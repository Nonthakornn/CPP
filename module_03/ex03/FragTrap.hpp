#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

# define ATKFLAG 30

class FragTrap: virtual public ClapTrap {
private:
public:
	FragTrap();
	FragTrap(const FragTrap &copy);
	FragTrap(std::string name);
	FragTrap(std::string name, int hitPoint, int energyPoint, int attackDamage);
	~FragTrap();

	FragTrap& operator=(const FragTrap &rhs);
	void attack(const std::string &target);
	void highFivesGuys(void);
};

#endif