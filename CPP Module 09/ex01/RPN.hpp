/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:54:29 by mechane           #+#    #+#             */
/*   Updated: 2023/09/08 18:42:42 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stack>


enum Type {
    NBR = 1,
    PLUS = 2,
    MINUS = 3,
    MULT = 4,
    DIV = 5,
    NONE = 6,
};

class RPN {
public:
    int type;
    int value;
	
    RPN(int typ, int val = 0);
	RPN(char token);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();
	
	static int Res(int left, int right, char opera);
	static int Calcul(char *input);
};
