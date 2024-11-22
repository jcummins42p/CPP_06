/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/22 19:43:19 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <iostream>

class	Serializer
{
	public:
		static serialize(Data *ptr);
		static deserialize(uintptr_t raw);
	private:
		Serializer	( void );
		Serializer	( const Serializer &other );
		Serializer	&operator=( const Serializer &other );
		~Serializer	( void );
} ;

#endif

