/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:42:54 by mohamoha          #+#    #+#             */
/*   Updated: 2024/05/31 14:31:14 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


std::string Contact::getFirstName() const
{
	return (std::string(firstName));
}

std::string Contact::getLastName() const
{
	return (std::string(lastName));
}

std::string Contact::getNickname() const
{
	return (std::string(nickname));	
}

std::string Contact::getPhoneNumber() const
{
	return (std::string(phoneNumber));
}

std::string Contact::getDarkestSecret() const
{
	return (std::string(darkestSecret));
}

void Contact::setContact(const std::string &firstName,
                         const std::string &lastName,
                         const std::string &nickname,
                         const std::string &phoneNumber,
                         const std::string &darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

void Contact::display() const
{
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
