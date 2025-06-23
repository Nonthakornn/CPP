#include <iostream>
using namespace std;

class Student {
private:
public:
    string _name;
    int *_agePtr;
    
    Student() {
        _agePtr = nullptr;
    }
    
    Student(string name, int age) {
        this->_name = name;
        this->_agePtr = new int(age);
    }
    
    Student(const Student &copy) {
        cout << "Copy constructor is called" << endl;
        this->_name = copy._name;
        
        if (copy._agePtr != nullptr) {
            this->_agePtr = new int;
            *(this->_agePtr) = *(copy._agePtr); 
        } else {
            this->_agePtr = nullptr;
        }
    }
    
    ~Student() {
        cout << "Destructor Student" << endl;
        delete _agePtr; 
    }
    
    void display() {
        cout << "Name: " << this->_name << endl;
        cout << "Age Pointer: " << this->_agePtr << endl;  // Shows address
        if (_agePtr != nullptr) {
            cout << "Age Value: " << *this->_agePtr << endl;  // Shows value
        }
    }
};

int main() {
    Student s1("John", 25);  // Create student with age 25
    Student s2 = s1;         // Deep copy
    
    s1._name = "Peter";
    
    s1.display();
    s2.display();
    
    // Now you'll see DIFFERENT memory addresses!
    return 0;
}