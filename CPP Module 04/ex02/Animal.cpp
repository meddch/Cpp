/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:57:15 by mechane           #+#    #+#             */
/*   Updated: 2023/08/05 07:26:32 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "Animal constructor called for " << type << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called for " << type << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->type = other.type;
    return *this;
}

Animal::Animal(const Animal& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}


std::string  Animal::getType() const
{
    return type;
}