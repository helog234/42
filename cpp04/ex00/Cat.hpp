/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:07:21 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/01 13:55:51 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat: public Animal
{
public:
	Cat();
	Cat(const Cat& other);
	Cat &operator=(const Cat& other);
	~Cat();
	void makeSound();
	std::string getType();

protected:
	std::string _type;
};

#endif