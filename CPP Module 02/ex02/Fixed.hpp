/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:07 by mechane           #+#    #+#             */
/*   Updated: 2023/08/09 09:41:55 by mechane          ###   ########.fr       */
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
	int toInt(void) const;
	float toFloat(void) const;
	Fixed& operator=(const Fixed& other);
	bool operator>(const Fixed& other) const;
	bool operator>=(const Fixed& other);
	bool operator<(const Fixed& other) const ;
	bool operator<=(const Fixed& other);
	bool operator!=(const Fixed& other);
	bool operator==(const Fixed& other);
	Fixed operator+(const Fixed& other);
	Fixed operator-(const Fixed& other);
	Fixed operator*(const Fixed& other);
	Fixed operator/(const Fixed& other);
	Fixed &operator++(void);
	Fixed &operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);
	static Fixed min(Fixed& Fixed1 , Fixed& Fixed2);
	static Fixed max(Fixed& Fixed1 , Fixed& Fixed2);
	static  Fixed min(Fixed const &Fixed1 , Fixed const &Fixed2);
	static  Fixed max(Fixed const &Fixed1 , Fixed  const &Fixed2);
};
std::ostream& operator<<(std::ostream &os, Fixed const &fixed);

#endif