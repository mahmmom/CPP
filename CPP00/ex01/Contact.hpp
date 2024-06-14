/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:41:44 by mohamoha          #+#    #+#             */
/*   Updated: 2024/05/31 19:55:18 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define	CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <climits>

class Contact{
	public:
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
		void display() const;
		void setContact(const std::string &firstName,
                        const std::string &lastName,
                        const std::string &nickname,
                        const std::string &phoneNumber,
                        const std::string &darkestSecret);

	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
};

#endif