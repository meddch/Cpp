/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:40:34 by mechane           #+#    #+#             */
/*   Updated: 2023/08/19 13:59:09 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>


#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

class ScalarConverter
{
private:
	std::string	const	_s;
	int					_int;
	char				_char;
	float				_float;
	double				_double;
	bool				_valid;
	bool				_special;
	bool				_onlyDouble;
	bool				_noChar;
public:
	ScalarConverter( void );
	ScalarConverter( ScalarConverter &c );
	ScalarConverter( std::string s );

	ScalarConverter	&operator=( ScalarConverter &c );
	~ScalarConverter();

	bool	isNum( char c );
	bool	isSpecialCase( void );
	bool	isFloatOrDouble( int mode );
	bool	isSpecialCaseFloat( void );
	bool	isSpecialCaseDouble( void );

	bool	charDisplayable( void );

	int		toInt( char const *s );
	float	toFloat( char const *s );
	double	toDouble( char const *s );

	int		tryInt();
	int		tryChar();
	int		tryFloatOrDouble();

	void	convert();
};