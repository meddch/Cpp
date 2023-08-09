/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:01 by mechane           #+#    #+#             */
/*   Updated: 2023/08/09 12:29:22 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::frac_bits = 8;

Fixed::Fixed() : _value(0)
{
	std::cout  << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_value = other.getRawBits();
	return *this;
}

void 	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

Fixed::Fixed(const int d)
{
	std::cout << "INT Constructor called" << std::endl;
	_value = d << frac_bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "FLOAT Constructor called" << std::endl;
	_value = roundf(f * (1 << frac_bits));
}

int Fixed::toInt(void) const
{
	return ((this->_value >=0 ? 1 : -1) * (abs(this->_value) >> frac_bits));
}

float Fixed::toFloat(void) const
{
	return ((float)(this->_value) / (1 << frac_bits));
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return os;
}
