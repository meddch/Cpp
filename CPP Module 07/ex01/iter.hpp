/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:24:00 by mechane           #+#    #+#             */
/*   Updated: 2023/08/22 12:01:56 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>


template<typename T> void iter(T arr[], int len, void (*f)(T const&))
{
	if (!f || !arr)
		return ;
	for (int i = 0; i < len ; i++)
	{
		(f)(arr[i]);
	}
	return ;
}
