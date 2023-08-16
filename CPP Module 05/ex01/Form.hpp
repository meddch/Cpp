/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:11:53 by mechane           #+#    #+#             */
/*   Updated: 2023/08/16 13:33:58 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	const std::string _name;
	bool			_signed;
	const		int _grade_s;
	const		int _grade_ex;
public :
	Form(std::string name, int grade_s, int grade_ex);
	~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);
	const std::string& getName() const;
    bool getSigned() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredToExecute() const;
	void beSigned(const Bureaucrat &bur);
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

std::ostream& operator<<(std::ostream& os, const Form& form);


#endif
