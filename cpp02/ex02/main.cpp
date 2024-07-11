/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:58:51 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/11 13:21:23 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

// main de l'exmple
/* int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
} */

int main() {
	std::cout << "Testing constructors" << std::endl;
	Fixed a;
	a = Fixed(1234.4321f);

	// multiplication
	std::cout << "multiplication" << std::endl;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << "b (5.05 * 2): " << b << std::endl; // devrait afficher 10.1

	std::cout << "division" << std::endl;
	Fixed const c(Fixed(b) / Fixed(0));
	std::cout << "c (10.1 / 2): " << c << std::endl; // devrait afficher 5.05

	// max
	std::cout << "max function" << std::endl;
	std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;

	// min
	std::cout << "min function" << std::endl;
	std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
	return 0;
}
