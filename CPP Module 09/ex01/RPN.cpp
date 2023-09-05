/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:53:29 by mechane           #+#    #+#             */
/*   Updated: 2023/09/05 18:53:31 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& src) : container(src.container) , result(src.result) {}

RPN::~RPN() {}

RPN&	RPN::operator=(const RPN& rhs)
{
	if ( this != &rhs )
	{
		container = rhs.container;
		result = rhs.result;
	}

	return *this ;
}

bool RPN::calculate(std::string av)
{
	for ( std::string::iterator it = av.begin() ; it != av.end() ; it++ )
	{
		if ( *it == ' ')
		{
			continue ;
		}
		else if ( '0' <= *it && *it <= '9' )
		{
			char	str[2];

			str[1] = '\0';
			str[0] = *it;
			container.push( std::atoi(str) );
		}
		else
		{
			if ( container.size() < 2 )
			{
				std::cout << "Invalid expression" << std::endl;
				return false ;
			}
			
			int nbr1;
			int nbr2;

			nbr2 = container.top();
			container.pop();
			nbr1 = container.top();
			container.pop();
			
			if ( *it == '+' )
			{
				container.push(nbr1 + nbr2);
			}
			else if ( *it == '-' )
			{
				container.push(nbr1 - nbr2);
			}
			else if ( *it == '*' )
			{
				container.push(nbr1 * nbr2);
			}
			else if ( *it == '/' )
			{
				if ( nbr2 == 0 )
				{
					std::cout << "you can't divide by zero." << std::endl;
					return false ;
				}
				container.push(nbr1 / nbr2);
			}
		}
	}

	result = container.top();
	container.pop();

	if ( container.size() != 0)
	{
		std::cout << "Invalid expression" << std::endl;
		return false ;
	}
	return true ;
}

int RPN::getResult() const
{
	return result ;
}
