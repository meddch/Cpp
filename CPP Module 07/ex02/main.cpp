/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:52:51 by mechane           #+#    #+#             */
/*   Updated: 2023/08/24 08:34:48 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

#define VAL 10


int main(int, char**)
{

    Array<int> nums(VAL);
    int* arr = new int[VAL];
    srand(time(NULL));



	 for (int i = 0; i < VAL; i++)
    {
        const int value = rand();
        nums[i] = value;
        arr[i] = value;
    }

    for (int i = 0; i < VAL; i++)
    {
        std::cout << "nums[" << i << "] = " << nums[i];
		std::cout << std::setw(20) << "arr[" << i << "] = " << arr[i]  << std::endl;
    }
	///////////////////////////////////////////
    try
    {
        nums[-10] = 0;
        nums[VAL - 1] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    delete [] arr;
    return 0;
}