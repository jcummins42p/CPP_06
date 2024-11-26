/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/26 20:03:00 by jcummins         ###   ########.fr       */
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

static bool beyondIntBounds( const double input ) {
	if (input > INT_MAX) {
		std::cout << "int:\ttoo large to display" << std::endl;
		return (true);
	}
	if (input < INT_MIN) {
		std::cout << "int:\ttoo low to display" << std::endl;
		return (true);
	}
	return (false);
}

static bool beyondCharBounds( const double input ) {
	if (floor(input) != input) {
		std::cout << "char:\timpossible" << std::endl;
		return (true);
	}
	if (input > 128) {
		std::cout << "char:\ttoo large to display" << std::endl;
		return (true);
	}
	if (input < 33) {
		std::cout << "char:\ttoo low to display" << std::endl;
		return (true);
	}
	return (false);
}

static void printCharConversion( long int i ) {
	if ( i < 32 || i > 127)
		std::cout << "char:\tNon displayable" << std::endl;
	else
		std::cout << "char:\t'" << static_cast<unsigned char> (i) << "'" << std::endl;
}

static void printIntConversion( long int i ) {
	if (!beyondIntBounds(static_cast<double>(i)))
		std::cout << "int:\t" << static_cast<int> (i) << std::endl;
}

static void printFloatConversion( float i) {
	std::cout << std::fixed << std::setprecision(4)
		<< "float:\t" << static_cast<float> (i) << "f" << std::endl;
}

static void printDoubleConversion( double i ) {
	std::cout << std::fixed << std::setprecision(4)
		<< "double:\t" << static_cast<double> (i) << std::endl;
}

static int handleIntegerConversions( const int input ) {
	if (!beyondCharBounds(input))
		printCharConversion(static_cast<unsigned char>(input));
	printIntConversion(input);
	printFloatConversion(static_cast<float>(input));
	printDoubleConversion(static_cast<double>(input));
	return 0;
}

static int handleCharConversions( const unsigned char input ) {
	if (!beyondCharBounds(input))
		printCharConversion(input);
	printIntConversion(static_cast<int>(input));
	printFloatConversion(static_cast<float>(input));
	printDoubleConversion(static_cast<double>(input));
	return 0;
}

static int handleFloatConversions( const float input ) {
	if (!beyondCharBounds(input))
		printCharConversion(static_cast<unsigned char>(input));
	if (!beyondIntBounds(input))
		printIntConversion(static_cast<int>(input));
	printFloatConversion(input);
	printDoubleConversion(static_cast<double>(input));
	return 0;
}

static int handleDoubleConversions( const double input ) {
	if (!beyondCharBounds(input))
		printCharConversion(static_cast<unsigned char>(input));
	printIntConversion(static_cast<int>(input));
	printFloatConversion(static_cast<float>(input));
	printDoubleConversion(static_cast<double>(input));
	return 0;
}

static void handlePseudoConversions( const std::string input ) {
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
		if (input[i] == '.' && result != INPUT_DOUBLE)
			result = INPUT_DOUBLE;
		else if (input[i] == 'f' && result == INPUT_DOUBLE)
			return (i + 1 == static_cast<int>(input.length()) ? INPUT_FLOAT : INPUT_INVALID);
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
			std::cout << "Type psuedo" << std::endl;
			handlePseudoConversions(input);
			return (0);
		case INPUT_DOUBLE:
			std::cout << "Type double" << std::endl;
			handleDoubleConversions(static_cast<double>(atof(input.c_str())));
			return (0);
		case INPUT_FLOAT:
			std::cout << "Type float" << std::endl;
			handleFloatConversions(atof(input.c_str()));
			return (0);
		case INPUT_INTEGER:
			std::cout << "Type integer" << std::endl;
			handleIntegerConversions(atol(input.c_str()));
			return (0);
		default:
			std::cout << "Could not detect type" << std::endl;
			return (1);
	}
}

static bool isCharLiteral( const std::string input ) {
	return (input[0] == '\'' && input[2] == '\'' ? true : false);
}

static int handleCharLiteral( const std::string input ) {
	if (!isCharLiteral(input))
		return 1;
	std::cout << "Type unsigned char literal" << std::endl;
	return (handleCharConversions(input[1]));
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
			handleCharConversions( input[0] );
			return (0);
		case 3:
			if (!handleCharLiteral(input))
				return (0);
		default:
			return (multiCharHandle( input ));
	}
}
