#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public FragTrap,  public ScavTrap {
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &copy);
	~DiamondTrap();

	DiamondTrap& operator=(const DiamondTrap &rhs);
	void	attack(const std::string &target);
	void	whoAmI();
};

# endif