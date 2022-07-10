/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:39:39 by yschecro          #+#    #+#             */
/*   Updated: 2022/07/10 21:27:00 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rot_a(t_data *data)
{
	int	nb;

	if (data->len_a >= 2)
	{
		nb = data->a[0];
		data->a = stack_del_front(data->a, data->len_a);
		if (!data->a)
			return (0);
		data->len_a--;
		data->a = stack_add_back(data->a, data->len_a, nb);
		if (!data->a)
			return (0);
		data->len_a++;
	}
	return (write(1, "ra\n", 3));
}

int	rot_b(t_data *data)
{
	int	nb;

	if (data->len_b >= 2)
	{
		nb = data->b[0];
		data->b = stack_del_front(data->b, data->len_b);
		if (!data->b)
			return (0);
		data->len_b--;
		data->b = stack_add_back(data->b, data->len_b, nb);
		if (!data->b)
			return (0);
		data->len_b++;
	}
	return (write(1, "rb\n", 3));
}

int	rrot_a(t_data *data)
{
	int	nb;

	if (data->len_a >= 2)
	{
		nb = data->a[data->len_a - 1];
		data->a = stack_del_back(data->a, data->len_a);
		if (!data->a)
			return (0);
		data->len_a--;
		data->a = stack_add_front(data->a, data->len_a, nb);
		if (!data->a)
			return (0);
		data->len_a++;
	}
	return (write(1, "rra\n", 4));
}

int	rrot_b(t_data *data)
{
	int	nb;

	if (data->len_b >= 2)
	{
		nb = data->b[data->len_b - 1];
		data->b = stack_del_back(data->b, data->len_b);
		if (!data->b)
			return (0);
		data->len_b--;
		data->b = stack_add_front(data->b, data->len_b, nb);
		if (!data->b)
			return (0);
		data->len_b++;
	}
	return (write(1, "rrb\n", 4));
}
