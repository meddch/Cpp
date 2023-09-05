/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:54:29 by mechane           #+#    #+#             */
/*   Updated: 2023/09/05 18:54:30 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once

#include <stack>
#include <string>
#include <iostream>
#include <cstdlib>

class RPN
{
private:
	std::stack< int > container;
	int result;
public:
	RPN();
	RPN(const RPN& src);
	~RPN();
	RPN& operator=(const RPN& rhs);
	
	bool calculate(std::string av);
	int getResult() const;
};

