#include <iostream>
#include <vector>

struct Vertex {
	float x, y ,z;
};

std::ostream& operator<<(std::ostream & stream, const Vertex& vertex) {
	stream << vertex.x << "," << vertex.y << "," << vertex.z;
	return stream;
}

int main() {

	std::vector<Vertex> v;
	v.push_back({1,2,3});

	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << std::endl;
	}

}
