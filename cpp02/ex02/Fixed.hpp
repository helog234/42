/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:58:07 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/27 13:34:20 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>
#pragma once

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
	Fixed&	operator=(const Fixed& t);
	~Fixed();
	int 	getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int 	toInt( void ) const;
	bool	operator>(const Fixed& t) const;
	bool	operator<(const Fixed& t) const;
	bool	operator>=(const Fixed& t) const;
	bool	operator<=(const Fixed& t) const;
	bool	operator==(const Fixed& t) const;
	bool	operator!=(const Fixed& t) const;
	Fixed	operator+(const Fixed& t) const;
	Fixed	operator-(const Fixed& t) const;
	Fixed	operator*(const Fixed& t) const;
	Fixed	operator/(const Fixed& t) const;
	Fixed&	operator++(void);
	Fixed	operator++(int i);
	Fixed&	operator--(void);
	Fixed	operator--(int i);
	static			Fixed&	min(Fixed& a, Fixed& b);
	static const	Fixed&	min(const Fixed& a, const Fixed& b);
	static			Fixed&	max(Fixed& a, Fixed& b);
	static const	Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif