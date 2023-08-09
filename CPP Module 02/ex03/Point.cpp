/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:02:54 by mechane           #+#    #+#             */
/*   Updated: 2023/08/09 16:25:30 by mechane          ###   ########.fr       */
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

int	Point::substitute_point_in_line(Point const a, Point const b, Point const p)
{
	Fixed res;

	res = (a.getY() - p.getY()) * (a.getX() - b.getX()) - (a.getY() - b.getY()) * (a.getX() - p.getX());
	if (res != 0)
	return (res < 0 ? 1 : -1);
		return 0;
}