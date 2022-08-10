#include <iostream>

char	*to_upper(char *toModify)
{
	int	i;

	i = 0;
	while (toModify[i])
	{
		if (toModify[i] >= 'a' && toModify[i] <= 'z')
			toModify[i] -= 32;
		i++;
	}
	toModify[i] = '\0';
	return (toModify);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		argv++;
		while (*argv)
		{
			std::cout << to_upper(*argv);
			argv++;
		}
		std::cout << std::endl;
	}
	return (0);
}
