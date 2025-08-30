#include "iter.hpp"

int main()
{
	std::string arr[] = {"ONE", "TWO", "THREE"};
	int array_size = sizeof(arr) / sizeof(arr[0]) ;

	std::cout << "====== BEFORE ======" << std::endl;
	for (int i = 0; i < array_size; i++)
		std::cout << arr[i]  << std::endl;

	iter(arr, array_size, convert_to_ascii);

	std::cout << "====== AFTER ======" << std::endl;
	for (int i = 0; i < array_size; i++)
		std::cout << arr[i]  << std::endl;
}