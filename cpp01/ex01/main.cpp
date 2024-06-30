/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:30:17 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/24 11:15:16 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main(void)
{
	int	N = 10;
	Zombie *newHorde = zombieHorde(N, "Georges");
	if (newHorde)
	{
		for (size_t i = 0; i < N; i++)
			newHorde[i].announce();
		delete[] newHorde;
	}
	return (0);
}