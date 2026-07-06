#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    protected:
        bool    _guardMode;

    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &trap);
        ~ScavTrap(void);
        void attack(const std::string& target);
        void guardGate(void);
};

#endif