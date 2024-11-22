/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/22 19:47:56 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void ) {}

Serializer::Serializer( const Serializer& other )
{
	//	copy constructor
}

Serializer &Serializer::operator=( const Serializer& other ) {
	if (this != &other)
	{
		//	copy member variables
	}
	return *this;
}

Serializer::~Serializer( void ) {}

uintptr_t serialize(Data *ptr)
{
	uintptr_t	output;

	return (output);
}

Data *deserialize(uintptr_t raw)
{
	Data *output;

	return (output);
}
