#include "push_swap.h"

int	ft_data_init(t_data *data)
{
	data->len_a = 0;
	data->len_b = 0;
	data->i = 0;
	data->j = 0;
	data->a = NULL;
//	if (!data->a)
//		return (0);
//	data->b = malloc(0);
	data->b = NULL;
//	if (!data->b)
//		return (0);
	return (1);
}

void	print_stacks(t_data *data)
{
	int	i;

	i = 0;
	dprintf(1, "len A = %d", data->len_a);
	dprintf(1, "\nstack A: ");
	while (i < data->len_a)
	{
		dprintf(1, "%d, ", data->a[i]);
		i++;
	}
	dprintf(1, "\nlen B = %d\n", data->len_b);
	dprintf(1, "B pointer = %p\n", data->b);
	dprintf(1, "stack B: ");
	i = 0;
	while (i < data->len_b)
	{
		dprintf(1, "%d, ", data->b[i]);
		i++;
	}
	dprintf(1, "\n");
}

int main(int ac, char **av)
{
	
	t_data	data;

	if (!ft_data_init(&data))
		return (0);
	if (!ft_parse(ac, av, &data))
		return (write(1, "parsing error\n", 14));
	if (!data.len_a || !tab_check(&data))
		return (write(1, "parsing error\n", 14));
//	ft_split_int("42 44 4 43454 43854", data);
//	print_stacks(&data);
//	push_b(&data);
//	push_a(&data);
	print_stacks(&data);
	rrot_a(&data);
	print_stacks(&data);

//	print_stacks(&data);
	free(data.a);
	free(data.b);
//	printf("%d\n", ft_atoi(av[ac - 1]));
}
