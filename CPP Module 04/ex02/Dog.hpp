/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:37:59 by mechane           #+#    #+#             */
/*   Updated: 2023/08/05 08:26:19 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	Brain*	brain;
public :
    Dog();
    ~Dog();
    Dog& operator=(const Dog& other);
    Dog(const Dog& other);
    void makeSound() const;
	Brain* get_brain(void);
};


#endif