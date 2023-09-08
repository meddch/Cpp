/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:54:38 by mechane           #+#    #+#             */
/*   Updated: 2023/09/08 20:09:22 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static bool isValidArg(char **arg)
{
	for (int i = 1 ; arg[i] ; i++ )
	{
		long overflowChecker(strtol(arg[i], NULL, 10));

		if (overflowChecker < 0 || INT_MAX < overflowChecker)
			return false ;

		for (int j = 0 ; arg[i][j] ; j++)
			if ( !isdigit(arg[i][j]) )
				return false ;
	}
	
	return true ;
}

static void printVec(std::vector<int>& vec)
{
	for (std::vector<int>::iterator it(vec.begin()) ; it != vec.end() ; it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}

static void printSortTime(std::clock_t t_vector, std::clock_t t_deque, int nbOfElements)
{
	double timevector = static_cast<double>(t_vector) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << nbOfElements << " elements with std::vector : " << std::fixed << timevector  << " us" << std::endl;

	double timedeque = static_cast<double>(t_deque) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << nbOfElements << " elements with std::deque  : " << std::fixed << timedeque << " us" << std::endl;
}

int main(int ac, char **av)
{
	if (ac < 2 || !isValidArg(av))
		return std::cout << "Error: bad input" << std::endl, EXIT_FAILURE;
	
	std::vector<int> vector;
	std::deque<int> deque;
	std::set<int> dupChecker;

	for (int i = 1 ; av[i] ; i++)
	{
		int nb = atoi(av[i]);
		if (dupChecker.find(nb) != dupChecker.end())
			return std::cout << "Error: Duplicate" << std::endl,  EXIT_FAILURE;
		dupChecker.insert(nb);
		vector.push_back(nb);
		deque.push_back(nb);
	}

	std::cout << "Before: ";
	printVec(vector);
	
	std::clock_t t_vector, t_deque;

	t_vector = insertMergeSort(vector, 0, vector.size() - 1);
	t_deque = insertMergeSort(deque, 0, deque.size() - 1);

	std::cout << "after: ";
	printVec(vector);

	printSortTime(t_vector, t_deque, ac - 1);

	return EXIT_SUCCESS ;
}