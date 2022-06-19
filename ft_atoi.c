#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	out;
	int	signe;

	i = 0;
	signe = 1;
	out = 0;
	if (str[0] == '-')
	{
		signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		out = out * 10 + str[i] - '0';
		i++;
	}
	return (out * signe);
}
