#include "ClapTrap.hpp"

// Constructor
ClapTrap::ClapTrap()
	:_name("Default Robot")
	,_hitPoint(10)
	,_energyPoint(10)
	,_attackDamage(0)
{
	std::cout << "Default constructor is called" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit Point: " << this->_hitPoint << std::endl;
	std::cout << "Energy Point: " << this->_energyPoint << std::endl;
	std::cout << "Attack Damage: " << this->_attackDamage << std::endl;
	std::cout << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	:_name(name)
	,_hitPoint(10)
	,_energyPoint(10)
	,_attackDamage(0)
{
	std::cout << "Parameter constructor is called" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit Point: " << this->_hitPoint << std::endl;
	std::cout << "Energy Point: " << this->_energyPoint << std::endl;
	std::cout << "Attack Damage: " << this->_attackDamage << std::endl;
	std::cout << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hitPoint, int energyPoint, int attackDamage)
	:_name(name)
	,_hitPoint(hitPoint)
	,_energyPoint(energyPoint)
	,_attackDamage(attackDamage)
{
	std::cout << "Parameter constructor is called" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit Point: " << this->_hitPoint << std::endl;
	std::cout << "Energy Point: " << this->_energyPoint << std::endl;
	std::cout << "Attack Damage: " << this->_attackDamage << std::endl;
	std::cout << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &other) {
	std::cout << "Copy constructor is called" << std::endl;
	*this = other;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit Point: " << this->_hitPoint << std::endl;
	std::cout << "Energy Point: " << this->_energyPoint << std::endl;
	std::cout << "Attack Damage: " << this->_attackDamage << std::endl;
	std::cout << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap &rhs) {
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor is called" << std::endl;
}

//Get-Set
std::string ClapTrap::get_name() { return (this->_name); }

int ClapTrap::get_hitPoint() { return (this->_hitPoint); }

int ClapTrap::get_energyPoint() { return (this->_energyPoint); }

int ClapTrap::get_attackDamage() { return (this->_attackDamage); }

// Method
void ClapTrap::attack(const std::string &target)
{
	if (this->get_hitPoint() == 0 || this->get_energyPoint() == 0) 
	{
		std::cout << this->get_name() << " has no hitPoint or Energy left: " << std::endl;
		std::cout << "hitPoint: " << this->get_hitPoint() << " Energy: " << this->get_energyPoint() << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->get_name() << " attacks " << target << ", causing " << this->get_attackDamage() << " points of damage!" << std::endl;
	std::cout << "(Energy " << this->get_energyPoint() << " ==> "; 
	this->_energyPoint -= 1;
	std::cout << "" << this->get_energyPoint() << ")" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->get_hitPoint() <= 0 || this->get_energyPoint() <= 0) 
	{
		std::cout << this->get_name() << " has no hitPoint or Energy left: " << std::endl;
		std::cout << "hitPoint: " << this->get_hitPoint() << " Energy: " << this->get_energyPoint() << std::endl;
		return ;
	}
	std::cout << this->get_name() << " has taken damage"  << std::endl;
	std::cout << "(Hit Point " << this->get_hitPoint() << " ==> "; 
	this->_hitPoint -= amount;
	std::cout << "" << this->get_hitPoint() << ")" << std::endl;

	std::cout << "(Energy " << this->get_energyPoint() << " ==> "; 
	this->_energyPoint -= 1;
	std::cout << "" << this->get_energyPoint() << ")" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->get_hitPoint() <= 0 || this->get_energyPoint() <= 0) 
	{
		std::cout << this->get_name() << " has no hitPoint or Energy left: " << std::endl;
		std::cout << "hitPoint: " << this->get_hitPoint() << " Energy: " << this->get_energyPoint() << std::endl;
		return ;
	}
	std::cout << this->get_name() << " has been repaired"  << std::endl;
	std::cout << "(Hit Point " << this->get_hitPoint() << " ==> "; 
	this->_hitPoint += amount;
	std::cout << "" << this->get_hitPoint() << ")" << std::endl;

	std::cout << "(Energy " << this->get_energyPoint() << " ==> "; 
	this->_energyPoint -= 1;
	std::cout << "" << this->get_energyPoint() << ")" << std::endl;
}
