#include "Serializer.hpp"

int main() {
	Data myData;
	myData.s1 = "String1";
	myData.n = 100;
	myData.s2 = "String2";

	// Create a pointer to the object
	Data* originalPtr = &myData;

	std::cout << "Original Pointer Address: " << originalPtr << std::endl;
	std::cout << "Original Data: s1=\"" << originalPtr->s1 << "\", n=" << originalPtr->n << ", s2=\"" << originalPtr->s2 << "\"" << std::endl;
	std::cout << "------------------------------------------" << std::endl;

	// Serialize the pointer (Convert memory address of object to uintptr_t)
	uintptr_t serializedValue = Serializer::serialize(originalPtr);
	std::cout << "Address of Serialized to uintptr_t:  " << &serializedValue << std::endl;
	std::cout << "Value of Serialized to uintptr_t:  " << serializedValue << std::endl;

	std::cout << "------------------------------------------" << std::endl;
	// Deserialize it back to a pointer (Convert memory of unitptr_t back Data*)
	Data* deserializedPtr = Serializer::deserialize(serializedValue);
	std::cout << "Address of Deserialized Pointer:     " << &deserializedPtr << std::endl;
	std::cout << "Value of Deserialized Pointer:     " << deserializedPtr << std::endl;
	std::cout << "------------------------------------------" << std::endl;

	// Check if the pointers are equal and access data
	if (deserializedPtr == originalPtr) {
		std::cout << "Success: Pointers are the same." << std::endl;
		std::cout << "Address of deserializedPtr: " << deserializedPtr << std::endl;
		std::cout << "Address of originalPrt: " << originalPtr << std::endl;
		std::cout << "Data via Deserialized Ptr: s1=\"" << deserializedPtr->s1 << "\", n=" << deserializedPtr->n << ", s2=\"" << deserializedPtr->s2 << "\"" << std::endl;
	} else {
		std::cout << "Fail: Pointers are different." << std::endl;
	}

	return 0;
}