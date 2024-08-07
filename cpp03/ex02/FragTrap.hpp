/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:12:21 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/04 15:25:06 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{

public:
	FragTrap(std::string Name);
	FragTrap(const FragTrap& other);
	FragTrap &operator=(const FragTrap& other);
	~FragTrap();
	void attack(const std::string& target);
	void highFivesGuys(void);

private:
	
};

#endif