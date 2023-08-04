/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:12:18 by mechane           #+#    #+#             */
/*   Updated: 2023/08/04 13:16:43 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat constructor called for " <<  std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" <<  std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->type = other.type;
    return *this;
}

WrongCat::WrongCat(const WrongCat& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

void WrongCat::makeSound() const
{
    std::cout << "Meowww Meoawww" << std::endl;
}
