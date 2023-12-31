/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:37:59 by mechane           #+#    #+#             */
/*   Updated: 2023/08/04 11:57:22 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public :
    Dog();
    ~Dog();
    Dog& operator=(const Dog& other);
    Dog(const Dog& other);
    void makeSound() const;
};


#endif