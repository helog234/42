/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:07:21 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/15 14:19:45 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal
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