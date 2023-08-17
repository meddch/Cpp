/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:11:11 by mechane           #+#    #+#             */
/*   Updated: 2023/08/17 13:31:20 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other.getName(), other.getGradeRequiredToSign(), other.getGradeRequiredToExecute()) ,_target(other._target){}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}


void	PresidentialPardonForm::execute( const Bureaucrat &exec) const
{
	this->AForm::check_exec(exec);
	std::cout << this->_target << ",  you have been pardoned by Zaphod Beeblerox." << std::endl;
}