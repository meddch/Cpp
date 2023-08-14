/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:39:42 by mechane           #+#    #+#             */
/*   Updated: 2023/08/14 17:40:26 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#define SZ 8

int main()
{
	std::cout << "TEST 1:\n";
	{
		Animal *animals[SZ];

		for (int i = 0; i < SZ; i++) {
			if (i < SZ/2) {
				animals[i] = new Dog();
			}
			else {
				animals[i] = new Cat();
			}
		}

		std::cout << std::endl;
		for (int i = 0; i < SZ; i++) {
			animals[i]->makeSound();
		}

		std::cout << std::endl;
		for (int i = 0; i < SZ; i++) {
			delete animals[i];
		}
	}

	std::cout << "\nTEST 2:\n";
	{
		Dog d1;
		{
			Dog d2;
			std::cout << (d2.get_brain())->get_Idea(0) << std::endl;
			(d1.get_brain())->set_Idea(0, "wili wili");
			d2 = d1;
			std::cout <<(d2.get_brain())->get_Idea(0) << std::endl;
		}
	}

	std::cout << "\nTEST 3:\n";
	{
		Cat c1;
		{
			Cat c2;
				std::cout << (c2.get_brain())->get_Idea(0) << std::endl;
			(c1.get_brain())->set_Idea(0, "wili ana 9ta");
			c2 = c1;
			std::cout <<(c2.get_brain())->get_Idea(0) << std::endl;
		}
	}
	system("leaks Animals");
}