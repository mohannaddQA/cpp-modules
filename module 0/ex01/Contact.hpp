#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>

class Contact
{
private:
	/* data */
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string darkestSecret;
	long phoneNumber;

public:
	Contact();
	Contact(/* args */ std::string fName, long phoneNumber, std::string lName,
			std::string nickName, std::string darkestSecret);
	~Contact();
	void AddContactInfo(std::string fName, long phoneNumber, std::string lName,
						std::string nickName, std::string darkestSecret);
	void PrintContactInfo(void);
	std::string GetFirstName(void);
	std::string GetLastName(void);
	std::string GetNickName(void);
};

#endif
