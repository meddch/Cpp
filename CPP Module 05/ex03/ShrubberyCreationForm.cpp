/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:19:05 by mechane           #+#    #+#             */
/*   Updated: 2023/08/17 13:03:45 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getName(), other.getGradeRequiredToSign(), other.getGradeRequiredToExecute()) ,_target(other._target){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm& 	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	return *this;
}
void	ShrubberyCreationForm::execute( const Bureaucrat &exec) const
{
	this->AForm::check_exec(exec);
	std::fstream	file;

	file.open((this->_target + "_shrubbery").c_str(), std::ios::out);
	if (!file)
		throw(FileNotOpen());
    file << " 	    ^                  ^			        ^\n";
    file << "       ^^^		          ^^^	     	       ^^^\n";
    file << "      ^^^^^	    	     ^^^^^				  ^^^^^\n";
    file << "     ^^^^^^^	        ^^^^^^^		   	     ^^^^^^^\n";
    file << "    ^^^^^^^^^	       ^^^^^^^^^     	    ^^^^^^^^^\n";
    file << "   ^^^^^^^^^^^	      ^^^^^^^^^^^	       ^^^^^^^^^^^\n";
    file << "  ^^^^^^^^^^^^^    	 ^^^^^^^^^^^^^	      ^^^^^^^^^^^^^\n";
    file << "        |	                |                   |\n";
	file.close();
}
