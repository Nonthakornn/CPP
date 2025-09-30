#include <map>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int main()
{
	{
		std::map<std::string, int> hash;

		//c++20
		// hash.insert({"Alice", 30});

		hash["Aice"] = 30;
		hash["Bob"] = 31;

		// hash.insert(std::pair<std::string,int>("Boy", 12));

		//make_pair does not need to cast a type
		hash.insert(std::make_pair("Boy", 12));

		for (std::map<std::string, int>::iterator it = hash.begin(); it != hash.end(); ++it)
		{
			std::cout << it->first << ": " << it->second << std::endl;
		}
	}

	{
		// std::unordered_map<std::string, int> un_map;
		// un_map = {{"A",0}, {"B", 1}};

		std::unordered_map<int, int> un_map;
		un_map = {{1,1}, {2,2}};

		std::cout << un_map[1] << std::endl;
		un_map.contains(1);

		// for (const auto &ele: un_map)
		// 	std::cout << ele.first << std::endl;
	}
}