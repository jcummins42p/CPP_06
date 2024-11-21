/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/21 18:10:41 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <iostream>
# include <string>
# include <iomanip>

class	ScalarConverter
{
	public:
		ScalarConverter	( void );
		ScalarConverter	( const ScalarConverter &other );
		ScalarConverter	&operator=( const ScalarConverter &other );
		~ScalarConverter	( void );

		static void convert( const std::string input );
	private:
} ;

#endif
