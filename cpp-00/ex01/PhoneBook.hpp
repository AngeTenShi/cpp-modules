#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H
#include "Contact.hpp"

class PhoneBook {
public:

	 PhoneBook(void);
	 ~PhoneBook(void);

	 void	add_contact();
	 void	search_contact();

private:
	 Contact _contact[8];

};

#endif