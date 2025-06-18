#include "FragTrap.hpp"

FlagTrap::FlagTrap()
	:ClapTrap()
{
	std::cout << " FlagTrap Inherit Default Constructor is called" << std::endl;
	std::cout << "Name: " << this->get_name() << std::endl;
	std::cout << "Hit Point: " << this->get_hitPoint()<< std::endl;
	std::cout << "Energy Point: " << this->get_energyPoint() << std::endl;
	std::cout << "Attack Damage: " << this->get_attackDamage() << std::endl;
	std::cout << std::endl;
}

FlagTrap::FlagTrap(FlagTrap &copy) {
	std::cout << "FlagTrap Copy constructor is called" << std::endl;
	*this = copy;
}

FlagTrap::FlagTrap(std::string name)
	:ClapTrap(name, 100, 100, 30)
{
	std::cout << "FlagTrap Inherit Parameter Constructor is called" << std::endl;
	std::cout << "Name: " << this->get_name() << std::endl;
	std::cout << "Hit Point: " << this->get_hitPoint()<< std::endl;
	std::cout << "Energy Point: " << this->get_energyPoint() << std::endl;
	std::cout << "Attack Damage: " << this->get_attackDamage() << std::endl;
	std::cout << std::endl;
}

FlagTrap::FlagTrap(std::string name, int hitPoint, int energyPoint, int attackDamage)
	:ClapTrap(name, hitPoint, energyPoint, attackDamage)
{
	std::cout << "FlagTrap Inherit Parameter Constructor is called" << std::endl;
	std::cout << "Name: " << this->get_name() << std::endl;
	std::cout << "Hit Point: " << this->get_hitPoint()<< std::endl;
	std::cout << "Energy Point: " << this->get_energyPoint() << std::endl;
	std::cout << "Attack Damage: " << this->get_attackDamage() << std::endl;
	std::cout << std::endl;
}

FlagTrap::~FlagTrap() {
	std::cout << "FlagTrap Inherit Destrcutor is called" << std::endl;
}

FlagTrap& FlagTrap::operator=(FlagTrap &rhs) {
	std::cout << "FlagTrap copy operator is called" << std::endl;
	if (this != &rhs)
	{
		this->get_name() = rhs.get_name();

	}
	return (*this);

}

void FlagTrap::highFivesGuys(void) {
	std::cout << this->get_name() << ": Wanna high five!?" << std::endl;
}