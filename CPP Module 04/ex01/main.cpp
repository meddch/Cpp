/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:39:42 by mechane           #+#    #+#             */
/*   Updated: 2023/08/05 07:15:32 by mechane          ###   ########.fr       */
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
			d2 = d1;
		}
	}

	std::cout << "\nTEST 3:\n";
	{
		Cat c1;
		{
			Cat c2;
			c2 = c1;
		}
	}
}