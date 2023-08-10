/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:05:25 by mechane           #+#    #+#             */
/*   Updated: 2023/08/09 12:06:02 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed b(a);
	Fixed c;
	Fixed t;


	c = b;
	t.setRawBits(9);
	Fixed h(t);
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << t.getRawBits() << std::endl;
	std::cout << h.getRawBits() << std::endl;

	return 0;
}
