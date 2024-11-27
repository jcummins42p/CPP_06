/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeTester.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/27 14:23:24 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeTester.hpp"

TypeTester::TypeTester( void ) {}

TypeTester::~TypeTester( void ) {}

//	dynamic cast returns a NULL pointer if the conversion isn't possible
void	TypeTester::identify( Base *p ) {
	//std::cout << "Testing identity via pointer" << std::endl;
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

//	creating a new reference is like creating an alias for that object
//	dynamic cast throws an exception when this is done on references
void	TypeTester::identify( Base &p ) {
	//std::cout << "Testing identity via reference" << std::endl;
	try {
		A &new_a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void) new_a;
		return ;
	}
   	catch ( const std::exception & ) {}
	try {
		B &new_b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void) new_b;
		return ;
	}
	catch ( const std::exception & ) {}
	try {
		C &new_c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void) new_c;
		return ;
	}
	catch ( const std::exception & ) {}
}

Base *TypeTester::generate( void ) {
	srand(time(NULL));
	int	choice = (rand() % 3);
	//char classes[3] = {'A', 'B', 'C'};

	//std::cout << "Generator produced class " << classes[choice] << std::endl;
	switch (choice) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return (NULL);
}
