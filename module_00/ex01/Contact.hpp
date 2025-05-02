#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <cstdlib>

class Contact {
private:
	std::string	m_fname;
	std::string	m_lname;
	std::string	m_nick_name;
	std::string m_phonenumber;
	std::string	m_secret;

public:
	Contact();
	void	set_fname(std::string value);
	void	set_lname(std::string value);
	void	set_nickname(std::string value);
	void	set_phonenumber(std::string value);
	void	set_secret(std::string value);

	std::string get_fname() const;
	std::string	get_lname() const;
	std::string	get_nickname() const;
	std::string get_phonenumber() const;
	std::string	get_secret() const;
};

#endif
