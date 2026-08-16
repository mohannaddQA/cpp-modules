
#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(std::string fName, long phoneNumber, std::string lName,
	std::string nickName, std::string darkestSecret)
{
	firstName = fName;
	lastName = lName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
	this->nickName = nickName;
}

void Contact::AddContactInfo(std::string fName, long phoneNumber,
	std::string lName, std::string nickName, std::string darkestSecret)
{
	firstName = fName;
	lastName = lName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
	this->nickName = nickName;
}

void Contact::PrintContactInfo(void)
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickName << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}

std::string Contact::GetFirstName(void)
{
	return (firstName);
}

std::string Contact::GetLastName(void)
{
	return (lastName);
}

std::string Contact::GetNickName(void)
{
	return (nickName);
}

Contact::~Contact()
{
}
