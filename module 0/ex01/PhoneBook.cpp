
#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

static std::string FormatField(std::string text)
{
	if (text.length() > 10)
		text = text.substr(0, 9) + ".";
	return (text);
}

PhoneBook::PhoneBook(/* args */)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::AddContact(std::string fName, long phoneNumber,
						   std::string lName, std::string nickName, std::string darkestSecret)
{
	contacts[contactIdx].AddContactInfo(fName, phoneNumber, lName, nickName,
										darkestSecret);
	contactIdx++;
	if (contactIdx == 8)
		contactIdx = 0;
	if (contactCount < 8)
		contactCount++;
}

void PhoneBook::DisplayContacts()
{
	int index;

	if (contactCount == 0)
	{
		std::cout << "No contacts saved" << std::endl;
		return;
	}
	std::cout << std::setw(10) << "index"
			  << "|";
	std::cout << std::setw(10) << "first name"
			  << "|";
	std::cout << std::setw(10) << "last name"
			  << "|";
	std::cout << std::setw(10) << "nickname" << std::endl;
	index = 0;
	while (index < contactCount)
	{
		std::cout << std::setw(10) << index << "|";
		std::cout << std::setw(10) << FormatField(contacts[index].GetFirstName()) << "|";
		std::cout << std::setw(10) << FormatField(contacts[index].GetLastName()) << "|";
		std::cout << std::setw(10) << FormatField(contacts[index].GetNickName()) << std::endl;
		index++;
	}

}

void PhoneBook::PrintContact(int index)
{
	contacts[index].PrintContactInfo();
}

int PhoneBook::GetContactCount()
{
	return (contactCount);
}
