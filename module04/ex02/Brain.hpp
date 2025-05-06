#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "iostream"

class Brain
{
    private:
        std::string _ideas[100];
        int         _curr_index;

    public:
        Brain(void);
        ~Brain();
        void    addIdea(std::string idea);
};



#endif