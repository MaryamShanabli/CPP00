#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main()
{
	PhoneBook	book;
	std::string	cmd;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, cmd))
			break;
		if (cmd == "ADD")
		{
			Contact	c;
			std::string	s;
			bool		valid = true;

			std::cout << "First name: ";
			std::getline(std::cin, s);
			if (s.empty()) valid = false;
			c.setFirstName(s);

			std::cout << "Last name: ";
			std::getline(std::cin, s);
			if (s.empty()) valid = false;
			c.setLastName(s);

			std::cout << "Nickname: ";
			std::getline(std::cin, s);
			if (s.empty()) valid = false;
			c.setNickname(s);

			std::cout << "Phone number: ";
			std::getline(std::cin, s);
			if (s.empty()) valid = false;
			c.setPhoneNumber(s);

			std::cout << "Darkest secret: ";
			std::getline(std::cin, s);
			if (s.empty()) valid = false;
			c.setDarkestSecret(s);

			if (!valid)
				std::cout << "Field cannot be empty" << std::endl;
			else
				book.addContact(c);
		}
		else if (cmd == "SEARCH")
		{
			book.displayList();
			if (book.getTotal() == 0)
				continue;
			std::cout << "Enter index: ";
			std::getline(std::cin, cmd);
			if (cmd.empty())
			{
				std::cout << "Invalid index" << std::endl;
				continue;
			}
			for (size_t i = 0; i < cmd.length(); ++i)
			{
				if (!std::isdigit(cmd[i]))
				{
					std::cout << "Invalid index" << std::endl;
					cmd = "";
					break;
				}
			}
			if (cmd.empty())
				continue;
			int index = std::atoi(cmd.c_str());
			book.displayContact(index);
		}
		else if (cmd == "EXIT")
			break;
	}
	return 0;
}