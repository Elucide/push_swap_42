#include "push_swap.h"

int	fill_a(int nb, t_data *data)
{
	int *new;
	int	i;

	i = 0;
	new = malloc(sizeof(int) * data->len_a + 1);
	if (!new)
		return (0);
	while (i < data->len_a)
	{
		new[i] = data->a[i];
		i++;
	}
	new[i] = nb;
//	dprintf(1, "atoi %d\n", new[i]);
	data->len_a++;
	free(data->a);
	data->a = new;
	return (1);
}
	

int	ft_split_int(char *str, t_data *data)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	data->a = malloc(sizeof(int));
	if (!data->a)
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			n = ft_atoi(str + i);
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		if (!fill_a(n, data))
			return (0);
		while (str[i] == '\t' || str[i] == '\v' || \
			str[i] == '\n' || str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
			i++;
	}
	return (1);
}

