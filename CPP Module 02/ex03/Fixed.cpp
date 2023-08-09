/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:01 by mechane           #+#    #+#             */
/*   Updated: 2023/08/09 16:38:34 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::frac_bits = 8;

Fixed::Fixed() : _value(0)
{
	// std::cout  << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
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
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

Fixed::Fixed(const int d)
{
	// std::cout << "INT Constructor called" << std::endl;
	_value = d << frac_bits;
}

Fixed::Fixed(const float f)
{
	// std::cout << "FLOAT Constructor called" << std::endl;
	_value = roundf((float)f * (1 << frac_bits));
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

// comparison operators:
bool Fixed::operator>(const Fixed& other) const
{
	return (_value > other.getRawBits());
}
bool Fixed::operator>=(const Fixed& other)
{
	return (_value < other.getRawBits());
}
bool Fixed::operator<(const Fixed& other) const
{
	return (_value < other.getRawBits());
}
bool Fixed::operator<=(const Fixed& other)
{
	return (_value <= other.getRawBits());
}
bool Fixed::operator!=(const Fixed& other)
{
	return (_value != other.getRawBits());
}
bool Fixed::operator==(const Fixed& other)
{
	return (_value != other.getRawBits());
}

//arithmetic operators:
Fixed Fixed::operator+(const Fixed& other)
{
	Fixed	res;
	res.setRawBits(_value + other.getRawBits());
	return res;
}
Fixed Fixed::operator-(const Fixed& other)
{
	Fixed	res;
	res.setRawBits(_value - other.getRawBits());
	return res;
}
Fixed Fixed::operator*(const Fixed& other)
{
	Fixed	res;
	res.setRawBits(((long long)_value * other.getRawBits()) >> frac_bits);
	return res;
}

//  increment/decrement
Fixed Fixed::operator/(const Fixed& other)
{
	Fixed	res;
	if (!other.getRawBits())
	{
		std::cerr << "Division by zero is undefined" << std::endl;
		exit(1);
	}
	res.setRawBits((_value << frac_bits)/ other.getRawBits());
	return res;
}

Fixed	Fixed::operator--(int)
{
	Fixed	res(*this);

	this->_value--;
	return res;
}
Fixed	Fixed::operator++(int)
{
	Fixed	res(*this);

	this->_value++;
	return res;
}

Fixed	&Fixed::operator++(void)
{
	this->_value++;
	return *this;
}
Fixed	&Fixed::operator--(void)
{
	this->_value--;
	return *this;
}

//comparison functions
Fixed	Fixed::min(Fixed& Fixed1 , Fixed& Fixed2)
{
	return ((Fixed1 < Fixed2) ? Fixed1 : Fixed2);
}
Fixed	Fixed::max(Fixed& Fixed1 , Fixed& Fixed2)
{
	return ((Fixed1 > Fixed2) ? Fixed1 : Fixed2);
}
Fixed Fixed::min(Fixed const &Fixed1 , Fixed const &Fixed2)
{
	return ((Fixed1 < Fixed2) ? Fixed1 : Fixed2);
}
Fixed Fixed::max(Fixed const &Fixed1 , Fixed const &Fixed2)
{
	return ((Fixed1 > Fixed2) ? Fixed1 : Fixed2);
}
