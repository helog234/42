/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:29:36 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/04 14:43:47 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Albert = ClapTrap("Albert");
	ClapTrap Alice = ClapTrap("Alice");
	
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
    Albert.beRepaired(5);
	Alice.beRepaired(5);
}

