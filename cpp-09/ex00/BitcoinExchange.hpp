#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>
#include <sstream>

class BitcoinExchange
{
public:
    BitcoinExchange(char *filename);
    BitcoinExchange(BitcoinExchange &other);
    BitcoinExchange &operator=(BitcoinExchange &other);
    ~BitcoinExchange();
    void run();
    void prepareDates();
    int parseLine(std::string line);

private:
    char *filename;
    std::map<std::string, float> dates;
    std::string input_date;
    std::string modified_date;
    float input_value;
};