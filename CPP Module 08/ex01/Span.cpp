/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:37:11 by mechane           #+#    #+#             */
/*   Updated: 2023/08/24 14:18:04 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"

Span::Span()
{
	_size = 0;
	// std::cout << "\e[0;33mDefault Constructor called of Span\e[0m" << std::endl;
}

Span::Span(const Span &copy)
{
	*this = copy;
	// std::cout << "\e[0;33mCopy Constructor called of Span\e[0m" << std::endl;
}

Span::Span(size_t size)
{

	_size = size;
	// std::cout << "\e[0;33mFields Constructor called of Span\e[0m" << std::endl;
}


Span::~Span()
{
	// std::cout << "\e[0;31mDestructor called of Span\e[0m" << std::endl;
}


Span & Span::operator=(const Span &assign)
{
	if (this != &assign)
	{
		_size = assign._size;
		_vector = assign._vector;
	}
	return *this;
}


void Span::addNumber(int num)
{
	if (_vector.size() >= _size)
		throw std::runtime_error("Vector already full !");
	_vector.push_back(num);
}

int Span::shortestSpan()
{
	if (_vector.empty())
		throw std::runtime_error("Vector is empty !");
	if (_vector.size() == 1)
		throw std::runtime_error("Vector has only one number .");

	std::vector<int> sortedNumbers(_vector);
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int shortest = std::numeric_limits<int>::max();

    for (size_t i = 1; i < sortedNumbers.size(); ++i) {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < shortest)
            shortest = span;
    }
        return shortest;
}

int Span::longestSpan()
{
	if (_vector.empty())
		throw std::runtime_error("Vector is empty !");
	if (_vector.size() == 1)
		throw std::runtime_error("Vector has only one number .");
	std::vector<int> sortedNumbers(_vector);
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	return (sortedNumbers.back() - sortedNumbers.front());
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if ((unsigned int)(_vector.size() + end - begin) > _size)
	{
		throw std::runtime_error("Vector already full !");

	}
	while (begin != end)
		addNumber(*begin++);
}