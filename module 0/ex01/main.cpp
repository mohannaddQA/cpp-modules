
#include "PhoneBook.hpp"
#include <iostream>

std::string takeInputLoop(void)
{
	std::string cmd;
	std::cout << "Type a command (ADD, SEARCH or EXIT):" << std::endl;
	std::getline(std::cin, cmd);
	while (cmd != "ADD" && cmd != "SEARCH" && cmd != "EXIT")
	{
		std::cout << "Please type only one of the allowed commands: ADD, SEARCH or EXIT " << std::endl;
		std::getline(std::cin, cmd);
	}
	return (cmd);
}

int handleAddCmd(PhoneBook &pb)
{
	std::string fName = "";
	std::string lName = "";
	std::string nickName = "";
	std::string darkestSec = "";
	long phoneNum = -1;

	while (fName == "")
	{
		std::cout << "Enter Contact first name:" << std::endl;
		std::getline(std::cin, fName);
	}

	while (lName == "")
	{
		std::cout << "Enter Contact last name:" << std::endl;
		std::getline(std::cin, lName);
	}

	while (nickName == "")
	{
		std::cout << "Enter Contact nickname:" << std::endl;
		std::getline(std::cin, nickName);
	}

	while (darkestSec == "")
	{
		std::cout << "Enter Contact darkest secret:" << std::endl;
		std::getline(std::cin, darkestSec);
	}

	std::string phoneStr = "";
	while (phoneStr == "")
	{
		std::cout << "Enter Contact phone number (digits only):" << std::endl;
		std::getline(std::cin, phoneStr);
		for (size_t i = 0; i < phoneStr.length(); ++i)
		{
			if (!isdigit(phoneStr[i]))
			{
				std::cout << "Phone must contain digits only. Try again." << std::endl;
				phoneStr = "";
				break;
			}
		}
	}

	try
	{
		phoneNum = std::stol(phoneStr);
	}
	catch (...)
	{
		std::cout << "Error: Failed to save the contact" << std::endl;
		return 1;
	}

	pb.AddContact(fName, phoneNum, lName, nickName, darkestSec);
	std::cout << "Contact Added" << std::endl;
	return 0;
}

void handleUserInput(PhoneBook &pb, const std::string &cmd)
{
	if (cmd == "ADD")
	{
		handleAddCmd(pb);
		return;
	}
	if (cmd == "SEARCH")
	{
		pb.DisplayContacts();
		int count = pb.GetContactCount();
		if (count == 0)
			return;
		std::string input;
		int selected = -1;
		while (selected < 0 || selected >= count)
		{
			std::cout << "Enter index to display contact info:" << std::endl;
			std::getline(std::cin, input);
			try
			{
				selected = std::stoi(input);
				if (selected < 0 || selected >= count)
					std::cout << "Invalid index. Please enter a valid index." << std::endl;
			}
			catch (...)
			{
				std::cout << "Invalid input. Please enter a valid index." << std::endl;
			}
		}
		pb.PrintContact(selected);
		return;
	}
}

int main(void)
{
	PhoneBook myPhoneBook;
	std::string cmd;

	while (true)
	{
		cmd = takeInputLoop();
		if (cmd == "EXIT")
			break;
		handleUserInput(myPhoneBook, cmd);
	}
	return (0);
}