/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:33:36 by mechane           #+#    #+#             */
/*   Updated: 2023/08/05 08:25:11 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	Brain*	brain;
public :
    Cat();
    ~Cat();
    Cat& operator=(const Cat& other);
    Cat(const Cat& other);
    void makeSound() const;
	Brain* get_brain(void);
};


#endif