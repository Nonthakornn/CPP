#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
private:
	std::string	_name;
	int			_hitPoint;
	int			_energyPoint;
	int			_attackDamage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(std::string name, int hitPoint, int energyPoint, int attackDamage);
	ClapTrap(ClapTrap &other);
	~ClapTrap();

	ClapTrap&	operator=(ClapTrap &rhs);
	void		attack(const std::string &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	std::string	get_name();
	int			get_hitPoint();
	int			get_energyPoint();
	int			get_attackDamage();
};

# endif