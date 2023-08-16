/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:01:50 by mechane           #+#    #+#             */
/*   Updated: 2023/08/16 14:14:12 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int garde_s, int garde_ex) :
	 _name(name), _grade_s(garde_s) , _grade_ex(garde_ex)
{
	if (_grade_s< 1 || _grade_ex < 1)
        throw GradeTooHighException();
    else if (_grade_s > 150 || _grade_ex > 150)
        throw GradeTooLowException();
	_signed  = false;
}

Form::~Form(){}

Form::Form(const Form &other) : _name(other._name),_grade_s(other._grade_s) , _grade_ex(other._grade_ex)
{
	*this = other;
}

Form &Form::operator=(const Form &other)
{
	if (this == &other)
		return *this;
	this->_signed = other._signed;
	return *this;
}



const char *Form::GradeTooHighException::what(void) const throw()
{
	return "Form : Exception Grade too high!";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return "Form : Exception Grade too low!";
}

const std::string& Form::getName() const
{
    return _name;
}

bool Form::getSigned() const
{
    return _signed;
}

int Form::getGradeRequiredToSign() const
{
    return _grade_s;
}

int Form::getGradeRequiredToExecute() const
{
    return _grade_ex;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form: " << form.getName() << std::endl;
    os << "Signed: " << (form.getSigned() ? "Yes" : "No") << std::endl;
    os << "Grade required to sign: " << form.getGradeRequiredToSign() << std::endl;
    os << "Grade required to execute: " << form.getGradeRequiredToExecute() << std::endl;
    return os;
}

void	Form::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() <= this->_grade_s)
		_signed = true;
	else
		throw GradeTooLowException();
}