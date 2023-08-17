/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:01:50 by mechane           #+#    #+#             */
/*   Updated: 2023/08/16 14:14:12 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int garde_s, int garde_ex) :
	 _name(name), _grade_s(garde_s) , _grade_ex(garde_ex)
{
	if (_grade_s< 1 || _grade_ex < 1)
        throw GradeTooHighException();
    else if (_grade_s > 150 || _grade_ex > 150)
        throw GradeTooLowException();
	_signed  = false;
}

AForm::~AForm(){}

AForm::AForm(const AForm &other) : _name(other._name),_grade_s(other._grade_s) , _grade_ex(other._grade_ex)
{
	*this = other;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
		return *this;
	this->_signed = other._signed;
	return *this;
}



const char *AForm::GradeTooHighException::what(void) const throw()
{
	return "AForm : Exception Grade too high!";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return "AForm : Exception Grade too low!";
}
const char	*AForm::FormNotSigned::what( void ) const throw()
{
	return ("AForm: Form is not signed!");
}

const char	*AForm::FileNotOpen::what( void ) const throw()
{
	return ("AForm: File couldn't be opened!");
}

const std::string& AForm::getName() const
{
    return _name;
}

bool AForm::getSigned() const
{
    return _signed;
}

int AForm::getGradeRequiredToSign() const
{
    return _grade_s;
}

int AForm::getGradeRequiredToExecute() const
{
    return _grade_ex;
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
    os << "AForm: " << AForm.getName() << std::endl;
    os << "Signed: " << (AForm.getSigned() ? "Yes" : "No") << std::endl;
    os << "Grade required to sign: " << AForm.getGradeRequiredToSign() << std::endl;
    os << "Grade required to execute: " << AForm.getGradeRequiredToExecute() << std::endl;
    return os;
}

void	AForm::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() <= this->_grade_s)
		_signed = true;
	else
		throw GradeTooLowException();
}

void	AForm::check_exec(const Bureaucrat &exec) const
{
	if (!this->getSigned())
		throw(FormNotSigned());
	if (exec.getGrade() > this->getGradeRequiredToExecute())
		throw(GradeTooLowException());
}