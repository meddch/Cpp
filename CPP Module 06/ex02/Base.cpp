/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:45:05 by mechane           #+#    #+#             */
/*   Updated: 2023/08/21 17:45:39 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include"A.hpp"
#include"B.hpp"
#include"C.hpp"

Base::~Base()
{
	std::cout << "Destructor Called for Base\n";
}

Base *generate(void)
{
	std::srand(std::time(0));

	switch (std::rand() % 3)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

void identify(Base* p)
{
	Base *tmp;
	if ((tmp = dynamic_cast<A*>(p)) != NULL)
		std::cout << "This Base identify as A type class ." << std::endl;
	else if ((tmp = dynamic_cast<B*>(p)) != NULL)
		std::cout << "This Base identify as B type class ." << std::endl;
	else if ((tmp = dynamic_cast<C*>(p)) != NULL)
		std::cout << "This Base identify as C type class ." << std::endl;
	else
		std::cout << "UNKNOWN type" << std::endl;
}

void identify(Base& p)
{
	static int i = 0;
	Base tmp;

	try
	{
		switch (i)
		{
			case 0:
				tmp = dynamic_cast<A&>(p);
				break;
			case 1:
				tmp = dynamic_cast<B&>(p);
				break;
			case 2:
				tmp = dynamic_cast<C&>(p);
				break;
			default :
				std::cout << "UNKNOWN type" << std::endl;
				return ;
		}
	}
	catch (std::exception &e)
	{
		i++;
		identify(p);
	}
	switch (i)
	{
	case 0:
		std::cout << "This Base identify as A type class ." << std::endl;
		break;
	case 1:
		std::cout << "This Base identify as B type class ." << std::endl;
		break;
	case 2:
		std::cout << "This Base identify as C type class ." << std::endl;
		break;
	}
}