/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:58:02 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/01 17:04:20 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
public:
	Animal(void);
	Animal(std::string type);
	Animal(const Animal& other);
	Animal &operator=(const Animal& other);
	virtual ~Animal();
	void makeSound() const;
	std::string getType() const;

protected:
	std::string _type;
};


#endif