/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:08:07 by mechane           #+#    #+#             */
/*   Updated: 2023/07/29 11:31:41 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
class Fixed
{
	int	_n;
	static const int _b = 8;	
public :
	Fixed();
	~Fixed();
	void setRawBits(int const raw);
	int getRawBits(void) const;

	
};
#endif