#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
{
	_total = 0;
	_index = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::addContact(const Contact &contact)
{
	_contacts[_index] = contact;
	_index = (_index + 1) % 8;
	if (_total < 8)
		_total++;
}

int	PhoneBook::getTotal() const
{
	return _total;
}

std::string	PhoneBook::_formatField(const std::string &str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return std::string(10 - str.length(), ' ') + str;
}

void	PhoneBook::displayList() const
{
	std::cout << "|" << std::setw(10) << "index"
		<< "|" << std::setw(10) << "first name"
		<< "|" << std::setw(10) << "last name"
		<< "|" << std::setw(10) << "nickname" << "|" << std::endl;
	for (int i = 0; i < _total; ++i)
	{
		std::cout << "|" << std::setw(10) << i
			<< "|" << _formatField(_contacts[i].getFirstName())
			<< "|" << _formatField(_contacts[i].getLastName())
			<< "|" << _formatField(_contacts[i].getNickname()) << "|" << std::endl;
	}
}

void	PhoneBook::displayContact(int index) const
{
	if (index < 0 || index >= _total)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	std::cout << "First name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
}