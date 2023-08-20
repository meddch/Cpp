/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:40:34 by mechane           #+#    #+#             */
/*   Updated: 2023/08/20 15:17:49 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

// class ScalarConverter
// {
// 	static int					_int;
// 	static char				_char;
// 	static float				_float;
// 	static double				_double;
// 	static bool				_valid;
// 	static bool				_special;
// 	static bool				_onlyDouble;
// 	static bool				_noChar;
// public:
// 	// ScalarConverter(std::string s);
// 	ScalarConverter();
// 	ScalarConverter(ScalarConverter &other);
// 	ScalarConverter	&operator=(ScalarConverter &other);
// 	~ScalarConverter();

// 	static bool	isNum(char c);
// 	static bool	isSpecialCase(void);
// 	static bool	isFloatOrDouble(int mode);
// 	static bool	isSpecialCaseFloat(void);
// 	static bool	isSpecialCaseDouble(void);
// 	static bool	charDisplayable(void);

// 	static int		toInt( char const *s);
// 	static float	toFloat(char const *s);
// 	static double	toDouble(char const *s);

// 	static int		tryInt();
// 	static int		tryChar();
// 	static int		tryFloatOrDouble();

// 	static void	convert();
// };


class ScalarConverter
{
	static int				_int;
	static char				_char;
	static float			_float;
	static double			_double;
	static bool				_valid;
	static bool				_special;
	static bool				_onlyDouble;
	static bool				_noChar;

	public :
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter	&operator=(const ScalarConverter &other);
		~ScalarConverter();
		static void convert(std::string &c);

		static void ConvertChar(std::string &c);
		static void ConvertFloat(std::string &c);

};
