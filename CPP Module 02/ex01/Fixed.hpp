/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:07 by mechane           #+#    #+#             */
/*   Updated: 2023/08/09 10:27:58 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	int	_value;
	static const int frac_bits;
public :
	Fixed();
	~Fixed();
	void setRawBits(int const raw);
	int getRawBits(void) const;
	Fixed(const Fixed& other);
	Fixed(const int d);
	Fixed(const float f);
	Fixed& operator=(const Fixed& other);
	int toInt(void) const;
	float toFloat(void) const;
};
std::ostream& operator<<(std::ostream &os, Fixed const &fixed);

#endif