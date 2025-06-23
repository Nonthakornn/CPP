#include <iostream>
using namespace std;

class Student {
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
    
    // SHALLOW COPY constructor
    Student(const Student &copy) {
        cout << "SHALLOW Copy constructor is called" << endl;
        this->_name = copy._name;
        this->_agePtr = copy._agePtr;  // ❌ Just copy the pointer address!
    }
    
    ~Student() {
        cout << "Destructor for " << _name << endl;
        delete _agePtr;  // ⚠️ This will cause double deletion!
    }
    
    void display() {
        cout << "Name: " << _name << endl;
        cout << "Age Pointer: " << _agePtr << endl;
        if (_agePtr != nullptr) {
            cout << "Age Value: " << *_agePtr << endl;
        }
        cout << "---" << endl;
    }
    
    void changeAge(int newAge) {
        if (_agePtr != nullptr) {
            *_agePtr = newAge;
        }
    }
};

int main() {
    cout << "=== SHALLOW COPY EXAMPLE ===" << endl;
    
    Student s1("John", 25);
    Student s2 = s1;  // Shallow copy
    
    cout << "\nInitial state:" << endl;
    s1.display();
    s2.display();
    
    cout << "\nChanging s1's age to 30..." << endl;
    s1.changeAge(30);
    
    cout << "\nAfter changing s1's age:" << endl;
    s1.display();
    s2.display();  // ⚠️ s2's age also changed!
    
    cout << "\nProgram ending (destructors will run)..." << endl;
    // ⚠️ Program will likely crash due to double deletion!
    
    return 0;
}