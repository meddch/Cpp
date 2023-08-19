/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:08:55 by mechane           #+#    #+#             */
/*   Updated: 2023/08/19 16:07:22 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(Intern &other)
{
	(void)other;
	return(*this);
}

Intern::~Intern(){}

AForm*	Intern::newShrubbery(std::string target)
{
	return(new ShrubberyCreationForm(target));
}
AForm*	Intern::newPresidential( std::string target )
{
	return(new PresidentialPardonForm(target));
}
AForm*	Intern::newRobotomy(std::string target)
{
	return(new RobotomyRequestForm(target));
}

AForm*	Intern::makeForm(std::string form, std::string target)
{
	std::string	s[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*p[3])(std::string) = {&Intern::newShrubbery, &Intern::newRobotomy, &Intern::newPresidential};
	int i = 0;

	while (i < 3 && s[i].compare(form) != 0)
		i++;
	if (i < 3)
	{
		std::cout << "Intern creates " << s[i] << std::endl;
		return((this->*p[i])(target));
	}
	else
		std::cout << "Exception: " << form << " is not a valid name for a form!" << std::endl;
	return (NULL);
}