#include <iostream>

class Base
{
public:
    Base() { }

    virtual void identify() const { std::cout << "Base::identify()\n"; }
};

class Derived: public Base
{
public:
    Derived() { }

    void identify() const { std::cout << "Derived::identify()\n"; }
};


int main() {
    Base base_obj;
    Derived derived_obj;
    
    Base& base_ref = base_obj;
    Base& derived_ref = derived_obj;  // Reference to Derived as Base
    
    base_ref.identify();     // Base::identify()
    derived_ref.identify();  // Derived::identify()
    
    return 0;
}

/*
int main()
{
    Base base  = Base();
    base.identify();

    Base derived = Derived();
    derived.identify();

	// delete base;
	// delete derived;

    return 0;
}
*/