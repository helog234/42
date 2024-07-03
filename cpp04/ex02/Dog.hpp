/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:04:03 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/01 17:26:15 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
public:
	Dog();
	Dog(const Dog& other);
	Dog &operator=(const Dog& other);
	~Dog();
	void makeSound() const;
	std::string getType();
	
protected:
	std::string _type;

private:
	Brain* _Brain;
};

#endif