/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:42:43 by mohamoha          #+#    #+#             */
/*   Updated: 2024/05/31 18:52:27 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

PhoneBook::PhoneBook() : currentIndex(0), contactCount(0) {}

void PhoneBook::addContact(const Contact &contact)
{
    contacts[currentIndex] = contact;
    currentIndex = (currentIndex + 1) % maxContacts;
    if (contactCount < maxContacts)
        contactCount++;
}

void PhoneBook::displayContacts() const
{
    std::cout << "=============================================" << std::endl;
	std::cout << "|" << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "=============================================" << std::endl;	  
    for (int i = 0; i < contactCount; ++i)
	{
        std::cout << "|" << std::setw(10) << i << "|"
                  << std::setw(10) << append(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << append(contacts[i].getLastName()) << "|"
                  << std::setw(10) << append(contacts[i].getNickname()) << "|" << std::endl;
    }
	std::cout << "---------------------------------------------" << std::endl;
}

void PhoneBook::displayContact(int index) const
{
	if (index >= 0 && index < contactCount)
        contacts[index].display();
	else
        std::cout << "Invalid index!" << std::endl;
}

std::string PhoneBook::append(const std::string &str) const
{
	if (str.length() > 10)
        return (str.substr(0, 9) + ".");
	else
        return (str);
}

void check_eof()
{
	if (std::cin.eof())
	{
        std::cout << "EOF reached, Phonebook closed." << std::endl;
		exit (1);
    }
}
