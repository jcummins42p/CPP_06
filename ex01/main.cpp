/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:54:24 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/27 12:56:14 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	printData(Data *ptr)
{
	if (!ptr) {
		std::cout << std::endl << "Error:\tnull pointer" << std::endl;
		return (1);
	}
	std::cout << std::endl << "Pointer:" << ptr << std::endl
		<< "Name:\t" << ptr->name << std::endl
		<< "Decimal:" << ptr->decimal << std::endl
		<< "Grade\t" << ptr->grade << std::endl;
	return (0);
}

int initData(Data *ptr)
{
	if (!ptr) {
		std::cout << std::endl << "Error:\tnull pointer" << std::endl;
		return (1);
	}
	std::string str("Steven\0");
	str.copy(ptr->name, 6);
	ptr->decimal = 42.42;
	ptr->grade = 42;
	return (0);
}

int main(void)
{
	Data *ptr = new Data;
	Data *ptr2 = new Data;
	uintptr_t raw;

	initData(ptr);
	raw = Serializer::serialize(ptr);
	ptr2 = Serializer::deserialize(raw);

	printData(ptr);
	printData(ptr2);
	ptr = NULL;
	printData(ptr);
	ptr = Serializer::deserialize(raw);
	printData(ptr);

	return (0);
}
