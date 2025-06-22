#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	:ClapTrap()
{
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	this->_gateStatus = false;

	std::cout << "ScavTrap Inherit Default Constructor is called (Overide)" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Hit Point: " << this->_hitPoint << std::endl;
	std::cout << "Energy Point: " << this->_energyPoint << std::endl;
	std::cout << "Attack Damage: " << this->_attackDamage<< std::endl;
	std::cout << "Gate Status: " << this->_gateStatus << std::endl;
	std::cout << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &copy)
	:ClapTrap(copy) //Copy from base class
	,_gateStatus(copy._gateStatus)
{
	std::cout << "Gate Status: " << this->_gateStatus << std::endl;
	std::cout << "ScavTrap Copy Constructor is called" << std::endl;
	std::cout << "ALL copying is done! Object is fully constructed with copied values" << std::endl;
	std::cout << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	:ClapTrap(name, 100, 50, 20)
{
	this->_gateStatus = false;

	std::cout << "ScavTrap Inherit Parameter Constructor is called (Direct initialization)" << std::endl;
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
	std::cout << "Scav Trap Destrcutor is called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &rhs) {
	std::cout << "ScavTrap assignment operator is called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_energyPoint = rhs._energyPoint;
		this->_attackDamage = rhs._attackDamage;
		this->_gateStatus = rhs._gateStatus;
	}
	return (*this);
}

void ScavTrap::attack(const std::string &target) {

	if (this->get_hitPoint() == 0 || this->get_energyPoint() == 0) 
	{
		std::cout << this->get_name() << " has no hitPoint or Energy left: " << std::endl;
		std::cout << "hitPoint: " << this->get_hitPoint() << " Energy: " << this->get_energyPoint() << std::endl;
		return ;
	}
	std::cout << "(Call ScavTrap method) " << this->get_name() << " attacks " << target << ", causing " << this->get_attackDamage() << " points of damage!" << std::endl;
	std::cout << "(Energy " << this->get_energyPoint() << " ==> "; 
	this->_energyPoint -= 1;
	std::cout << "" << this->get_energyPoint() << ")" << std::endl;

}

void ScavTrap::guardGate() {
	if (this->get_hitPoint() == 0 || this->get_energyPoint() == 0) 
	{
		std::cout << this->get_name() << " has no hitPoint or Energy left: " << std::endl;
		std::cout << "hitPoint: " << this->get_hitPoint() << " Energy: " << this->get_energyPoint() << std::endl;
		return ;
	}
	if (this->_gateStatus == false)
	{
		this->_gateStatus = true;
		std::cout << this->get_name() << ": "<< "ScavTrap is now in Gate keeper mode" << std::endl;
	}
	else
		std::cout << this->get_name() << ": "<< "ScavTrap is already in Gate keeper mode" << std::endl;
}
