/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:29:36 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/12 14:33:42 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap Albert = ClapTrap("Albert");
	FragTrap Josef = FragTrap("Josef");
	ScavTrap Alice = ScavTrap("Alice");
	
	Albert.displayInfo();
	Josef.displayInfo();
	Alice.displayInfo();
	for (int i = 0; i < 3; ++i)
	{
		Alice.attack("Albert");
		Albert.takeDamage(2);
	}
	Alice.beRepaired(4);
	
	for (int i = 0; i < 10; ++i)
    {
		Albert.attack("Alice");
		Alice.takeDamage(2);
	}
	Josef.highFivesGuys();
	Albert.displayInfo();
	Josef.displayInfo();
	Alice.displayInfo();
	std::cout << "*****" << std::endl;
}