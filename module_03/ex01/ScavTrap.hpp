#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
private:
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(std::string name, int hitPoint, int energyPoint, int attackDamage);
	~ScavTrap();
	void guardGate();
};

#endif