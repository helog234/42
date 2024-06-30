/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:09:29 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/24 09:26:53 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef ZOMBIE_H
# define ZOMBIE_H

class Zombie
{	
public:
	Zombie(std::string name);
	~Zombie();
	
	void announce( void );
	
private:
	std::string	_name;

};



#endif
