#include <iostream>

using namespace std;

class Animal {
public:
    virtual void speak() { cout << "Animal sound" << endl; }
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void speak() { cout << "Woof!" << endl; }
    void wagTail() { cout << "Wagging tail" << endl; }
};

// int main() {
//     Dog myDog;
    
//     // Upcasting - converting Dog* to Animal*
//     Animal* animalPtr = &myDog;  // Implicit upcast
    
//     // Polymorphic behavior - calls Dog's speak()
//     animalPtr->speak();  // Output: "Woof!"
    
//     // animalPtr->wagTail();  // ERROR - can't access Dog-specific methods
    
//     return 0;
// }

int main() 
{
	// Upcasting - converting Dog* to Animal*
	Animal *animalptr = new Dog();

	animalptr->speak();

	// ERROR - can't access Dog-specific methods
	// animalptr->wagTail();

}