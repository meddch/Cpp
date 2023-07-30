/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:16:16 by mechane           #+#    #+#             */
/*   Updated: 2023/07/30 18:03:15 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    int line1,line,line3;
  
    line1 = Point::line_equa_sig(a,b,point);
    line2 = Point::line_equa_sig(a,c,point);
    line3 = Point::line_equa_sig(c,b,point);
	if ((line1 == line) && (line2 == line3))
    	return true;
	return false;
}