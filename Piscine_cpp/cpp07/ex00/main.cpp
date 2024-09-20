/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:20:18 by hgandar           #+#    #+#             */
/*   Updated: 2024/08/27 16:02:39 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "iostream"

/* int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
} */

int	main(void)
{
	/* int	a = 1;
	int b = 2; */
	
	/* float	a = 1.5;
	float b = 2.5; */
	
	/* std::string a = "Hello ";
	std::string b = "world ! "; */
	
	double a = 42.42;
	double b = 22.22;
	
	std::cout << "a:" << a << " " << "a:" << b << std::endl;
	swap(a, b);
	std::cout << "a:" << a << " " << "a:" << b << std::endl;
	std::cout << "min:" << ::min(a, b) << std::endl;
	std::cout << "max:" << ::max(a, b) << std::endl;
}

