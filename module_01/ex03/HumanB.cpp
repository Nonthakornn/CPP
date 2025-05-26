#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	:m_name(name)
	,m_weapon(nullptr)
{

};

HumanB::~HumanB(){};

void	HumanB::setWeapon(Weapon &weapon) {
	this->m_weapon = &weapon;
}

void HumanB::attack() {
	if (!m_weapon)
	{
		std::cout << "HumanB does not have any Weapon" << std::endl;
		return ;
	}
	std::cout << 
		m_name << " attacks with their " <<
		m_weapon->getType() << std::endl;
}
