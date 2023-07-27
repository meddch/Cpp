/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:38:25 by mechane           #+#    #+#             */
/*   Updated: 2023/07/27 14:05:24 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money. \
You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl<< "I think I deserve to have some extra bacon for free. \
I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl << "This is unacceptable! I want to speak to\
the manager now." << std::endl;
}
void Harl::complain(std::string level)
{
	std::string msg[4] ={"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*func_Ptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	int index ;
		for (index = 0; index < 4; index++)
			if(level == msg[index])
				break;
	switch (index)
    {
        case 0:
            (this->*func_Ptr[0])();
        case 1:
            (this->*func_Ptr[1])();
        case 2:
            (this->*func_Ptr[2])();
        case 3:
            (this->*func_Ptr[3])();
			break;
        default:
            std::cout << "Unknown level: " << level << std::endl << "You just a baby complaining about irrelevent shit !"
			<< std::endl;
    }
}