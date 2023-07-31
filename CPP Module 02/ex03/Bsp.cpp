/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:16:16 by mechane           #+#    #+#             */
/*   Updated: 2023/07/31 09:02:19 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    int line1,line2,line3;
  
    line1 = Point::substitute_point_in_line(a,b,point);
    line2 = Point::substitute_point_in_line(a,c,point);
    line3 = Point::substitute_point_in_line(c,b,point);
	if ((line1 == line2) && (line2 == line3))
    	return true;
	return false;
}