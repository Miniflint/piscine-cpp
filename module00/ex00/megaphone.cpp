#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		argv++;
		while (*argv)
		{
			std::string str = *argv;
			std::cout << std::uppercase << str << std::endl;
			argv++;
		}
		std::cout << std::endl;
	}
}
/*

int main()
{
    std::cout 
              << "blabla with uppercase: " << std::uppercase << "blabla" << std::endl
              << "BLABLA with nouppercase: " << std::nouppercase << "BLABLA" << std::endl
              << "uuuuh with uppercase: " << std::uppercase << "uuuuh" << std::endl
              << "UUUUH with nouppercase: " << std::nouppercase << "UUUUH" << std::endl;
}
*/
