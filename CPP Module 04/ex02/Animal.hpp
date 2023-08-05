/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:57:17 by mechane           #+#    #+#             */
/*   Updated: 2023/08/05 07:28:37 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected :
    std::string type;
public :
    Animal();
    Animal(std::string type);
    virtual ~Animal();
    Animal& operator=(const Animal& other);
    Animal(const Animal& other);
    virtual void makeSound() const = 0 ;
    std::string getType(void) const;
};


#endif