/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:42:36 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/24 09:49:03 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int	main(void)
{
	Zombie *add = newZombie("Rotten Ralph");
	add->announce();
	randomChump("Gory Gabe");
	delete(add);
}
