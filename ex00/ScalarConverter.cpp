/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/21 18:42:28 by jcummins         ###   ########.fr       */
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

static void	multiCharHandle( const std::string input ) {
	std::cout << "Treating multi-char input: " << input << std::endl;
}

static void singleCharHandle( const std::string input ) {
	std::cout << "Treating single char input: "
		<< std::endl << std::fixed << std::setprecision(1)
		<< "char:\t" << static_cast<char> (input[0]) << std::endl
		<< "int:\t" << static_cast<int> (input[0]) << std::endl
		<< "float:\t" << static_cast<float> (input[0]) << "f" << std::endl
		<< "double:\t" << static_cast<double> (input[0]) << std::endl;
}

//	std::setprecision <iomanip> is an I/O manipulator which modifies default formatting
void ScalarConverter::convert( const std::string input ) {
	switch (input.length()) {
		case 0:
			std::cout << "Error: empty input" << std::endl;
			break;
		case 1:
			singleCharHandle( input );
			break;
		default:
			multiCharHandle( input );
	}
}
