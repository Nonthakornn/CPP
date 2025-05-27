#include <iostream>
#include <fstream>
#include <string>

/*
std::ifstream - Reads from files
std::ofstream - Creates and write to file
std::fstream - Creates read and writes to file
*/

bool checkfile(std::ifstream *infile, std::ofstream *outfile)
{
	if (!infile->is_open()) {
		std::cerr << "Error Opening infile" << std::endl;
		return (false);
	}
	if (!outfile->is_open())
	{
		std::cerr << "Error Opening outfile" << std::endl;
		return (false);
	}
	return (true);
}

std::string replace_string(std::string &line, std::string &from , std::string &to)
{
	std::string	result;
	size_t pos = 0;
	size_t found = 0;

	//find(string that you want to find, starting_position)
	//substr(start index, n char that you want)
	while ((found = line.find(from, pos)) != std::string::npos)
	{
		result.append(line.substr(pos, found - pos));
		result.append(to);
		pos = found + from.length();
		std::cout << pos << std::endl;
	}
	result.append(line.substr(pos));
	return (result);
}

int main(int ac , char **av)
{
	if (ac != 4)
		return (std::cerr << "Error Input" << std::endl, EXIT_FAILURE);
	
	std::string		line;
	std::string		replace_line;
	std::ifstream	infile(av[1]);
	std::string 	str1(av[2]);
	std::string 	str2(av[3]);
	std::string		replace_file = std::string(av[1]) + ".replace";
	std::ofstream	outfile(replace_file);

	if (str1.empty() || str2.empty())
		return (std::cerr << "Error Input (Empty string)" << std::endl, EXIT_FAILURE);
	if (!checkfile(&infile, &outfile))
		return (EXIT_FAILURE);
	bool firstline = true;
	while (std::getline(infile, line))
	{
		if (!firstline)
			outfile << std::endl;
		else
			firstline = false;
		replace_line = replace_string(line, str1, str2);
		outfile << replace_line;
	}
	outfile.close();
	infile.close();
	return (EXIT_SUCCESS);
}
