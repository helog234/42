/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:39:07 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/04 10:42:05 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
private:
	int	_int1;
	const static int _int2 = 8;
	
public:
	Fixed();
	Fixed(const int i);
	Fixed(const float f);
	Fixed(const Fixed &t);
	Fixed&operator=(const Fixed& t);
	~Fixed();
	
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif