#include "Contact.hpp"

/*Initialize to empty string*/
Contact::Contact(): m_fname(""), m_lname(""), m_nick_name(""), m_secret("") {};

void	Contact::set_fname(std::string value) {};
void	Contact::set_lname(std::string value) {};
void	Contact::set_nickname(std::string value) {};
void	Contact::set_secret(std::string value) {};

std::string Contact::get_fname() const {};
std::string	Contact::get_lname() const {};
std::string	Contact::get_nickname() const {};
std::string	Contact::get_secret() const {};