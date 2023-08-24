/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:33:24 by mechane           #+#    #+#             */
/*   Updated: 2023/08/24 08:33:01 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <class T>
Array<T>::Array()
{
	_size = 0;
	arr = NULL;
}

template <class T>
Array<T>::Array(size_t const &n)
{
	try
	{
		this->_size = n;
		this->arr = new T[this->_size];
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << e.what() << std::endl;
		exit(1);
	}
}

template <class T>
Array<T>::Array(const Array &src)
{
	this->_size = src._size;
    this->arr = new T[this->_size];
    for (size_t i = 0; i < this->_size; i++)
    {
        this->arr[i] = src.arr[i];
    }
}


template <class T>
Array<T>::~Array()
{
	if (arr)
		delete arr;
}

template <class T>
Array<T> &Array<T>::operator=( Array const &other)
{
	if ( this == &other)
		return *this;
	this->_size = other._size;
	if (arr)
		delete arr;
	this->arr = new T[this->_size];
	for (size_t i = 0; i < this->_size; i++)
	{
		this->arr[i] = other.arr[i];
	}

	return *this;
}

template <class T>
T &Array<T>::operator[](size_t const &i)
{
    if (i >= _size || i < 0)
        throw std::out_of_range("std::invalid index");
    return this->arr[i];
}