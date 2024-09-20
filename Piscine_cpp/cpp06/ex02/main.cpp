/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:02:36 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/19 13:43:26 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Derived.hpp"

int	main(void)
{
	srand (time(NULL));
	for (size_t i = 0; i < 10; i++)
	{
		Base* test = generate();
		identify(test);
		identify(*test);
		delete test;
	}
	return 0;
}