#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
private:
	bool _gateStatus;
protected:
public:
	ScavTrap();
	ScavTrap(const ScavTrap &copy);
	ScavTrap(std::string name);
	ScavTrap(std::string name, int hitPoint, int energyPoint, int attackDamage);
	~ScavTrap();

	ScavTrap& operator=(const ScavTrap &rhs);
	void	attack(const std::string &target);
	void 	guardGate();
};

#endif