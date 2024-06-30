/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:58:22 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/24 10:27:25 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef ZOMBIE_H
# define ZOMBIE_H

class Zombie
{	
public:
	Zombie(std::string name);
	Zombie();
	~Zombie();
	
	void announce( void );
	
private:
	std::string	_name;

};
#endif
