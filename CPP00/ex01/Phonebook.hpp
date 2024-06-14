/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:41:39 by mohamoha          #+#    #+#             */
/*   Updated: 2024/05/31 18:53:52 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	public:
   		PhoneBook();
		void addContact(const Contact &contact);
		void displayContacts() const;
		void displayContact(int index) const;

	private:
		static const int maxContacts = 8;
		Contact contacts[maxContacts];
		int currentIndex;
		int contactCount;
		std::string append(const std::string &str) const;
};

void check_eof();

#endif