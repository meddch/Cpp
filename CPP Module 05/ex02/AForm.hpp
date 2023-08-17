/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:11:53 by mechane           #+#    #+#             */
/*   Updated: 2023/08/16 17:58:18 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	const std::string _name;
	bool			_signed;
	const		int _grade_s;
	const		int _grade_ex;
public :
	AForm(std::string name, int grade_s, int grade_ex);
	~AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	const std::string& getName() const;
    bool getSigned() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredToExecute() const;
	void beSigned(const Bureaucrat &bur);
	void	check_exec(const Bureaucrat &exec) const;
	virtual void		execute( Bureaucrat const &executor ) const = 0;
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
		class FormNotSigned : public std::exception
		{
			public:
				const char	*what( void ) const throw();
		};

		class FileNotOpen : public std::exception
		{
			public:
				const char	*what( void ) const throw();
		};

};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);


#endif
