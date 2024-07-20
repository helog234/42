/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:33:21 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/18 17:53:41 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iomanip> 

int	main(void)
{
	Data * school = new Data;
	school->name = "42 Lausanne";
	school->iValue = 42;
	school->fValue = static_cast<float>(84) / 2.0f;
	
	std::cout << "Initially" << std::endl;
	std::cout << school->name << std::endl;
	std::cout << school->iValue << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << school->fValue << std::endl;
	
	uintptr_t test = Serializer::serialize(school);
	Data *reborn = Serializer::deserialize(test);
	
	std::cout << "Reborn" << std::endl;
	std::cout << reborn->name << std::endl;
	std::cout << reborn->iValue << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << reborn->fValue << std::endl;
	delete school;
	return (0);
}