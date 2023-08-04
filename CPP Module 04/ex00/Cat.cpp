/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:33:34 by mechane           #+#    #+#             */
/*   Updated: 2023/08/04 11:59:55 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor called for " <<  std::endl;    
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" <<  std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->type = other.type;
    return *this;
}

Cat::Cat(const Cat& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

void Cat::makeSound() const
{
    std::cout << "Meowww Meoawww" << std::endl;
}
