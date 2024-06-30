/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:05:59 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/25 17:26:08 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>

class Fixed
{
private:
	int	_int1;
	const static int _int2 = 8;
	
public:
	Fixed();
	Fixed(const Fixed &t);
	Fixed&operator=(const Fixed& t);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};




#endif