#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) 
{
	
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

