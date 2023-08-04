/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:33:36 by mechane           #+#    #+#             */
/*   Updated: 2023/08/04 13:44:25 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	Brain*	_brain;
public :
    Cat();
    ~Cat();
    Cat& operator=(const Cat& other);
    Cat(const Cat& other);
    void makeSound() const;
};


#endif