/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:58:02 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/15 14:21:02 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <iostream>

class AAnimal
{
public:
	AAnimal(void);
	AAnimal(std::string type);
	AAnimal(const AAnimal& other);
	AAnimal &operator=(const AAnimal& other);
	virtual~AAnimal();
	virtual void makeSound() const = 0;
	std::string getType() const;

protected:
	std::string _type;
};


#endif