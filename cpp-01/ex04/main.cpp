#include <iostream>
#include <fstream>

std::string replace(std::string begin, std::string to_find, std::string to_rep)
{
    std::size_t pos = begin.find(to_find);
    if (pos != std::string::npos)
        begin = begin.substr(0, pos) + to_rep + replace(begin.substr(pos + to_find.size()), to_find, to_rep);
    return (begin);
}

int main(int ac, char **av)
{
    std::string s1;
    std::string s2;
    std::string line;
    std::string input;
    std::ifstream file;
    if (ac != 4)
        return (0);
    file.open(av[1]);
    s1 = av[2];
    s2 = av[3];
    if (!file)
        std::cout << "Can't open file" << std::endl;
    else
    {
        std::string filename = av[1];
        std::string ext = ".replace";
        std::size_t pos;
        filename += ext;
        std::ofstream output (filename.c_str());
        while (std::getline(file, line))
        {
            input += line + '\n';
        }
        pos = input.find(s1);
        if (pos != std::string::npos)
            input =  input.substr(0, pos) + s2 + replace(input.substr(pos + s1.size()), s1, s2);
        output.write(input.c_str(), input.size());
        file.close();
        output.close();
    }
    return (0);
}