/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:01:43 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/24 14:22:17 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>
# include <map>


class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		void (Harl::*_complains[4])(void);
	
	public:
		Harl( void );
		~Harl ( void );
		void complain( std::string level );

};


#endif