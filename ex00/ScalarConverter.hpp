/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/26 19:20:49 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <iostream>
# include <algorithm>
# include <iterator>
# include <string>
# include <iomanip>
# include <stdlib.h>
# include <math.h>
# include <limits.h>

typedef enum s_input_type {
	INPUT_INVALID = 0,
	INPUT_INTEGER,
	INPUT_FLOAT,
	INPUT_DOUBLE,
	INPUT_PSEUDO
}			e_input_type;

class	ScalarConverter
{
	public:
		static int convert( const std::string input );
	private:
		ScalarConverter	( void );
		ScalarConverter	( const ScalarConverter &other );
		ScalarConverter	&operator=( const ScalarConverter &other );
		~ScalarConverter	( void );
} ;

#endif
