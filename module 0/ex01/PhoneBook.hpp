#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int contactIdx = 0; // One way of having default values
	int contactCount = 0;

public:
	PhoneBook(/* args */);
	~PhoneBook();
	void AddContact(std::string fName, long phoneNumber, std::string lName,
					std::string nickName, std::string darkestSecret);
	void DisplayContacts();
	void PrintContact(int index);
	int  GetContactCount();
};



#endif