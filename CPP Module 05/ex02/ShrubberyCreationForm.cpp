/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:19:05 by mechane           #+#    #+#             */
/*   Updated: 2023/08/16 18:32:09 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : _target(src._target)
{
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return;
}

ShrubberyCreationForm& 	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	(void)rhs;

	return (*this);
}

void					ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	try
	{
		// std::cout << executor.getName() << " tried to execute " << getName() << std::endl;
		if (executor.executeForm(*this) == true)
		{
			std::ofstream	ofs(_target + "_shrubbery", std::ios_base::app);
			ofs << TREE << std::endl;
		}
		else
			throw (FormNotExecutedException());
	}
	catch (FormNotExecutedException& e)
	{
		// std::cout << e.what() << std::endl;
	}
	return;
}


