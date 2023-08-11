#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    
        const std::string _name;
        int				_grade;
    public :
		Bureaucrat(std::string name);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat& other);

};


#endif