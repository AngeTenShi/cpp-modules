#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
	std::string input;

	PhoneBook phonebook;
	std::cout << "Commande chacal : ";
	std::cin >> input;
	while (input.compare("EXIT"))
	{
		if (input.compare("ADD") == 0)
			phonebook.add_contact();
		else if (input.compare("SEARCH") == 0)
			phonebook.search_contact();
		std::cout << "Commande chacal : ";
		std::cin >> input;
	}
	return (0);
}