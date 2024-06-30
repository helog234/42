/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:29:36 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/28 15:22:33 by hgandar          ###   ########.fr       */
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
	
	Albert.attack("Josef");
	Josef.takeDamage(2);
	Alice.attack("Albert");
	Albert.takeDamage(3);
	Josef.beRepaired(1);
	std::cout << "*****" << std::endl;
	Albert.displayInfo();
	Josef.displayInfo();
	Alice.displayInfo();
	std::cout << "*****" << std::endl;
	Josef.attack("Albert");
	Alice.attack("Albert");
	Alice.attack("Josef");
	Albert.takeDamage(4);
	Josef.takeDamage(8);
	Josef.attack("Alice");
	Alice.takeDamage(3);
	std::cout << "*****" << std::endl;
	Albert.displayInfo();
	Josef.displayInfo();
	Alice.displayInfo();
	std::cout << "*****" << std::endl;
	}