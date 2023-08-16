/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:13:38 by mechane           #+#    #+#             */
/*   Updated: 2023/08/16 18:31:48 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& cpy);
		~ShrubberyCreationForm();

		ShrubberyCreationForm& 	operator=(const ShrubberyCreationForm& rhs);

		void					execute(const Bureaucrat& executor) const;

	private:
		const std::string		_target;
};


