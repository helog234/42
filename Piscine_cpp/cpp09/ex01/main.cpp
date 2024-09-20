/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:13:52 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/21 15:12:13 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	RPN data = RPN(argv[1]);
	try
	{
		data.calculate();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}