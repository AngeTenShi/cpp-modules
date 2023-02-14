#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
	std::string input;

	PhoneBook phonebook;
	std::cout << "Commande chacal : ";
	std::cin >> input;
	if (std::cin.eof())
		return (0);
	while (input.compare("EXIT"))
	{
		if (input.compare("ADD") == 0)
			phonebook.add_contact();
		else if (input.compare("SEARCH") == 0)
			phonebook.search_contact();
		std::cout << "Commande chacal : ";
		std::cin >> input;
		if (std::cin.eof())
			exit(0);
	}
	return (0);
}