/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:10:25 by mechane           #+#    #+#             */
/*   Updated: 2023/08/05 07:16:11 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#define MAX_IDEA 100

class   Brain
{
	std::string _ideas[MAX_IDEA];
public :
	Brain();
	~Brain();
	Brain& operator=(const Brain& other);
	Brain(const Brain& other);
	std::string get_Idea(int index) const;
	void set_Idea(int index,const  std::string& idea);
};

#endif