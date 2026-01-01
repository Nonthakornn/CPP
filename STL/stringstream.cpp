#include <iostream>
#include <sstream>
#include <typeinfo>

int main() {
	std::stringstream ss;
	std::string strbuffer = "Hello World";

	ss <<  strbuffer;
	std::cout << ss.str() << std::endl;

	std::string chunk;
	while (ss >> chunk) {
		std::cout << "Chunk: " << chunk << std::endl;
		std::cout << ss.tellg() << std::endl;
	}
	ss.clear();

	ss << " Another one";
	std::cout << ss.str() << std::endl;

}

