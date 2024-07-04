/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:35:22 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/03 18:20:49 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	std::string str;
	Harl instance;
	
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			str = argv[i];
			std::transform(str.begin(), str.end(), str.begin(), ::toupper);
			instance.complain(str);
		}
	}
	return (0);
}