/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 07:48:38 by mechane           #+#    #+#             */
/*   Updated: 2023/08/17 10:53:26 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;
class  Bureaucrat
{
        const std::string _name;
        int				_grade;
public :
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat& other);
		int	getGrade() const ;
		const std::string&  getName() const ;
		void decrementGrade();
		void incrementGrade();
		void signAForm(AForm &AForm) const;
		void	executeForm( AForm &f ) const;
		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char *what() const throw ();
		};

		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char *what() const throw ();
		};
};
std::ostream& operator<<(std::ostream &os, const Bureaucrat &bur);


#endif