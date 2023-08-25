/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:53:14 by mechane           #+#    #+#             */
/*   Updated: 2023/08/25 17:19:04 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// #define push push_back


int main()
{
	MutantStack<int> mstack;


	mstack.push(1000000);
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(737);
	mstack.push(895);
	mstack.push(737);
	mstack.pop();
	mstack.push(-1);
	mstack.push(737);
	mstack.push(156);
	mstack.push(737);
	mstack.push(87);
	mstack.pop();
	mstack.push(715737);
	mstack.push(74657);
	mstack.push(7307);
	mstack.push(102);
	mstack.pop();
	mstack.push(257);
	mstack.push(10);
	mstack.push(0);


	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}


	std::cout << "\n\n\n";
	///////////////////////////////////////////////////
    std::list<int> l;


	l.push_back(1000000);
	l.push_back(5);
    l.push_back(17);
    std::cout << l.back() << std::endl;
    l.pop_back();
    std::cout << l.size() << std::endl;
	l.push_back(3);
	l.push_back(737);
	l.push_back(895);
	l.push_back(-1);
	l.push_back(737);
    l.pop_back();
	l.push_back(737);
	l.push_back(156);
	l.push_back(737);
	l.push_back(87);
    l.pop_back();
	l.push_back(715737);
	l.push_back(74657);
	l.push_back(7307);
	l.push_back(102);
    l.pop_back();
	l.push_back(257);
	l.push_back(10);
    l.push_back(0);

    std::list<int>::iterator lit = l.begin();
    std::list<int>::iterator lite = l.end();
    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }	return 0;
}


