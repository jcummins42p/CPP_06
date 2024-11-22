/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/22 15:00:26 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <iostream>
# include <string>
# include <iomanip>
# include <stdlib.h>
# include <math.h>

typedef enum s_input_type {
	INPUT_INVALID = 0,
	INPUT_INTEGER,
	INPUT_FLOAT
}			e_input_type;

class	ScalarConverter
{
	public:
		ScalarConverter	( void );
		ScalarConverter	( const ScalarConverter &other );
		ScalarConverter	&operator=( const ScalarConverter &other );
		~ScalarConverter	( void );

		static int convert( const std::string input );
	private:
} ;

#endif
