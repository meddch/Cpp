/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:38:36 by mechane           #+#    #+#             */
/*   Updated: 2023/08/04 12:00:01 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor called" <<  std::endl;    
}

Dog::~Dog()
{
    std::cout << "Dog destructor called for " <<  std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->type = other.type;
    return *this;
}

Dog::Dog(const Dog& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

void Dog::makeSound() const
{
    std::cout << "Bark Bark" << std::endl;
}
