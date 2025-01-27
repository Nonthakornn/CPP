#include <iostream>  // for std::cout and std::cin

int main()
{
    std::cout << "Enter two numbers: ";

    int x;
    int y;
    int z;
    std::cin >> x;
    std::cin >> y;
    std::cin >> z;

	std::cout << "You entered " << x << ", " << y << ", and " << z << ".\n";
    return 0;
}