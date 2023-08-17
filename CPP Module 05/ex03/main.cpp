/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 09:54:31 by mechane           #+#    #+#             */
/*   Updated: 2023/08/17 13:32:59 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int	main( void )
{
	AForm		*shrub = new ShrubberyCreationForm("home");
	Bureaucrat	corr("Corrector", 1);
	Bureaucrat	me("Me", 140);

	corr.executeForm(*shrub);
	std::cout << std::endl;
	corr.signAForm(*shrub);
	std::cout << *shrub << std::endl;
	std::cout << corr << std::endl;
	corr.executeForm(*shrub);
	me.executeForm(*shrub);
	delete shrub;

	std::cout << std::endl;
	std::cout << std::endl;

	AForm		*robotomy = new RobotomyRequestForm("You");
	Bureaucrat	me2("Me", 1);

	me2.executeForm(*robotomy);
	me2.signAForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	delete robotomy;

	std::cout << std::endl;
	std::cout << std::endl;

	AForm		*presidential = new PresidentialPardonForm("you");
	Bureaucrat	me3("Me", 5);

	me3.executeForm(*presidential);
	me3.signAForm(*presidential);
	me3.executeForm(*presidential);
	me3.decrementGrade();
	me3.executeForm(*presidential);
	delete presidential;

	return (0);
}