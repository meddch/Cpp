/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:37:06 by mechane           #+#    #+#             */
/*   Updated: 2023/08/24 14:03:48 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
#include <iterator>
# include <string>
#include <vector>

class Span
{
		size_t _size;
		std::vector<int> _vector;
	public:
		Span();
		Span(const Span &copy);
		Span(size_t size);
		~Span();

		Span & operator=(const Span &assign);

		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);



};

#endif