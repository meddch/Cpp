/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:07 by mechane           #+#    #+#             */
/*   Updated: 2023/08/09 09:42:00 by mechane          ###   ########.fr       */
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
	Fixed& operator=(const Fixed& other);

};
#endif