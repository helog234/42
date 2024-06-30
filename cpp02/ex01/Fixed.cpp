/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:39:39 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/27 10:53:44 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
: _int1(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
: _int1(i << _int2)
{
	std::cout << "Int constructor called" << std::endl;
}

// Shift the bit to left (1 is 0000 0001) so it becomes
// 0000 0001 0000 0000 (256 in decimal)
// multiply the float by it (256) which will still give us a float
// then we need to round it so it becomes an int
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_int1 = roundf(f * (1 << 8));
}

Fixed::Fixed(const Fixed &t)
{
	std::cout << "Copy constructor called" << std::endl;
	_int1 = t.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& t)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &t)
		this->_int1 = t.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_int1);
}

void	Fixed::setRawBits( int const raw )
{
	this->_int1 = raw;
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->_int1) / (1 << _int2));
}

int Fixed::toInt( void ) const
{
	return (static_cast<int>(this->_int1) >> this->_int2);
}

// allows to use cout with a fixed class parameter
// Converts the fixed-point value to a float using
// toFloat() and inserts it into the output stream
std::ostream& operator<<(std::ostream& out, const Fixed& value) 
{
	out << value.toFloat();
	return out;
}