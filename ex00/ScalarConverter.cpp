/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/28 12:42:41 by jcummins         ###   ########.fr       */
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

static int beyondIntBounds( const double input, e_input_type type) {
	if (input > INT_MAX) {
		std::cout << "int:\tabove range" << std::endl;
		return (1);
	}
	if (input < INT_MIN) {
		std::cout << "int:\tbelow range" << std::endl;
		return (-1);
	}
	if (type >= INPUT_PSEUDO && static_cast<int>(input) == INT_MIN) {
		std::cout << "int:\timpossible" << std::endl;
		return (2);
	}
	return (0);
}

static bool beyondCharBounds( const double input ) {
	if (floor(input) != input) {
		std::cout << "char:\timpossible" << std::endl;
		return (true);
	}
	if (input > 126) {
		std::cout << "char:\tabove range" << std::endl;
		return (true);
	}
	if (input < 32) {
		std::cout << "char:\tbelow range" << std::endl;
		return (true);
	}
	return (false);
}

static void printIntConversion( long int i ) {
	std::cout << "int:\t" << (i) << std::endl;
}

static void printCharConversion( unsigned char i ) {
	std::cout << "char:\t'" << (i) << "'" << std::endl;
}

static void printFloatConversion( float i) {
	std::cout << std::fixed << std::setprecision(4)
		<< "float:\t" << (i) << "f" << std::endl;
}

static void printDoubleConversion( double i ) {
	std::cout << std::fixed << std::setprecision(4)
		<< "double:\t" << (i) << std::endl;
}

//static void handlePseudoConversions( const std::string input ) {
	//std::cout << "char:\timpossible" << std::endl
		//<< "int:\timpossible" << std::endl
		//<< "float:\t" << input << "f" << std::endl
		//<< "double:\t" << input << std::endl;
//}

//static void handlePseudoFloatConversions( const std::string input ) {
	//std::cout << "char:\timpossible" << std::endl
		//<< "int:\timpossible" << std::endl
		//<< "float:\t" << input << std::endl
		//<< "double:\t" << input << std::endl;
//}

static int handleIntegerConversions( const long int input ) {
	if (!beyondCharBounds(input))
		printCharConversion(static_cast<unsigned char>(input));
	if (!beyondIntBounds(input, INPUT_INTEGER))
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
	if (!beyondIntBounds(input, INPUT_FLOAT))
		printIntConversion(static_cast<int>(input));
	printFloatConversion(input);
	printDoubleConversion(static_cast<double>(input));
	return 0;
}

static int handleDoubleConversions( const double input, e_input_type type ) {
	if (!beyondCharBounds(input))
		printCharConversion(static_cast<unsigned char>(input));
	if (!beyondIntBounds(input, type))
		printIntConversion(static_cast<int>(input));
	printFloatConversion(static_cast<float>(input));
	printDoubleConversion(static_cast<double>(input));
	return 0;
}

static e_input_type pseudoTypeCheck( const std::string &input ) {
	std::string pseudos[] = {"nanf", "+inff", "-inff"};
	int pseudos_size = sizeof(pseudos) / sizeof(pseudos[0]);

	if (std::find(pseudos, pseudos + pseudos_size, input) != pseudos + 3)
		return (INPUT_PSEUDO_F);
	if (std::find(pseudos, pseudos + pseudos_size, input + "f") != pseudos + 3)
		return (INPUT_PSEUDO);
	return (INPUT_INTEGER);
}

static e_input_type inputTypeCheck( const std::string input )
{
	int i = 0;
	e_input_type result = pseudoTypeCheck(input);

	if (result >= INPUT_PSEUDO)
		return (result);
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
			std::cout << "Type:\tpsuedo" << std::endl;
			handleDoubleConversions(static_cast<double>(atof(input.c_str())), INPUT_PSEUDO);
			return (0);
		case INPUT_PSEUDO_F:
			std::cout << "Type:\tpsuedo float" << std::endl;
			handleDoubleConversions(static_cast<float>(atof(input.c_str())), INPUT_PSEUDO);
			return (0);
		case INPUT_DOUBLE:
			std::cout << "Type:\tdouble" << std::endl;
			handleDoubleConversions(static_cast<double>(atof(input.c_str())), INPUT_DOUBLE);
			return (0);
		case INPUT_FLOAT:
			std::cout << "Type:\tfloat" << std::endl;
			handleFloatConversions(atof(input.c_str()));
			return (0);
		case INPUT_INTEGER:
			std::cout << "Type:\tinteger" << std::endl;
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
	std::cout << "Type:\tchar literal" << std::endl;
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
			return (handleCharConversions( input[0] ));
		case 3:
			if (!handleCharLiteral(input))
				return (0);
			// fall through
		default:
			return (multiCharHandle( input ));
	}
}
