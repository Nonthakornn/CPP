#include <map> //Sorted
#include <iostream>
#include <vector>
#include <stdint.h>

struct CityRecord {
	std::string name;
	uint64_t Population;
	double Latitude, Longitude;

	CityRecord() : name(""), Population(0), Latitude(0.0), Longitude(0.0) {}
	CityRecord(const std::string& n, uint64_t p, double lat, double lon)
		: name(n), Population(p), Latitude(lat), Longitude(lon) {}
};

int main() {

	/*
	Using a vector for this is bad
	std::vector<CityRecord> cities;

	// cities.emplace_back("Bangkok", 500000, 2.4, 9.5); C++11
	cities.push_back(CityRecord("A", 500000, 2.4, 9.5));
	cities.push_back(CityRecord("B", 500000, 2.4, 9.5));
	cities.push_back(CityRecord("C", 500000, 2.4, 9.5));
	cities.push_back(CityRecord("D", 500000, 2.4, 9.5));

	for (auto &city: cities) {
		if (city.name == "A")
		{
			city.Population;
			std::cout << city.Population << std::endl;
			break;
		}
	}
	*/

	std::map<std::string, CityRecord> cityMap;

	// For c++20
	// cityMap["A"] = CityRecord{"A", 50000, 2.4, 9.4};


	cityMap["A"] = CityRecord("A", 50000, 2.4, 9.4);
	cityMap["B"] = CityRecord ("B", 50000, 2.4, 9.4);
	cityMap["C"] = CityRecord ("C", 50000, 2.4, 9.4);

	CityRecord& AData = cityMap["A"];
	std::cout << AData.Population << std::endl;
}
