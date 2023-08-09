/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:16:16 by mechane           #+#    #+#             */
/*   Updated: 2023/08/09 09:40:04 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


bool bsp( Point const a, Point const b, Point const c, Point const p)
{
    int line;

    line = Point::substitute_point_in_line(a,b,p);
    return Point::substitute_point_in_line(a, b, c) == line &&
           Point::substitute_point_in_line(a, c, p) == line &&
           Point::substitute_point_in_line(c, b, p) == line;
}