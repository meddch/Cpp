/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:02:54 by mechane           #+#    #+#             */
/*   Updated: 2023/07/30 17:22:13 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point():_x(0), _y(0){}

Point::Point(const Point &other) :_x(other.getX()), _y(other.getY()){}

Point::Point(float n_x, float n_y) :_x(n_x), _y(n_y){}

Point::~Point(){}


Fixed	Point::getX() const
{
	return	_x;
}

Fixed	Point::getY() const
{
	return	_y;
}

Point& Point::operator=(Point const &other)
{
	new(this) Point(other);
	return *this;
}

int	Point::line_equation(Point const a, Point const b, Point const x)
{
	Fixed res;
	
	res = (a.getY() - x.getY()) * (a.getX() - b.getX()) - (a.getY() - b.getY()) * (a.getX() - x.getX());
	if (res == 0)
		return 0;
	return (res < 0 ? -1 : 1);
}