/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:13:38 by mechane           #+#    #+#             */
/*   Updated: 2023/08/17 12:53:14 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"
#include <fstream>
#include <string>


class ShrubberyCreationForm : public AForm
{
	const std::string		_target;
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& 	operator=(const ShrubberyCreationForm& other);
		void execute( const Bureaucrat &executor ) const;
};


