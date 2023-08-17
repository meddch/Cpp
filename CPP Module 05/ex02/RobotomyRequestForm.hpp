/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:08:13 by mechane           #+#    #+#             */
/*   Updated: 2023/08/17 11:43:29 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <AForm.hpp>

class RobotomyRequestForm: public AForm
{
	const std::string	_target;
public:
	RobotomyRequestForm( RobotomyRequestForm &other);
	RobotomyRequestForm &operator=( RobotomyRequestForm &other);
	~RobotomyRequestForm();
	RobotomyRequestForm( std::string target );
	void	execute( Bureaucrat const &executor ) const;
};

