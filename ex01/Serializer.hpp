/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/22 20:52:51 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <iostream>

typedef struct s_data {
	std::string	name;
	int			grade;
	int			age;
}	t_data;

class	Serializer
{
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
	private:
		Serializer	( void );
		Serializer	( const Serializer &other );
		Serializer	&operator=( const Serializer &other );
		~Serializer	( void );
} ;

#endif

//	in C++ serialization is the process of converting an object into a sequence of bytes so that it can be stored in memory or transmitted across a network and deserialization is the reverse, where the byte stream is used to reconstruct the original object.
//	Serialization is the process of converting an object of a particular class into a stream of bytes in such a way that we can reconstruct the exact same object at later times. The process of reconstructing the serialized object is called deserialization. It is generally used to store it in the memory or transmit it over a network.
//	Generally, when we write data in binary form to files using fwrite() it will simply convert all the data in the given object to binary and store it in the memory as it is. Due to this, members that may reger to the dynamic memory will not be copied. Also, if the class contains virtual functions, it may not work correctly when reconstructed.
//	We can serialize an object either using the inbuilt fstream class with custom serialization function or we can use the external libraries such as boost serialization that provide robust methods.
