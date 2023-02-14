#include <iostream>

int	main(int ac, char **av)
{
	int i = 1;
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (i < ac)
	{

		std::string	manip = av[i];  
		for (std::string::size_type j = 0; j < manip.size(); j++)
		{
			std::cout << static_cast<char>(std::toupper(manip[j]));
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
