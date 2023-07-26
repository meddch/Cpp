/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:45:27 by mechane           #+#    #+#             */
/*   Updated: 2023/07/26 14:17:17 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	
	char name[] = "Spitter";
	int N = 5;
	
	Zombie* zombies = zombieHorde(N, name);

    for (int i = 0; i < N; i++) {
        zombies[i].announce();
    }
	 delete[] zombies;
}