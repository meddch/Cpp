/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:08:08 by mechane           #+#    #+#             */
/*   Updated: 2023/08/17 11:42:29 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm( std::string target ): AForm("RobotomyRequest", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm &other):  AForm(other.getName(), other.getGradeRequiredToSign(), other.getGradeRequiredToExecute()) ,_target(other._target){}

RobotomyRequestForm	&RobotomyRequestForm::operator=( RobotomyRequestForm &other)
{
	AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}


void	RobotomyRequestForm::execute( const Bureaucrat &exec) const
{
	this->AForm::check_exec(exec);
	std::cout << " DRILLING NOISES :" << std::endl;
	std::cout << " DDZZZZZZZZZZZZZZZZZZ" << std::endl;
	std::cout << " DDZZZZZZZZZZZZZZZZZZ" << std::endl;
	int	random = rand() % 2;
	std::cout << this->_target << ((rand == 0) ? " has been robotomized successfully" : " has failed to be robotomized.") << std::endl;

}