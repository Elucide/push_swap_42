/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:24:55 by yschecro          #+#    #+#             */
/*   Updated: 2022/07/05 19:06:33 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_int_tab(int *stack, int len)
{
	int	i;
	int	j;
	int	save;

	save = 0;
	i = 0;
	j = 0;
	while (j < len - 1)
	{
		i = 0;
		while (i < len - 1)
		{
			if (stack[i] > stack[i + 1])
			{
				save = stack[i];
				stack[i] = stack[i + 1];
				stack[i + 1] = save;
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	ft_create_comp(t_data *data)
{
	int	i;

	i = 0;
	data->comp = malloc(sizeof(int) * data->len_a);
	if (!data->comp)
		return (0);
	while (i < data->len_a)
	{
		data->comp[i] = data->a[i];
		i++;
	}
	sort_int_tab(data->comp, data->len_a);
	return (1);
}

int	ft_solve(t_data *data)
{
	int	i;
	int	save;

	save = 0;
	i = 0;
	if (!ft_create_comp(data))
		return (0);
	data->pivot = data->a[data->len_a - 1];
	print_stacks(data);
	rrot_a(data);
	push_b(data);
	while (i <= data->len_a + 5)
	{
		if (data->a[0] > data->pivot)
			push_b(data);
		else
			rot_a(data);
		i++;
	}
	print_stacks(data);
	i = 1;
	rrot_b(data);
	print_stacks(data);
	save = data->len_b;
	while (i <= save)
	{
		push_a(data);
		rot_a(data);
		i++;
	}
	print_stacks(data);
	return (1);
}
