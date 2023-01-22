#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

class Contact {
public:

	 Contact();
	 Contact(std::string first_name, std::string last_name, std::string nickname, std::string phoneNumber, std::string secret);
	 ~Contact();

	 void	print_contact(int index);
	 std::string getFirstName();
	 std::string getLastName();
	 std::string getNickname();
	 std::string getPhoneNumber();
	 std::string getSecret();
	 static unsigned int index;
private:
	 std::string _firstName;
	 std::string _lastName;
	 std::string _nickname;
	 std::string _phoneNumber;
	 std::string _secret;
};

#endif