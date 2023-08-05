/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:33:34 by mechane           #+#    #+#             */
/*   Updated: 2023/08/05 07:21:09 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat() : Animal("Cat"), brain(new Brain)
{
    std::cout << "Cat constructor called" <<  std::endl;
}

Cat::~Cat()
{
    delete brain;
	std::cout << "Cat destructor called" <<  std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
	for (int i = 0; i < MAX_IDEA; i++)
		this->brain->set_Idea(i ,other.brain->get_Idea(i));
	this->type = other.type;
    return *this;
}

Cat::Cat(const Cat& other)
{
    std::cout << "Cat Copy constructor called" << std::endl;
	type = "Cat";
	brain = new Brain();
	*this = other;

}

void Cat::makeSound() const
{
    std::cout << "Meowww Meoawww" << std::endl;
}
