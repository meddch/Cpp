/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:05:25 by mechane           #+#    #+#             */
/*   Updated: 2023/07/31 09:07:39 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    Point P[4];
    float x,y;
	int i;
	
    for (i = 0; i < 3; i++)
    {
		std::cout << "Please enter the vertices (x , y) of the triangle :" << std::endl;
	    std::cin >> x >> y;
        P[i] = Point(x, y);
    }
	std::cout << "Please enter the point to check :" << std::endl;
	std::cin >> x >> y;
    P[i] = Point(x, y);
    std::cout << (bsp(P[0],P[1],P[2],P[3]) ? "inside the triangle" : "outside the triangle") << std::endl;
}