/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:13:52 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/29 11:59:58 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
		std::cout << "Error" << std::endl;
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