#include "../headers/INC.hpp"

int		ft_strlen(std::string s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
