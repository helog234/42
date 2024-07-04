/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:30:11 by hgandar           #+#    #+#             */
/*   Updated: 2024/07/03 15:34:11 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>

class Contact
{
	public:
		Contact(void);
		Contact(const std::string& FirstName, const std::string& LastName, const std::string& Nickname, const std::string& PhoneNumber, const std::string& DarkestSecret);
		~Contact(void);
		
		std::string getFirstName(void) const;
		void setFirstName(void);
		std::string getLastName(void) const;
		void setLastName(void);
		std::string getNickname(void) const;
		void setNickname(void);
		std::string getPhoneNumber(void) const;
		void setPhoneNumber(void);
		std::string getDarkestSecret(void) const;
		void setDarkestSecret(void);
		int	ctrDigits(std::string) const;
		
	private:
		std::string _FirstName;
		std::string _LastName;
		std::string _Nickname;
		std::string _PhoneNumber;
		std::string _DarkestSecret;
};

#endif
