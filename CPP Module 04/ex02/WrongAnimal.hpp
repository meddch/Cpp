/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:57:17 by mechane           #+#    #+#             */
/*   Updated: 2023/08/04 13:18:58 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected :
    std::string type;
public :
    WrongAnimal();
    WrongAnimal(std::string type);
    ~WrongAnimal();
    WrongAnimal& operator=(const WrongAnimal& other);
    WrongAnimal(const WrongAnimal& other);
    void makeSound() const;
    std::string getType(void) const;
};


#endif