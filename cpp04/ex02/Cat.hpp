/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:07:21 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/01 17:26:08 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
public:
	Cat();
	Cat(const Cat& other);
	Cat &operator=(const Cat& other);
	~Cat();
	void makeSound() const;
	std::string getType();

protected:
	std::string _type;

private:
	Brain* _Brain;
};

#endif