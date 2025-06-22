#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Inherit Default Constructor is called" << std::endl;
	std::cout << "Name: " << this->get_name() << std::endl;
	std::cout << "Hit Point: " << this->get_hitPoint()<< std::endl;
	std::cout << "Energy Point: " << this->get_energyPoint() << std::endl;
	std::cout << "Attack Damage: " << this->get_attackDamage() << std::endl;
	std::cout << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) 
{
	*this = copy;
	std::cout << "FragTrap Copy constructor is called" << std::endl;
	std::cout << "Name: " << this->get_name() << std::endl;
	std::cout << "Hit Point: " << this->get_hitPoint()<< std::endl;
	std::cout << "Energy Point: " << this->get_energyPoint() << std::endl;
	std::cout << "Attack Damage: " << this->get_attackDamage() << std::endl;
}

FragTrap::FragTrap(std::string name)
	:ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap Inherit Parameter Constructor is called" << std::endl;
	std::cout << "Name: " << this->get_name() << std::endl;
	std::cout << "Hit Point: " << this->get_hitPoint()<< std::endl;
	std::cout << "Energy Point: " << this->get_energyPoint() << std::endl;
	std::cout << "Attack Damage: " << this->get_attackDamage() << std::endl;
	std::cout << std::endl;
}

FragTrap::FragTrap(std::string name, int hitPoint, int energyPoint, int attackDamage)
	:ClapTrap(name, hitPoint, energyPoint, attackDamage)
{
	std::cout << "FragTrap Inherit Parameter Constructor is called" << std::endl;
	std::cout << "Name: " << this->get_name() << std::endl;
	std::cout << "Hit Point: " << this->get_hitPoint()<< std::endl;
	std::cout << "Energy Point: " << this->get_energyPoint() << std::endl;
	std::cout << "Attack Damage: " << this->get_attackDamage() << std::endl;
	std::cout << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << this->_name << " (FragTrap) Destrcutor is called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &rhs) {
	std::cout << "FragTrap copy operator is called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

void FragTrap::attack(const std::string &target) {

	if (this->get_hitPoint() <= 0 || this->get_energyPoint() <= 0) 
	{
		std::cout << this->get_name() << " has no hitPoint or Energy left: " << std::endl;
		std::cout << "hitPoint: " << this->get_hitPoint() << " Energy: " << this->get_energyPoint() << std::endl;
		return ;
	}
	std::cout << "(Call FragTrap method) " << this->get_name() << " attacks " << target << ", causing " << this->get_attackDamage() << " points of damage!" << std::endl;
	std::cout << "(Energy " << this->get_energyPoint() << " ==> "; 
	this->_energyPoint -= 1;
	std::cout << "" << this->get_energyPoint() << ")" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	if (this->get_hitPoint() <= 0 || this->get_energyPoint() <= 0) 
	{
		std::cout << this->get_name() << " has no hitPoint or Energy left: " << std::endl;
		std::cout << "hitPoint: " << this->get_hitPoint() << " Energy: " << this->get_energyPoint() << std::endl;
		return ;
	}
	std::cout << this->get_name() << ": Wanna high five!?" << std::endl;
}