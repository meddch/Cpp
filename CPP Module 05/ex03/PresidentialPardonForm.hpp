/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:11:15 by mechane           #+#    #+#             */
/*   Updated: 2023/08/17 13:30:10 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"
#include <fstream>
#include <string>

class PresidentialPardonForm : public AForm
{
	const std::string		_target;
public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& 	operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
		void execute( const Bureaucrat &exec) const;
};