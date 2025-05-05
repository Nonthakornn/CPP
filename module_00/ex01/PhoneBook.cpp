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
	int contact_size = 0;

	if (m_contact_size == 0)
	{
		std::cout << "There is no contact in the list!" << std::endl;
		return ;
	}
	if (m_contact_size > 8)
		contact_size = 8;
	else
		contact_size = m_contact_size;

	std::cout << std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nick Name" << "|"
		<< std::endl;

	for (int i = 0; i < contact_size; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		if (m_contact_list[i].get_fname().length() > 10)
			std::cout << std::setw(9) << m_contact_list[i].get_fname().substr(0,9) << ".|";
		else
			std::cout << std::setw(10) << m_contact_list[i].get_fname() << "|";

		if (m_contact_list[i].get_lname().length() > 10)
			std::cout << std::setw(9) << m_contact_list[i].get_lname().substr(0,9) << ".|"; 
		else
			std::cout << std::setw(10) << m_contact_list[i].get_lname() << "|";

		if (m_contact_list[i].get_nickname().length() > 10)
			std::cout << std::setw(9) << m_contact_list[i].get_nickname().substr(0,9) << ".|" << std::endl;
		else
			std::cout << std::setw(10) << m_contact_list[i].get_nickname() << "|" << std::endl;
	}
}

void	PhoneBook::display_specific_contact() const {};

/*
void	PhoneBook::display_all_contact() const {
    int contact_size = 0;

    if (m_contact_size == 0)
    {
        std::cout << "There is no contact in the list!" << std::endl;
        return ;
    }
    if (m_contact_size > 8)
        contact_size = 8;
    else
        contact_size = m_contact_size;

    std::cout << std::setw(10) << "Index" << "|"
        << std::setw(10) << "First Name" << "|"
        << std::setw(10) << "Last Name" << "|"
        << std::setw(10) << "Nick Name" << "|"
        << std::endl;

    for (int i = 0; i < contact_size; i++)
    {
        std::cout << std::setw(10) << i + 1 << "|";
        
        // Fix: Add the dot inside the string to maintain proper alignment
        std::string fname = m_contact_list[i].get_fname();
        if (fname.size() > 10)
            fname = fname.substr(0, 9) + ".";
        std::cout << std::setw(10) << fname << "|";
        
        // Fix: Add the dot inside the string to maintain proper alignment
        std::string lname = m_contact_list[i].get_lname();
        if (lname.size() > 10)
            lname = lname.substr(0, 9) + ".";
        std::cout << std::setw(10) << lname << "|";
        
        // Fix: Add the dot inside the string to maintain proper alignment
        std::string nickname = m_contact_list[i].get_nickname();
        if (nickname.size() > 10)
            nickname = nickname.substr(0, 9) + ".";
        std::cout << std::setw(10) << nickname << "|" << std::endl;
    }
}
*/

