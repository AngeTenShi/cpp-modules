#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char *filename)
{
    this->filename = filename;
    prepareDates();
    return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &other)
{
    this->filename = other.filename;
    prepareDates();
    return ;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &other)
{
    this->filename = other.filename;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    return ;
}

void    BitcoinExchange::prepareDates()
{
    std::ifstream datacsv("data.csv");
    if (!datacsv.is_open())
    {
        std::cout << "Error: can't open data.csv are you sure it's here !" << std::endl;
        return ;
    }
    std::string line;
    std::string date;
    std::string values;
    std::getline(datacsv, line); // pour sauter la premiere ligne
    while (std::getline(datacsv, line))
    {
        date = line.substr(0, line.find(','));
        values = line.substr(line.find(',') + 1);
        this->dates[date] = std::atof(values.c_str());
    }
}

int BitcoinExchange::parseLine(std::string line)
{
    std::string date;
    float values;
    std::string year;
    std::string month;
    std::string day;
    if (line.find('|') == std::string::npos || line.find('|') != line.rfind('|'))
    {
        std::cout << "Error : bad input => " << line << std::endl;
        return (0);
    }
    while (line.find(' ') != std::string::npos) // on enleve tous les espaces
        line.erase(line.find(' '), 1);
    date = line.substr(0, line.find('|'));
    values = std::atof(line.substr(line.find('|') + 1).c_str());
    if (date.find('-') == std::string::npos || date.find('-') == date.rfind('-'))
    {
        std::cout << "Error : bad date format => " << date << std::endl;
        return (0);
    }
    year = date.substr(0, date.find('-'));
    month = date.substr(date.find('-') + 1, date.rfind('-') - date.find('-') - 1);
    day = date.substr(date.rfind('-') + 1);
    if (year.length() != 4 || month.length() != 2 || day.length() != 2)
    {
        std::cout << "Invalid Format : Year-Month-Day" << std::endl;
        return (0);
    }
    else if (month > "12" || month < "01")
    {
        std::cout << "Error : Month must be between 01 and 12" << std::endl;
        return (0);
    }
    else if (day > "31" || day < "01")
    {
        std::cout << "Error : Day must be between 01 and 31" << std::endl;
        return (0);
    }
    else if (year < "2010" || year > "2023")
    {
        std::cout << "Error : Year must be between 2010 and 2023" << std::endl;
        return (0);
    }
    else if (values > 1000 || values < 0)
    {
        std::cout << "Error : value must be between 0 and 1000 => " << values << std::endl;
        return (0);
    }
    this->input_date = date;
    while ((this->dates.find(date) == this->dates.end()) && (year > "2009" || (year == "2009" && day > "02" && month > "01")))
    {
        std::stringstream convert;
        if (day == "01")
        {
            if (month == "01")
            {
                convert << std::atoi(year.c_str() - 1);
                year = convert.str();
                month = "12";
                day = "31";
            }
            else
            {
                convert << std::atoi(month.c_str()) - 1;
                if (month < "10")
                    month = "0" + convert.str();
                else
                    month = convert.str();
                day = "31";
            }
        }
        else
        {
            convert << std::atoi(day.c_str()) - 1;
            if (day < "10")
                day = "0" + convert.str();
            else
                day = convert.str();
        }
        date = year + "-" + month + "-" + day;
    }
    this->modified_date = date;
    this->input_value = values;
    return (1);
}

void BitcoinExchange::run()
{
    std::ifstream input(this->filename);
    if (!input.is_open())
    {
        std::cout << "Error: file can't be opened" << std::endl;
        return ;
    }
    std::string line;
    std::getline(input, line); // pour sauter la premiere ligne
    while (std::getline(input, line))
    {
        if (parseLine(line))
        {
            std::cout << this->input_date << " => " << this->input_value << " = " << this->input_value * this->dates[this->modified_date] << std::endl;
        }
    }
    return ;
}
