#include "PhoneBook.hpp"

/* Best Practice (Initialization list) */
PhoneBook::PhoneBook() : m_contact_size(0) {}

static std::string trim_space(std::string &info)
{
	size_t	first = 0;
	int last = info.size() - 1;
	std::string sub_str = "";

	while (first < info.size() && std::isspace(info[first]))
		first++;
	if (first == info.size())
		return "";
	while (std::isspace(info[last]))
		last--;
	sub_str = info.substr(first, last - first + 1);
	return sub_str;
}

static void assign_info(std::string prompt, std::string &info) {

	std::string trim_info;

	while (info.empty()) {
		std::cout << prompt;
		if (!getline(std::cin, info))
			exit(0);
		trim_info = trim_space(info);
		if (!trim_info.empty())
		{
			info = trim_info;
			break;
		}
		info.clear();
	}
}

void PhoneBook::add_contact() {
	Contact contact_info;
	std::string	fname;
	std::string	lname;
	std::string	nickname;
	std::string	phonenumber;
	std::string	secret;

	assign_info("Enter your Fisname: ", fname);
	assign_info("Enter your Lastname: ", lname);
	assign_info("Enter your Nickname: ", nickname);
	assign_info("Enter your Phone number: ", phonenumber);
	assign_info("Enter your Secret: ", secret);

	contact_info.set_fname(fname);
	contact_info.set_lname(lname);
	contact_info.set_nickname(nickname);
	contact_info.set_phonenumber(phonenumber);
	contact_info.set_secret(secret);

	this->m_contact_list[this->m_contact_size % 8] = contact_info;
	this->m_contact_size++;
}

void	PhoneBook::display_all_contact() const {
	Contact contact_info;
	std::cout << contact_info.get_fname() << std::endl;

}

// void	PhoneBook::display_specific_contact() const {};
