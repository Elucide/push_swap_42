/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:13:17 by yschecro          #+#    #+#             */
/*   Updated: 2022/07/10 21:26:36 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	super_simple_sort(t_data *data)
{
	int	max;

	max = 0;
	if (!ft_create_comp(data, data->a, data->len_a))
		return (0);
	max = data->comp[data->len_a - 1];
	if (max == data->a[0])
		if (!rot_a(data))
			return (0);
	if (max == data->a[1])
		if (!rrot_a(data))
			return (0);
	if (data->a[0] > data->a[1])
		if (!swap_a(data))
			return (0);
	return (1);
}

int	quite_utils(t_data *data)
{
	int	i;
	int	func;

	i = 0;
	while (i < 2)
	{
		while (data->a[0] != data->comp[i])
		{
			func = get_pos(data, data->comp[i]);
			if (func == 1)
			{
				if (!rrot_a(data))
					return (0);
			}
			else if (func == 2)
			{
				if (!rot_a(data))
					return (0);
			}
		}
		if (!push_b(data))
			return (0);
		i++;
	}
	return (1);
}

int	quite_simple_sort(t_data *data)
{
	int	func;

	if (!ft_create_comp(data, data->a, data->len_a))
		return (0);
	func = get_pos(data, data->comp[4]);
	if (!quite_utils(data))
		return (0);
	if (!super_simple_sort(data))
		return (0);
	if (!push_a(data))
		return (0);
	if (!push_a(data))
		return (0);
	return (1);
}

int	simple_sort(t_data *data)
{
	if (data->len_a <= 3)
		return (super_simple_sort(data));
	return (quite_simple_sort(data));
}

int	ft_sort(t_data *data)
{
	if (data->len_a == 3)
	{
		if (!simple_sort(data))
			return (free(data->a), free(data->b), free(data->comp), 1);
	}
	else if (data->len_a == 5)
	{
		if (!quite_simple_sort(data))
			return (free(data->a), free(data->b), free(data->comp), 1);
	}
	else if (data->len_a > 5 || data->len_a == 4)
	{
		if (!ft_quick_quick_sort(data))
			return (free(data->a), free(data->b), write(1, "Error\n", 6));
		while (data->len_a)
			push_b(data);
		if (!ft_create_comp(data, data->b, data->len_b))
			return (free(data->a), free(data->b), write(1, "Error\n", 6));
		no_sort(data);
	}
	else if (!swap_a(data))
		return (1);
	return (0);
}
