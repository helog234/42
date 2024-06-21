/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:01:57 by hgandar           #+#    #+#             */
/*   Updated: 2024/06/20 10:40:13 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <iostream>
# include <string>
# include "contact.hpp"

class Phonebook
{
	public:
		Phonebook(void);
		~Phonebook(void);
		
		void addContact();
		void searchContact() const;
		void printList(const std::string& str) const;
		void printContact(int index) const;
	
	private:
		Contact _Contacts[8];
		int		_index;
};

#endif