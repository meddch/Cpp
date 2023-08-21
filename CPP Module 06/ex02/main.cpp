/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:44:11 by mechane           #+#    #+#             */
/*   Updated: 2023/08/21 16:39:17 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include"A.hpp"
#include"B.hpp"
#include"C.hpp"
#include <thread>


int	main(void)
{
	Base * r;
	Base * r1;
	Base * r2;
	Base * c = new C();
	Base * a = new A();
	Base * b = new B();

	r = generate();
	std::chrono::milliseconds duration(500);
	std::this_thread::sleep_for(duration);
	r1 = generate();
	std::chrono::milliseconds duration1(500);
	std::this_thread::sleep_for(duration1);
	r2 = generate();

	std::cout << "POINTER" << std::endl;
	identify(a);
	identify(b);
	identify(c);
	identify(r);
	identify(r1);
	identify(r2);

	std::cout << "REFERENCE" << std::endl;
	identify(*a);
	identify(*b);
	identify(*c);
	identify(*r);
	identify(*r1);
	identify(*r2);

	delete a;
	delete b;
	delete c;
	delete r;
	delete r1;
	delete r2;
	return (0);
}