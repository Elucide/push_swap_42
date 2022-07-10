/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:24:55 by yschecro          #+#    #+#             */
/*   Updated: 2022/07/10 21:24:29 by yschecro         ###   ########.fr       */
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

int	first_step(t_data *data)
{
	int	func;

	func = get_pos(data, data->pivot);
	while (1)
	{
		if (data->a[0] != data->pivot)
			break ;
		if (func == 1)
		{
			if (!rrot_a(data))
				return (0);
		}
		else if (!rot_a(data))
			return (0);
	}
	if (!push_b(data))
		return (0);
	return (1);
}

int	second_step(t_data *d)
{
	int	i;
	int	lol;

	i = 0;
	lol = d->len_a;
	while (i <= lol)
	{
		if (d->a[0] > d->pivot)
		{
			if (!push_b(d))
				return (0);
		}
		else
		{
			if (!rot_a(d))
				return (0);
		}
		i++;
	}
	return (1);
}

int	third_step(t_data *data)
{	
	int	i;
	int	save;

	save = data->len_a;
	i = 0;
	while (i < save)
	{
		if (!push_b(data))
			return (0);
		i++;
	}
	return (1);
}

int	ft_quick_quick_sort(t_data *data)
{
	int	chunk;

	if (data->len_a < 400)
		chunk = 4;
	else
		chunk = 6;
	while (data->len_a >= 5)
	{
		if (!ft_create_comp(data, data->a, data->len_a))
			return (0);
		data->pivot = data->comp[data->len_a - (data->len_a / chunk)];
		if (!first_step(data))
			return (0);
		if (!second_step(data))
			return (0);
	}
	if (!third_step(data))
		return (0);
	return (1);
}
