#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie {
private:
	std::string m_name;

public:
	Zombie();
	~Zombie();
	void announce(void);
	void set_name(std::string name);
	/*
	- Use static for a member function when that function does not (and should not) operate on a specific object instance.
	— It doesn't use this or access instance (non-static) member
	- If you dont want to make it static just make it stand alone function.
	*/
	//static Zombie *zombieHorde(int N, std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif