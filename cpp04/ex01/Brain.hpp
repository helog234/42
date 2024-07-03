/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:54:37 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/01 16:41:38 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
public:
	Brain();
	Brain(const Brain& other);
	Brain &operator=(const Brain& other);
	~Brain();

protected:
	 std::string ideas[100];
};

#endif