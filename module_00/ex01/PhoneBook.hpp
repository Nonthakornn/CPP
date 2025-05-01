#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"

class PhoneBook {
private:
	int		m_contact_size;
	Contact	m_contact_list[8];

public:
	PhoneBook();
	void	add_contact();
	void	display_all_contact() const;
	void	display_specific_contact() const;
};

#endif