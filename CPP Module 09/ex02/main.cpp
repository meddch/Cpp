/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:54:38 by mechane           #+#    #+#             */
/*   Updated: 2023/09/05 18:58:38 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static bool isValidArg( char **arg )
{
	for ( size_t i(1) ; arg[i] ; i++ )
	{
		long overflowChecker(strtol(arg[i], NULL, 10));

		if ( overflowChecker < 0 || INT_MAX < overflowChecker )
			return false ;

		for ( size_t j(0) ; arg[i][j] != '\0' ; j++ )
		{
			if ( !isdigit(arg[i][j]) )
				return false ;
		}
	}
	
	return true ;
}

static void printValue(std::vector<int>& c)
{
	for ( std::vector<int>::iterator it(c.begin()) ; it != c.end() ; it++ )
	{
		std::cout << " " << *it;
	}
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
	if ( ac < 2 || isValidArg(av) == false )
	{
		std::cout << "Error: bad arguments" << std::endl;
		return EXIT_FAILURE ;
	}
	
	std::vector<int> c_vector;
	std::deque<int> c_deque;
	std::set<int> c_duplicateChecker;

	for (size_t i(1) ; av[i] ; i++ )
	{
		int nb = atoi(av[i]);
		if ( c_duplicateChecker.find(nb) != c_duplicateChecker.end() )
		{
			std::cout << "Error: the number must not be duplicate" << std::endl;
			return EXIT_FAILURE ;
		}
		c_duplicateChecker.insert(nb);
		c_vector.push_back(nb);
		c_deque.push_back(nb);
	}

	std::cout << "Before: ";
	printValue(c_vector);
	
	std::clock_t t_vector, t_deque;

	t_vector = insertMergeSort(c_vector, 0, c_vector.size() - 1);
	t_deque = insertMergeSort(c_deque, 0, c_deque.size() - 1);

	std::cout << "after: ";
	printValue(c_vector);

	printSortTime(t_vector, t_deque, ac - 1);

	return EXIT_SUCCESS ;
}