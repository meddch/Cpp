/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:58:47 by mechane           #+#    #+#             */
/*   Updated: 2023/08/25 08:25:01 by mechane          ###   ########.fr       */
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

    return 0;
}
