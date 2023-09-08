/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:53:29 by mechane           #+#    #+#             */
/*   Updated: 2023/09/08 18:46:15 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RPN::RPN(int typ, int val)
{
	type = typ;
	value = val;
}

RPN::RPN(char token)
{
    switch (token)
	{
        case '*':
            *this = RPN(MULT);
			break;
        case '/':
            *this = RPN(DIV);
			break;
        case '+':
            *this = RPN(PLUS);
			break;
        case '-':
            *this = RPN(MINUS);
			break;
        default:
            isdigit(token) ? *this = RPN(NBR, token - '0') : *this = RPN(NONE);
    }
}

RPN::RPN(const RPN &other)
{
	*this = other;
}


RPN::~RPN() {}

RPN & RPN::operator=(const RPN &other)
{
	if (this == &other)
		return (*this);
		
	value = other.value;
	type = other.type;
	
	return (*this);
}

int RPN::Res(int left, int right, char opera)
{
	switch (opera)
	{
		case PLUS:
			return (left + right);
		case MINUS:
			return (left - right);
		case MULT:
			return (left * right);
		case DIV:
		{
			if (!right)
				throw std::runtime_error("Floating Point Exception Dividing on Zero\n");
			return (left / right);
		}
	}
	return (0);
}

int RPN::Calcul(char *input)
{
    std::stack<int> stack;
    std::stringstream expr(input);

    char token;
	int left;
	int right;
	
    while (expr >> token)
	{

        RPN tok(token);

        if (tok.type == NONE)
            throw std::runtime_error("ERROR: bad input\n");

        if (tok.type == NBR)
            stack.push(tok.value);
        
        else
		{

            if (stack.size() < 2)
            	throw std::runtime_error("ERROR: bad input\n");
                
            right = stack.top();
			stack.pop();
            left = stack.top();
			stack.pop();

				
            stack.push(RPN::Res(left,right,tok.type));
        }
    }


    return (stack.size() == 1 ? stack.top() :  throw std::runtime_error("ERROR: bad input\n"));

}

