#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
    int i;
    int j;

    if (argc < 2)
        return ((std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl), 0);
    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
            std::cout << (char)(toupper(argv[i][j++]));
        i++;
    }
    return ((std::cout << std::endl), 0);
}