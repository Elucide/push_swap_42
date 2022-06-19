#include "push_swap.h"

int	push_a(t_data *data)
{
	if (data->len_b)
	{
		data->a = stack_add_front(data->a, data->len_a, data->b[0]);
		if (!data->a)
			return (0);
		data->len_a++;
		data->b = stack_del_front(data->b, data->len_b);
		if (!data->b)
			return (0);
		data->len_b--;
	}
	return (write(1, "pa\n", 3));
}

int	push_b(t_data *data)
{
	if (data->len_a)
	{
		data->b = stack_add_front(data->b, data->len_b, data->a[0]);
		if (!data->b)
			return (0);
		data->len_b++;
		data->a = stack_del_front(data->a, data->len_a);
		if (!data->a)
			return (0);
		data->len_a--;
	}
	return (write(1, "pb\n", 3));
}

