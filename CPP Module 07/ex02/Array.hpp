/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:46:36 by mechane           #+#    #+#             */
/*   Updated: 2023/08/24 08:19:20 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>

template <class T>
class Array
{
		T		*arr;
		size_t	_size;
	public:

		Array();
		Array(size_t const &n);
		Array( Array const & src );
		~Array();
		Array 		&operator=(Array const &other);
		T			&operator[](size_t const &i);
};