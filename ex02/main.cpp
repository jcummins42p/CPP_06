/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:23:23 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/27 13:42:08 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Base.hpp"
#include "TypeTester.hpp"

int main( void )
{
	Base *example = TypeTester::generate();

	TypeTester::identify(example);
	TypeTester::identify(*example);

	delete example;
	return (0);
}
