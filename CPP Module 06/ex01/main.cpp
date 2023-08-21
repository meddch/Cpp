/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:32:33 by mechane           #+#    #+#             */
/*   Updated: 2023/08/21 14:41:16 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"


int main()
{
	Data *data;
	uintptr_t pt;

	data = new Data;
	pt = Serializer::serialize(data);

	std::cout << pt << std::endl;
	std::cout << Serializer::deserialize(pt) << std::endl;
	std::cout << std::endl << std::endl;
	data->x = 0;
	data->y = 1;
	std::cout << (uintptr_t)(data) << std::endl;
	std::cout << (Data *)(pt) << std::endl;
}