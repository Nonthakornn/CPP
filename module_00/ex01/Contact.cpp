#include "Contact.hpp"

/*Initialize to empty string*/
Contact::Contact(): m_fname(""), m_lname(""), m_nick_name(""), m_secret("") {}

void	Contact::set_fname(std::string value) { m_fname = value; }

void	Contact::set_lname(std::string value) { m_lname = value; }

void	Contact::set_nickname(std::string value) { m_nick_name = value; }

void	Contact::set_phonenumber(std::string value) { m_phonenumber = value; }

void 	Contact::set_secret(std::string value) { m_secret = value; }

std::string Contact::get_fname() const { return this->m_fname; }

std::string	Contact::get_lname() const { return this->m_lname; }

std::string	Contact::get_nickname() const { return this->m_nick_name; }

std::string Contact::get_phonenumber() const { return this->m_phonenumber; }

std::string	Contact::get_secret() const { return this->m_secret; }
