/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:29:36 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/28 14:40:37 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Albert = ClapTrap("Albert");
	ClapTrap Josef = ClapTrap("Josef");
	ClapTrap Alice = ClapTrap("Alice");
	
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