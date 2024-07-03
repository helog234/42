/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:01:14 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/03 12:57:21 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICE_HPP
# define ICE_HPP
# include "iostream"
# include "AMateria.hpp"

class Ice: public AMateria
{
	/* private:
		std::string const & _type; */
	public:
		Ice();
		//Ice(std::string const & type);
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
		Ice* clone() const;
		~Ice();
		//void use(ICharacter& target);
};


#endif