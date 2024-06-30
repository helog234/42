/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:12:21 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/30 14:11:05 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{

public:
	FragTrap(void);
	FragTrap(std::string Name);
	FragTrap(const FragTrap& other);
	FragTrap &operator=(const FragTrap& other);
	~FragTrap();
	void attack(const std::string& target);
	void highFivesGuys(void);

private:
	
};

#endif