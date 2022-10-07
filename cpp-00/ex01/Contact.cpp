#include <iostream>
#include "Contact.hpp"

Contact::Contact()
{
	return ;
}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phoneNumber, std::string secret)
{
	this->_firstName = first_name;
	this->_lastName = last_name;
	this->_nickname = nickname;
	this->_phoneNumber = phoneNumber;
	this->_secret = secret;
	return ;
}

Contact::~Contact()
{
	return ;
}

std::string Contact::getFirstName()
{
	return this->_firstName;
}

std::string Contact::getLastName()
{
	return this->_lastName;
}

std::string Contact::getNickname()
{
	return this->_nickname;
}

std::string Contact::getPhoneNumber()
{
	return this->_phoneNumber;
}

std::string Contact::getSecret()
{
	return this->_secret;
}

void build_str_each_element(std::string str) {
	if (str.size() > 9)
	{
		str.resize(9);
		str.push_back('.');
		std::cout << str;
		return ;
	}
	int i = str.size();
	while (0 < 10-i)
	{
		std::cout << " ";
		i++;
	}
	std::cout << str;
}

void Contact::print_contact(int index)
{
	int space_to_add = 0;
	int copy_index = index;
	while (copy_index / 10 != 0)
	{
		space_to_add++;
		copy_index /= 10;
	}
	for (int i = 0; i < 10 - space_to_add; i++)
		std::cout << " ";
	std::cout << index << " | ";
	build_str_each_element(this->getFirstName());
	std::cout << " | ";
	build_str_each_element(this->getLastName());
	std::cout << " | ";
	build_str_each_element(this->getNickname());
	std::cout << "" << std::endl;
}

unsigned int Contact::index = 0;
