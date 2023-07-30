/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:05:25 by mechane           #+#    #+#             */
/*   Updated: 2023/07/30 18:05:07 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    Point P[4];
	
    for (int i = 0; i < 4; i++)
    {
        float x,y;
        std::cin >> x >> y;
        P[i] = Point(x, y);
    }
    std::cout << (bsp(P[0],P[1],P[2],P[3]) ? "inside the triangle" : "outside the triangle") << std::endl;
}