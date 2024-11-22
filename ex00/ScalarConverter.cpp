/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/22 15:13:32 by jcummins         ###   ########.fr       */
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

//static bool	isNumber( const std::string input ) {
	//int i = 0;
	//if (!isSign(input[i]) && !isdigit(input[i]))
		//return (0);
	//while (++i < static_cast<int>(input.length())) {
		//if (!isdigit(input[i]))
			//return (0);
	//}
	//return (1);
//}

static e_input_type inputTypeCheck( const std::string input ) {
	e_input_type result = INPUT_INTEGER;
	int i = 0;

	if (!isSign(input[i]) && !isdigit(input[i]))
		return (INPUT_INVALID);
	while (++i < static_cast<int>(input.length())) {
		if (input[i] == '.' && result != INPUT_FLOAT)
			result = INPUT_FLOAT;
		else if (!isdigit(input[i]))
			return (INPUT_INVALID);
	}
	if (result == INPUT_FLOAT )
		std::cout << "Input check: float detected" << std::endl;
	else if (result == INPUT_INTEGER)
		std::cout << "Input check: int detected" << std::endl;
	return (result);
}

static void printCharConversion( long int i ) {
	if ( i < 32 || i > 255)
		std::cout << "char:\tNon displayable" << std::endl;
	else
		std::cout << "char:\t'" << static_cast<char> (i) << "'" << std::endl;
}

static void printIntConversion( long int i ) {
	std::cout << "int:\t" << static_cast<int> (i) << std::endl;
}

static void printFloatConversion( float i) {
	std::cout << std::fixed << std::setprecision(1)
		<< "float:\t" << static_cast<float> (i) << "f" << std::endl;
}

static void printDoubleConversion( double i ) {
	std::cout << std::fixed << std::setprecision(1)
		<< "double:\t" << static_cast<double> (i) << std::endl;
}

static void printStringConversions( std::string const input ) {
	float	infloat = atof(input.c_str());

	if (infloat == floor(infloat))
		printCharConversion(static_cast<char>(atof(input.c_str())));
	else
		std::cout << "char:\timpossible" << std::endl;
	printIntConversion(atol(input.c_str()));
	printFloatConversion(atof(input.c_str()));
	printDoubleConversion(static_cast<double>(atof(input.c_str())));
}

static void printCharConversions( const char input ) {
	printCharConversion(input);
	printIntConversion(static_cast<int>(input));
	printFloatConversion(static_cast<float>(input));
	printDoubleConversion(static_cast<double>(input));
}

static int	multiCharHandle( const std::string input ) {
	switch (inputTypeCheck(input)) {
		case INPUT_INVALID:
			break;
		case INPUT_INTEGER:
			printStringConversions(input);
			return (0);
		case INPUT_FLOAT:
			printStringConversions(input);
			return (0);
	}
	std::cout << "Error: input is not a c++ literal" << std::endl;
	return (1);
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
