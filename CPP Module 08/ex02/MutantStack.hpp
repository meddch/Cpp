/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:53:11 by mechane           #+#    #+#             */
/*   Updated: 2023/09/14 12:42:48 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <stack>
#include <set>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator iterator;
		MutantStack(){};
		MutantStack(MutantStack const & src):std::stack<T>(src){};
		~MutantStack(){};
		MutantStack &operator=(MutantStack const &other){new (this) MutantStack(other);};
    	iterator begin() const {return std::begin(this->c);}
    	iterator end() const {return std::end(this->c);}
		iterator begin() {return std::begin(this->c);}
    	iterator end() {return std::end(this->c);}
};
