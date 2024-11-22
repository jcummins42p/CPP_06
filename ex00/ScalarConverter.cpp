/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/22 13:21:48 by jcummins         ###   ########.fr       */
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

static bool	isNumber( const std::string input ) {
	int i = 0;
	if (!isSign(input[i]) && !isdigit(input[i]))
		return (false);
	while (++i < static_cast<int>(input.length())) {
		if (!isdigit(input[i]))
			return (false);
	}
	return (true);
}

static void printCharConversion( long int i ) {
	if ( i < 32 || i > 255)
		std::cout << "char:\tNon displayable" << std::endl;
	else
		std::cout << "char:\t" << static_cast<char> (i) << std::endl;
}

static void printIntConversion( long int i ) {
	std::cout << "int:\t" << static_cast<int> (i) << std::endl;
}

static void printFloatConversion( long int i) {
	std::cout << std::fixed << std::setprecision(1)
		<< "float:\t" << static_cast<float> (i) << "f" << std::endl;
}

static void printDoubleConversion( long int i ) {
	std::cout << std::fixed << std::setprecision(1)
		<< "double:\t" << static_cast<double> (i) << std::endl;
}

static void printConversions( long int i ) {
	printCharConversion(i);
	printIntConversion(i);
	printFloatConversion(i);
	printDoubleConversion(i);
}

static int	multiCharHandle( const std::string input ) {
	switch (isNumber(input)) {
		case 0:
			std::cout << "Error: input is not a c++ literal" << std::endl;
			return (1);
		case 1:
			printConversions(atol(input.c_str()));
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
			printConversions( input[0] );
			return (0);
		default:
			return (multiCharHandle( input ));
	}
}
