/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/22 19:30:08 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {}

ScalarConverter::ScalarConverter( const ScalarConverter& other ) {
	(void)other;
}

ScalarConverter &ScalarConverter::operator=( const ScalarConverter& other ) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter( void ) {}

static bool isSign( const char c ) {
	if (c == '-')
		return (true);
	if (c == '+')
		return (true);
	return (false);
}

static void printCharConversion( long int i ) {
	if ( i < 32 || i > 127)
		std::cout << "char:\tNon displayable" << std::endl;
	else
		std::cout << "char:\t'" << static_cast<unsigned char> (i) << "'" << std::endl;
}

static void printIntConversion( long int i ) {
	std::cout << "int:\t";
	if (i > INT_MAX)
		std::cout << "too large to display";
	else if (i < INT_MIN)
		std::cout << "too low to display";
	else
		std::cout << static_cast<int> (i);
	std::cout << std::endl;
}

static void printFloatConversion( float i) {
	std::cout << std::fixed << std::setprecision(4)
		<< "float:\t" << static_cast<float> (i) << "f" << std::endl;
}

static void printDoubleConversion( double i ) {
	std::cout << std::fixed << std::setprecision(4)
		<< "double:\t" << static_cast<double> (i) << std::endl;
}

static void printStringConversions( std::string const input ) {
	float	infloat = atof(input.c_str());

	if (infloat == floor(infloat))
		printCharConversion(atol(input.c_str()));
	else
		std::cout << "char:\timpossible" << std::endl;
	printIntConversion(atol(input.c_str()));
	printFloatConversion(atof(input.c_str()));
	printDoubleConversion(static_cast<double>(atof(input.c_str())));
}

static void printCharConversions( const unsigned char input ) {
	printCharConversion(input);
	printIntConversion(static_cast<int>(input));
	printFloatConversion(static_cast<float>(input));
	printDoubleConversion(static_cast<double>(input));
}

static void printPseudoConversions( const std::string input ) {
	std::cout << "char:\timpossible" << std::endl
		<< "int:\timpossible" << std::endl
		<< "float:\t" << input << "f" << std::endl
		<< "double:\t" << input << std::endl;
}

static e_input_type inputTypeCheck( const std::string input ) {
	e_input_type result = INPUT_INTEGER;
	std::string pseudos[] = {"nan", "+inf", "-inf"};
	int pseudos_size = sizeof(pseudos) / sizeof(pseudos[0]);
	int i = 0;

	if (std::find(pseudos, pseudos + pseudos_size, input) != pseudos + 3) {
		std::cout << input << " is in literals list" << std::endl;
		return (INPUT_PSEUDO);
	}
	if (!isSign(input[i]) && !isdigit(input[i]))
		return (INPUT_INVALID);
	while (++i < static_cast<int>(input.length())) {
		if (input[i] == '.' && result != INPUT_FLOAT)
			result = INPUT_FLOAT;
		else if (input[i] == 'f' && result == INPUT_FLOAT)
			return (INPUT_FLOAT);
		else if (!isdigit(input[i]))
			return (INPUT_INVALID);
	}
	return (result);
}

static int	multiCharHandle( const std::string input ) {
	switch (inputTypeCheck(input)) {
		case INPUT_INVALID:
			std::cout << "Error: input is not a c++ literal" << std::endl;
			return (1);
		case INPUT_PSEUDO:
			printPseudoConversions(input);
			return (0);
		default:
			printStringConversions(input);
			return (0);
	}
}

//	std::setprecision <iomanip> is an I/O manipulator which modifies default formatting
int ScalarConverter::convert( const std::string input ) {
	switch (input.length()) {
		case 0:
			std::cout << "Error: empty input" << std::endl;
			return (1);
		case 1:
			if (isdigit(input[0]))
				return (multiCharHandle( input ));
			printCharConversions( input[0] );
			return (0);
		default:
			return (multiCharHandle( input ));
	}
}
