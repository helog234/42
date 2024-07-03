/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:04:52 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/03 12:57:08 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
# include "AMateria.hpp"

class Cure: public AMateria
{
	/* private:
		std::string const & _type; */
	public:
		Cure();
		//Cure(std::string const & type);
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);
		Cure* clone() const;
		~Cure();
		//void use(ICharacter& target);
};


#endif