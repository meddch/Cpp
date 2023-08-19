/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 10:05:55 by mechane           #+#    #+#             */
/*   Updated: 2023/08/19 10:13:02 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern &other);
	Intern &operator=(Intern &other);
	~Intern();
	AForm*	makeForm( std::string form, std::string target );
	AForm*	newShrubbery( std::string target );
	AForm*	newPresidential( std::string target );
	AForm*	newRobotomy( std::string target );
};
