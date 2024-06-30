/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:48:18 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/25 13:50:26 by hgandar          ###   ########.fr       */
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
			instance.complain(str);
		}
	}
	return (0);
}