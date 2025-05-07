#include "PhoneBook.hpp"

int main() {

	std::string option;
	PhoneBook phone_book;

	std::cout << "Phone Book Option:"<< std::endl;
	std::cout << "ADD:\tAdd new contact information."<< std::endl;
	std::cout << "SEARCH:\tDisplay saved contacts list."<< std::endl;
	std::cout << "EXIT:\tExit program.\n"<< std::endl;

	while (true) {
		std::cout << "Input your option> ";
		if (!std::getline(std::cin, option))
			break;
		if (option.empty())
			continue;
		else if (option == "ADD")
			phone_book.add_contact();
		else if (option == "SEARCH")
		{
			if (!phone_book.display_all_contact())
				continue;
			phone_book.display_specific_contact();
		}
		else if (option == "EXIT")
			break;
		else
			std::cout << "Option not found"<< std::endl;
	}
	std::cout << "Exit program..." << std::endl;
}
