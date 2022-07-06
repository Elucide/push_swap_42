/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:24:55 by yschecro          #+#    #+#             */
/*   Updated: 2022/07/06 17:16:44 by yschecro         ###   ########.fr       */
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

int	ft_create_comp(t_data *data, int *stack, int len)
{
	int	i;

	i = 0;
	free(data->comp);
	data->comp = malloc(sizeof(int) * (len + 1));
	if (!data->comp)
		return (0);
	while (i < len)
	{
		data->comp[i] = stack[i];
		i++;
	}
	sort_int_tab(data->comp, len);
	return (1);
}

int	first_step(t_data *data)
{
	int	i;
	int	func;

	func = get_pos(data, data->pivot);
	i = 0;
	while (data->a[i] != data->pivot)
	{
		if (func == 1)
		{
			if (!rrot_a(data))
				return (0);
		}
		if (func == 2)
		{
			if (!rot_a(data))
				return (0);
		}
	}
	if (!push_b(data))
		return (0);
	return (1);
}

int	second_step(t_data *data)
{
	int	i;
	int lol;

	i = 0;
	lol = data->len_a;
	while (i <= lol)
	{
		if (data->a[0] > data->pivot)
		{
			if (!push_b(data))
				return (0);
		}
		else
		{
			if (!rot_a(data))
				return (0);
		}
		i++;
	}
	return (1);
}


int	ft_quick_quick_sort(t_data *data)
{
	int	i;
	int	save;

	save = 0;
	dprintf(1, "pivot = %d\n", data->pivot);
	while (data->len_a >= 5)
	{
		if (!ft_create_comp(data, data->a, data->len_a))
			return (0);
		data->pivot = data->comp[data->len_a / 2];
		if (!first_step(data) || !second_step(data))
			return (0);
	}
	save = data->len_a;
	i = 0;
	while (i < save)
	{
		push_b(data);
		//		rot_a(data);
		i++;
	}
	//	print_stacks(data);
	return (1);
}
