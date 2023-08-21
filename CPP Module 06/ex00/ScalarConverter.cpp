/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:40:31 by mechane           #+#    #+#             */
/*   Updated: 2023/08/21 14:03:56 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int 	ScalarConverter::_int = 0;
char	ScalarConverter::_char = 0;
float	ScalarConverter::_float = 0;
double	ScalarConverter::_double = 0;
bool	ScalarConverter::_noInt = 0;
bool	ScalarConverter::_noChar = 0;
bool	ScalarConverter::_noDis = 0;
bool	ScalarConverter::_is_int = 0;
bool	ScalarConverter::_valid = 0;


ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

bool ScalarConverter::isStringDigits(const std::string& str)
{
	size_t found = 0;
	int p = 0;
	if (str[p] == '-' || str[p] == '+')
		p++;
	for (int i = 0 ; i < 2; i++)
	{
		found = str.find('.', found + 1);
		if (i > 1 || !found)
			return false;
	}
	for (int i = p; i < (int)str.length() - 1; i++)
	{
        if (!std::isdigit(static_cast<unsigned char>(str[i])) && str[i] != '.')
		{
			printf("%c\n",str[i]);
            return false;
		}
    }
	if ((str[str.length() - 1] == 'f' && isdigit(str[str.length() - 2]) )|| isdigit(str[str.length() - 1]) )
    	return true;
	return false;
}

double	ScalarConverter::To_Num(std::string &s)
{
	std::istringstream iss(s);

	double value;
	iss >> value;

	return value;
}



bool	ScalarConverter::SpecialCase(std::string  &c)
{
	std::string cases[6] = {"nan","nanf","-inf","-inff","+inf","+inff"};
	for(int i = 0;i < 6;i++)
	{
		if (!c.compare(cases[i]))
		{
			std::cout << "Char   : Impossible\n";
			std::cout << "Int    : Impossible\n";
			std::cout << "Float  : " << ((i % 2) == 0 ? cases[i + 1] : cases[i]) << std::endl;
			std::cout << "Double : " << ((i % 2) != 0 ? cases[i - 1] : cases[i]) << std::endl;
			return true;
		}
	}
	return false;
}



void	ScalarConverter::ConvertChar(std::string &c)
{
		if (c.length() == 3)
		{
			_valid = true;
			_char = c.c_str()[1];
			_int = static_cast<int>(_char);
			_float = static_cast<float>(_int);
			_double = static_cast<double>(_int);
			return ;
		}
		_valid = false;
		std::cout << "Error : Invalid char literal :" << c << std::endl;
}

void	ScalarConverter::ConvertFloat(std::string &s)
{
	s = s.erase(s.length() - 1, 1);

	_valid = true;
	_float = To_Num(s);
	_double = static_cast<double>(_float);
	_char = static_cast<char>(_float);
	_int = static_cast<int>(_float);
	((_int > 126 || _int < 0)) ? (_noChar = 1) : (_noChar = 0);
	((_int > 126 || _int < 32)) ? (_noDis = 1) : (_noDis = 0);
	(static_cast<long long>(_double) > INT_MAX && static_cast<long long>(_double) < INT_MIN) ? (_noInt = 1) : (_noInt = 0);

}

void	ScalarConverter::ConvertDouble(std::string &s)
{
	_valid = true;
	_double = To_Num(s);
	_float = static_cast<float>(_double);
	_char = static_cast<char>(_double);
	_int = static_cast<int>(_double);
	((_int > 126 || _int < 0)) ? (_noChar = 1) : (_noChar = 0);
	((_int > 126 || _int < 32)) ? (_noDis = 1) : (_noDis = 0);
	(static_cast<long long>(_double) > INT_MAX && static_cast<long long>(_double) < INT_MIN) ? (_noInt = 1) : (_noInt = 0);
}

void	ScalarConverter::ConvertInt(std::string &s)
{
	long long l = To_Num(s);

	if (l > INT_MAX || l < INT_MIN)
	{
		_valid = false;
		std::cout << "Error : Invalid int literal :" << s << std::endl;
		return ;
	}
	_valid = true;
	_is_int = true;
	_double = static_cast<double>(l);
	_float = static_cast<float>(l);
	_char = static_cast<char>(l);
	_int = static_cast<int>(l);
	(_int > 127 || _int < 0) ? (_noChar = 1) : (_noChar = 0);
	(_int == 127 || _int < 32) ? (_noDis = 1) : (_noDis = 0);
}



void	ScalarConverter::convert(std::string &s)
{
	if (s.empty())
	{
		std::cout << "Invalid literal : Empty string !!" << std::endl;
		return;
	}
	else if (SpecialCase(s))
		return ;
	else if (s[0] == '\'' && s[s.length() - 1] == '\'')
		ConvertChar(s);
	else if (!isStringDigits(s))
		{
			std::cout << " ---Error---" << std::endl;
			std::cout << "The literal must belong to one of the following scalar types:" << std::endl;
			std::cout << "• char" << std::endl;
			std::cout << "• int" << std::endl;
			std::cout << "• float" << std::endl;
			std::cout << "• double" << std::endl;
			return ;
		}
	else if(s.find_first_of('.') != std::string::npos)
	{
		if (s.find('f') != std::string::npos)
			ConvertFloat(s);
		else
			ConvertDouble(s);
	}
	else
		ConvertInt(s);
	if (!_valid)
		return ;
	if (_noDis || _noChar)
		std::cout << "Char   : " << (_noChar == 1 ? "Impossible ." : "No Displayable .") << std::endl;
	else
		std::cout << "Char   : \'" << _char << "\'\n";
	(_noInt) && (std::cout << "Int    : " << "Impossible ." << std::endl);
	(!_noInt) && (std::cout << "Int    : " << _int << std::endl);
	std::cout << "Float  : " << _float << ((_is_int || _float == _int) ? (".0f") : "f") << std::endl;
	std::cout << "Double : " << _double << ((_is_int || _float == _int) ? (".0") : "") << std::endl;
}


