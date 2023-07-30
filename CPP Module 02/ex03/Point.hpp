/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:01:29 by mechane           #+#    #+#             */
/*   Updated: 2023/07/30 16:53:42 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	Fixed const	_x;
	Fixed const	_y;

public:

	Point();
	Point(float ax, float ay);
	Point(Point const &src);
	~Point();
	Point 			&operator=( Point const & rhs );
	static int		line_equation(Point const a, Point const b, Point const x);	
	Fixed			getX() const;
	Fixed			getY() const;
};
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif