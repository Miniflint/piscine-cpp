#ifndef MAIN_CLASS_HPP
# define MAIN_CLASS_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <string>

# define maxSize 8
# define WIDTH 10

# define LOG_N(x) std::cout << x << std::endl;
# define LOG(x) std::cout << x

# define ASK(display, var) std::cout << display << ": "; std::getline(std::cin, var);

class Contact
{
    private:
        int         _index;
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;
    public:
        Contact(void);
        ~Contact(void);
        void addContact(
            int	index, std::string firstName,
            std::string lastName, std::string nickName,
            std::string phoneNumber, std::string darkestSecret
        );  
        void printContact(void);
        void printInfo(void);
};

class PhoneBook
{
    private:
        int _amountPeople;
        Contact _contact[maxSize];
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void    addContact();
        void    printAll();
        void    search();
};

#endif