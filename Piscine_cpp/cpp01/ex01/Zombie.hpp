/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:58:22 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/03 15:59:41 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie
{	
public:
	Zombie();
	~Zombie();
	
	void setName(std::string name);
	void announce( void ) const;
	
private:
	std::string	_name;

};
#endif
