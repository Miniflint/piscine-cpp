#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl {
    private:
        void    _debug(void);
        void    _info(void);
        void    _warning(void);
        void    _error(void);
        typedef struct  _S_binders {
            std::string str;
            void    (Harl::*f)(void);
        }   _bind;
        _bind   _s[4];

    public:
        Harl(void);
        ~Harl(void) { return ;}
        void    complain(std::string level);
};

#endif