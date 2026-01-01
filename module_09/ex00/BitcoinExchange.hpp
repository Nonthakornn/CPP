#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib> 
#include <limits> 

class BitcoinExchange {
    private:
        std::map<std::string, float> _database;

        std::string _trim(const std::string& str);
        bool        _isValidDate(const std::string& date);
        bool        _isValidValue(const float& value);
        float       _getExchangeRate(const std::string& date);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange& operator=(const BitcoinExchange& src);
        ~BitcoinExchange();

        void    loadDatabase(const char* filename);
        void    processInput(const char* filename);

        class DatabaseException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Error: Could not open or parse database.";
                }
        };
};

#endif