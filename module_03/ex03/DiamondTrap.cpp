#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	:ClapTrap("Defatult_clap_name")
{
	this->_name = "DTrap Default";
	this->_hitPoint = FragTrap::_hitPoint;
	this->_energyPoint = ScavTrap::_energyPoint;
	this->_attackDamage = ATKFLAG;
	std::cout << "DiamondTrap Constructor is called" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit Point: " << this->_hitPoint << std::endl;
	std::cout << "Energy Point: " << this->_energyPoint << std::endl;
	std::cout << "Attack Damage: " << this->_attackDamage << std::endl;
	std::cout << std::endl;
}
DiamondTrap::DiamondTrap(const std::string &name)
	:ClapTrap(name + "_clap_trap")
{
	this->_name = name ;
	this->_hitPoint = FragTrap::_hitPoint;
	this->_energyPoint = ScavTrap::_energyPoint;
	this->_attackDamage = ATKFLAG;
	std::cout << "DiamondTrap Parameter Constructor is called" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit Point: " << this->_hitPoint << std::endl;
	std::cout << "Energy Point: " << this->_energyPoint << std::endl;
	std::cout << "Attack Damage: " << this->_attackDamage << std::endl;
	std::cout << std::endl;

}
DiamondTrap::DiamondTrap(const DiamondTrap &copy) {
	*this = copy;
	std::cout << "DiamondTrap copy constructor is called" << std::endl;
	std::cout << "Name: " << this->get_name() << std::endl;
	std::cout << "Hit Point: " << this->get_hitPoint()<< std::endl;
	std::cout << "Energy Point: " << this->get_energyPoint() << std::endl;
	std::cout << "Attack Damage: " << this->get_attackDamage() << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &rhs) {
	std::cout << "DiamondTrap copy operator is called" << std::endl;
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << this->_name << " (DiamondTrap) Destructor is called" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
	// FragTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "Diamond: " << this->_name << std::endl;
	std::cout << "ClapTrap: " << ClapTrap::_name << std::endl;
}
