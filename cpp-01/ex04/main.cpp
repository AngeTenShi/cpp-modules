#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    std::string s1;
    std::string s2;
    std::string line;
    std::ifstream file;
    if (ac != 4)
        return (0);
    file.open(av[3]);
    s1 = av[1];
    s2 = av[2];
    if (!file)
        std::cout << "Can't open file" << std::endl;
    else
    {
        std::string filename = av[3];
        std::string ext = ".replace";
        std::size_t pos;
        filename += ext;
        std::ofstream output (filename.c_str());
        while (std::getline(file, line))
        {
            pos = line.find(s1);
            while (pos != std::string::npos)
            {
                line =  line.substr(0, pos) + s2 + line.substr(pos + s1.size());
                pos = line.find(s1);
            }
            line += '\n';
            output.write(line.c_str(), line.size());
        }
        file.close();
        output.close();
    }
    return (0);
}