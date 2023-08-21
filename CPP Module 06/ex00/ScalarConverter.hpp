/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:40:34 by mechane           #+#    #+#             */
/*   Updated: 2023/08/21 14:23:10 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <sstream>


class ScalarConverter
{
	static int				_int;
	static char				_char;
	static float			_float;
	static double			_double;
	static bool				_noInt;
	static bool				_noChar;
	static bool				_noDis;
	static bool				_valid;
	static bool				_is_int;

		static void ConvertChar(std::string &c);
		static void ConvertFloat(std::string &c);
		static void ConvertDouble(std::string &c);
		static bool	SpecialCase(std::string &c);
		static double	To_Num(std::string &s);
		static void	ConvertInt(std::string &s);
		static bool isStringDigits(const std::string& str);

		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter	&operator=(const ScalarConverter &other);
		~ScalarConverter();
	public :
		static void convert(std::string &c);



};
