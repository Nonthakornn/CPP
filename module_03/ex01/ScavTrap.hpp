#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
private:
	bool _gateStatus;
protected:
public:
	ScavTrap();
	ScavTrap(const ScavTrap &copy);
	ScavTrap(std::string name);
	ScavTrap(std::string name, int hitPoint, int energyPoint, int attackDamage);
	ScavTrap& operator=(const ScavTrap &rhs);
	~ScavTrap();
	void guardGate();
};

#endif