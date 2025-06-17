#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "Inherit Default Constructor is called" << std::endl;
	std::cout << "Name: " << this->get_name() << std::endl;
	std::cout << "Hit Point: " << this->get_hitPoint()<< std::endl;
	std::cout << "Energy Point: " << this->get_energyPoint() << std::endl;
	std::cout << "Attack Damage: " << this->get_attackDamage() << std::endl;
	std::cout << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	:ClapTrap(name, 100, 50, 20)
{
	std::cout << "Inherit Parameter Constructor is called" << std::endl;
	std::cout << "Name: " << this->get_name() << std::endl;
	std::cout << "Hit Point: " << this->get_hitPoint()<< std::endl;
	std::cout << "Energy Point: " << this->get_energyPoint() << std::endl;
	std::cout << "Attack Damage: " << this->get_attackDamage() << std::endl;
	std::cout << std::endl;
}
ScavTrap:: ScavTrap(std::string name, int hitPoint, int energyPoint, int attackDamage)
	:ClapTrap(name, hitPoint, energyPoint, attackDamage)
{
	std::cout << "Inherit Parameter Constructor is called" << std::endl;
	std::cout << "Name: " << this->get_name() << std::endl;
	std::cout << "Hit Point: " << this->get_hitPoint()<< std::endl;
	std::cout << "Energy Point: " << this->get_energyPoint() << std::endl;
	std::cout << "Attack Damage: " << this->get_attackDamage() << std::endl;
	std::cout << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "Inherit Destrcutor is called" << std::endl;
}

void ScavTrap::guardGate() {
	if (this->get_hitPoint() == 0 || this->get_energyPoint() == 0) 
	{
		std::cout << this->get_name() << " has no hitPoint or Energy left: " << std::endl;
		std::cout << "hitPoint: " << this->get_hitPoint() << " Energy: " << this->get_energyPoint() << std::endl;
		return ;
	}
	std::cout << this->get_name() << ": "<< "ScavTrap is now in Gate keeper mode" << std::endl;
}