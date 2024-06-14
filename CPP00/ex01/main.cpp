/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:41:24 by mohamoha          #+#    #+#             */
/*   Updated: 2024/05/31 19:57:42 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	check_number(std::string num)
{
	for (size_t i = 0; i < num.length(); i++)
	{
		if(!std::isdigit(num[i]))
		{
			std::cout << "Invalid Phone Number" << std::endl;
			return (0);
		}
	}
	return(1);
}

void addContact(PhoneBook &phoneBook)
{
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);
	check_eof();
    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);
	check_eof();
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
	check_eof();
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);
	check_eof();
	if (!check_number(phoneNumber))
		return;
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkestSecret);
	check_eof();

    if (firstName.empty()
		|| lastName.empty()
		|| nickname.empty()
		|| phoneNumber.empty()
		|| darkestSecret.empty())
	{
        std::cout << "All fields must be filled!" << std::endl;
        return;
    }
	
    Contact newContact;
    newContact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    phoneBook.addContact(newContact);
}

void searchContacts(const PhoneBook &phoneBook)
{
    phoneBook.displayContacts();
    std::cout << "Enter the index of the contact to display: ";
    int index;
	if (!(std::cin >> index))
	{
        // Input is not an integer, clear the input buffer
		check_eof();
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Invalid input! Please enter a valid index." << std::endl;
    }
	else
	{
        // Input is an integer, proceed with displaying the contact
        std::cin.ignore(INT_MAX, '\n');
        phoneBook.displayContact(index);
	}
}

int main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cout << "Error, invalid input, enter: ./Phonebook" << std::endl;
		return (1);
	}
    PhoneBook phoneBook;
    std::string command;

	std::cout << "\033[1;31m   ___   ___  _          ____  _   _  ___  _   _ _____ ____   ___   ___  _  __\n" <<
                 "  ( _ ) / _ \\( )___     |  _ \\| | | |/ _ \\| \\ | | ____| __ ) / _ \\ / _ \\| |/ /\n" <<
                 "  / _ \\| | | |/ __|     | |_) | |_| | | | |  \\| |  _| |  _ \\| | | | | | | ' /\n" <<
                 " | (_) | |_| | \\__ \\    |  __/|  _  | |_| | |\\  | |___| |_) | |_| | |_| | . \\\n" <<
                 "  \\___/ \\___/  |___/    |_|   |_| |_|\\___/|_| \\_|_____|____/ \\___/ \\___/|_|\\_\\\n\033[0m" << std::endl;


	std::cout << "\033[1;34mWelcome to the 80s PhoneBook!\033[0m" << std::endl << std::endl;

    while (true)
	{
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
		check_eof();
		if (command == "ADD")
            addContact(phoneBook);
		else if (command == "SEARCH")
            searchContacts(phoneBook);
		else if (command == "EXIT")
            break;
		else
            std::cout << "Invalid command!" << std::endl;
    }
	
    return 0;
}
