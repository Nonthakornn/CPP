#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

class FlagTrap: public ClapTrap {
private:
public:
	FlagTrap();
	FlagTrap(const FlagTrap &copy);
	FlagTrap(std::string name);
	FlagTrap(std::string name, int hitPoint, int energyPoint, int attackDamage);
	~FlagTrap();

	FlagTrap& operator=(FlagTrap &rhs);
	void highFivesGuys(void);
};

#endif