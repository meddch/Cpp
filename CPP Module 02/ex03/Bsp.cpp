/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:16:16 by mechane           #+#    #+#             */
/*   Updated: 2023/08/09 16:46:28 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    int line;

    line = Point::substitute_point_in_line(a,b,point);
    if (Point::substitute_point_in_line(a,b,c) != line && line)
        return false;
    line = Point::substitute_point_in_line(a,c,point);
    if (Point::substitute_point_in_line(a,c,b) != line && line)
        return false;
    line = Point::substitute_point_in_line(c,b,point);
    if (Point::substitute_point_in_line(c,b,a) != line && line )
        return false;
    return true;
}