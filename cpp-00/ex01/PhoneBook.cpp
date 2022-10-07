#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstring>

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	ask_for_var(std::string *var, char *name, size_t len)
{
	std::cout << name << " : ";
	std::cin >> *var;
	while ((*var).size() > len)
	{
		std::cout << name << " : ";
		std::cin >> *var;
	}
}

void	PhoneBook::add_contact()
{
	std::string f_name;
	std::string l_name;
	std::string nickname;
	std::string phoneNumber;
	std::string secret;
	int	i = 0;
	while (i < 5)
	{
		if (i == 0)
			ask_for_var(&f_name, (char *)"First Name", 20);
		if (i == 1)
			ask_for_var(&l_name, (char *)"Last Name", 20);
		if (i == 2)
			ask_for_var(&nickname, (char *)"Nickname", 20);
		if (i == 3)
			ask_for_var(&phoneNumber, (char *)"Phone Number", 10);
		if (i == 4)
			ask_for_var(&secret, (char *)"Secret", 50);
		i++;
	}
	if (Contact::index < 8)
		this->_contact[Contact::index] = Contact(f_name.c_str(), l_name.c_str(), nickname.c_str(), phoneNumber.c_str() ,secret.c_str());
	else
		this->_contact[7] = Contact(f_name.c_str(), l_name.c_str(), nickname.c_str(), phoneNumber.c_str(), secret.c_str());
	Contact::index += 1;
	std::cout << "Le contact a bien été enregistré !" << std::endl;
}

void PhoneBook::search_contact()
{
	unsigned int	i;

	i = 0;
	if (Contact::index == 0)
		std::cout << "There is no contact at the moment" << std::endl;
	while (i < Contact::index && i < 8)
	{
		this->_contact[i].print_contact(i);
		i++;
	}
}