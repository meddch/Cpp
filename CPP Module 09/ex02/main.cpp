/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:54:38 by mechane           #+#    #+#             */
/*   Updated: 2023/09/10 22:08:38 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static bool isValidArg(char **arg)
{
	for (int i = 1 ; arg[i] ; i++ )
	{
		long long nbr(strtol(arg[i], NULL, 10));

		if (nbr < 0 || INT_MAX < nbr)
			return false ;

		for (int j = 0 ; arg[i][j] ; j++)
			if ( !isdigit(arg[i][j]) )
				return false ;
	}
	
	return true ;
}

static void printVec(std::vector<std::size_t>& vec)
{
	for (std::vector<std::size_t>::iterator it(vec.begin()) ; it != vec.end() ; it++)
		std::cout << std::setw(11) << *it;
	std::cout << std::endl;
}

static void printTime(std::clock_t t_vector, std::clock_t t_deque, int nbOfElements)
{
	double timevector = static_cast<double>(t_vector) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << nbOfElements << " elements with std::vector : " << std::fixed << timevector  << " us" << std::endl;

	double timedeque = static_cast<double>(t_deque) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << nbOfElements << " elements with std::deque  : " << std::fixed << timedeque << " us" << std::endl;
}

static bool hasDuplicate(std::vector<std::size_t>& vec)
{
	std::set<std::size_t> set(vec.begin(), vec.end());
	return (set.size() != vec.size());
}

int main(int ac, char **av)
{
	if (ac < 2 || !isValidArg(av))
		return std::cout << "Error: bad input" << std::endl, EXIT_FAILURE;
	
	std::vector<std::size_t> vector;
	std::deque<std::size_t> deque;

	for (int i = 1 ; av[i] ; i++)
	{
		int nb = atoi(av[i]);
		vector.push_back(nb);
		deque.push_back(nb);
	}
	
	if(hasDuplicate(vector))
		return std::cout << "Error: Duplicate" << std::endl,  EXIT_FAILURE;
	
	std::cout << "Before :";
	printVec(vector);
	
	std::clock_t t_vector, t_deque;

	t_vector = mergeInsertionSortVector(vector);
	t_deque = insertionSortDeque(deque, deque.size());

	std::cout << "After  :";
	printVec(vector);

	printTime(t_vector, t_deque, ac - 1);



	return EXIT_SUCCESS ;
}