/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 07:48:44 by mechane           #+#    #+#             */
/*   Updated: 2023/08/16 17:59:38 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat (const Bureaucrat& other)
{
    *this = other;
}

Bureaucrat&  Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return *this;
	this->_grade = other._grade;
	return *this;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

const std::string&  Bureaucrat::getName() const
{
	return _name;
}

void Bureaucrat::incrementGrade()
{
	if (getGrade() == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (getGrade() == 150)
		throw GradeTooLowException();
	_grade++;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bur)
{
	os << bur.getName() << ", bureaucrat grade : " << bur.getGrade();
	return os;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Bureaucrat : Exception Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Bureaucrat : Exception Grade too low!";
}

void	Bureaucrat::signAForm(AForm &AForm) const
{
	try
	{
		if (AForm.getSigned())
			{
				std::cout << _name << " couldn’t sign " << AForm.getName() << " because AForm already is signed\n";
				return;
			}
		AForm.beSigned(*this);
		std::cout << _name << " signed " << AForm.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " couldn’t sign " << AForm.getName() << " because grade too low\n";
	}
}