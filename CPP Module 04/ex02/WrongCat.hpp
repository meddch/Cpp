/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:11:09 by mechane           #+#    #+#             */
/*   Updated: 2023/08/04 13:15:55 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public :
    WrongCat();
    ~WrongCat();
    WrongCat& operator=(const WrongCat& other);
    WrongCat(const WrongCat& other);
    void makeSound() const;
};


#endif