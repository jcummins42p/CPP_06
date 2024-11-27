/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Generator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/27 13:36:10 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPETESTER_H
# define TYPETESTER_H

# include <iostream>
# include <cstdlib>


# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

class	TypeTester
{
	public:
		static Base	*generate( void );
		static void identify(Base *p);
		static void identify(Base &p);
	private:
		TypeTester	( void );
		TypeTester	( const TypeTester &other );
		TypeTester	&operator=( const TypeTester &other );
		~TypeTester	( void );
} ;

#endif

