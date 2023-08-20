/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:40:31 by mechane           #+#    #+#             */
/*   Updated: 2023/08/20 15:19:48 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int 	ScalarConverter::_int = 0;
char	ScalarConverter::_char = 0;
float	ScalarConverter::_float = 0;
double	ScalarConverter::_double = 0;
bool	ScalarConverter::_valid = 0;
bool	ScalarConverter::_special = 0;
bool	ScalarConverter::_onlyDouble = 0;
bool	ScalarConverter::_noChar = 0;


ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	return *this;
}
void	ScalarConverter::ConvertChar(std::string &c)
{
		if (c.length() == 3)
		{
			_char = c.c_str()[1];
			_int = static_cast<int>(_char);
			_float = static_cast<float>(_int);
			_double = static_cast<double>(_int);
			return ;
		}
		_valid = false;
		std::cout << "Error : Invalid char literal :" << c << std::endl;

}

void	ScalarConverter::ConvertFloat(std::string &c)
{
	bool sign = (c[0] == '+');
	
}


void	ScalarConverter::convert(std::string &s)
{
	if (s.empty())
	{
		std::cout << "Invalid literal : Empty string !!" << std::endl;
		return;
	}
	else if (s[0] == '\'' && s[s.length() - 1] == '\'')
		ConvertChar(s);
	else if(s.find_first_of('.') != std::string::npos)
	{
		if (s.find('f') != std::string::npos)
			ConvertFloat(s);
	}

}


