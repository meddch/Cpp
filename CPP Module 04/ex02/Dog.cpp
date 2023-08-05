/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:38:36 by mechane           #+#    #+#             */
/*   Updated: 2023/08/05 08:26:39 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog() : Animal("Dog"), brain(new Brain)
{
    std::cout << "Dog constructor called" <<  std::endl;
}

Dog::~Dog()
{
    delete brain;
	std::cout << "Dog destructor called " <<  std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
	for (int i = 0; i < MAX_IDEA; i++)
		this->brain->set_Idea(i ,other.brain->get_Idea(i));
    this->type = other.type;
    return *this;
}


Dog::Dog(const Dog& other)
{
    std::cout << "Dog Copy constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
	for (int i = 0; i < MAX_IDEA; i++)
		this->brain->set_Idea(i ,other.brain->get_Idea(i));
	*this = other;
}

void Dog::makeSound() const
{
    std::cout << "Bark Bark" << std::endl;
}

Brain* Dog::get_brain(void)
{
	return brain;
}