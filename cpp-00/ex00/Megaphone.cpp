#include <iostream>

int	main(int ac, char **av)
{
	int i = 1;
	int j = 0;

	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (av[i])
	{
		while (av[i][j])
		{
			if (i == ac - 1)
			{
				std::cout << (char) std::toupper(av[i][j]);
				if (!av[i][j + 1])
					std::cout << (char) std::toupper(av[i][j]) << std::endl;
			}
			else
				std::cout << (char) std::toupper(av[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}