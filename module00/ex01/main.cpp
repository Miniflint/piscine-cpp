#include "main.class.hpp"

int main(void)
{
    PhoneBook   pb;
    std::string _whatToDo;

    while (1)
    {
        std::cout << "Choose one:" << std::endl << "ADD, SEARCH, EXIT" << std::endl << ">> ";
        std::cin >> _whatToDo;
        if (!_whatToDo.compare("ADD"))
        {
            pb.addContact();
        }
        else if (!_whatToDo.compare("SEARCH"))
        {
            pb.search();
        }
        else if (!_whatToDo.compare("EXIT"))
            break ;
    }
    return (0);
}
