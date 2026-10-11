#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];
	int		_total;
	int		_index;

	static std::string	_formatField(const std::string &str);

public:
	PhoneBook();
	~PhoneBook();

	void	addContact(const Contact &contact);
	void	displayList() const;
	void	displayContact(int index) const;
	int		getTotal() const;
};

#endif