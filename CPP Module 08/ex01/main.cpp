/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:58:47 by mechane           #+#    #+#             */
/*   Updated: 2023/09/14 13:40:36 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try {
        Span span(10000);
        for (int i = 0; i < 10000; ++i)
            span.addNumber(i);
	///////////////////////////////////////
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
	{
		std::vector<int> vec;
		Span spn(10);

		vec.push_back(45);
		vec.push_back(1);
		vec.push_back(125);
		vec.push_back(4755);
		vec.push_back(0);
		vec.push_back(-1);

		try
		{
			spn.addNumbers(vec.begin(), vec.end());
			std::cout << "\n\n";
			std::cout << "Shortest span: " << spn.shortestSpan() << std::endl;
			std::cout << "Longest span: " << spn.longestSpan() << std::endl;

		}
		  catch (const std::runtime_error& e) {
        std::cout << "Exception: " << e.what() << std::endl;
		}

	}
    return 0;
}
