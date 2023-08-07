/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 06:25:20 by mechane           #+#    #+#             */
/*   Updated: 2023/08/07 06:25:21 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(Ice const & ref);
		Ice & operator=(Ice const & ref);
		std::string const & getType() const;
		Ice *clone() const;
		void use(ICharacter& target);
	private:
		std::string _type;
};

#endif