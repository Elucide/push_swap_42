#include "push_swap.h"

int	clean_stack(int	*stack, int len)
{
	int	*new;
	int	i;

	i = 0;
	new = malloc(sizeof(int) * (len - 1));
	if (!new)
		return (0);
	while (i < len - 1)
	{
		new[i] = stack[i + 1];
		i++;
	}
	free(stack);
	stack = new;
	return (1);
}

int	add_stack(int *stack, int len, int nb)
{
	int *new;
	int	i;

	i = 0;
	new = malloc(sizeof(int) * (len + 1));
	if (!new)
		return (0);
	new[i] = nb;
	i++;
	while (i < len)
	{
		new[i] = stack[i];
		i++;
	}
	free(stack);
	stack = new;
	return (1);
}

int	push_a(t_data *data)
{
	if (data->len_b)
	{
		if (!add_stack(data->a, data->len_a, data->b[0]))
			return (0);
		if (!clean_stack(data->b, data->len_b))
			return (0);
		data->len_a++;
		data->len_b--;
	}
	return (write(1, "pa\n", 3));
}

int	push_b(t_data *data)
{
	if (data->len_a)
	{
		if (!add_stack(data->b, data->len_b, data->a[0]))
			return (0);
		if (!clean_stack(data->a, data->len_a))
			return (0);
		data->len_b++;
		data->len_a--;
	}
	return (write(1, "pb\n", 3));
}

