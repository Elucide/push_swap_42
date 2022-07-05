/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dual_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:40:12 by yschecro          #+#    #+#             */
/*   Updated: 2022/06/19 21:40:39 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rr(t_data *data)
{
	int	nb;

	if (data->len_a >= 2)
	{
		nb = data->a[0];
		data->a = stack_del_front(data->a, data->len_a);
		if (!data->a)
			return (0);
		data->a = stack_add_back(data->a, data->len_a - 1, nb);
		if (!data->a)
			return (0);
	}
	if (data->len_b >= 2)
	{
		nb = data->b[0];
		data->b = stack_del_front(data->b, data->len_b);
		if (!data->b)
			return (0);
		data->b = stack_add_back(data->b, data->len_b - 1, nb);
		if (!data->b)
			return (0);
	}
	return (write(1, "rr\n", 3));
}

int	rrr(t_data *data)
{
	int	nb;

	if (data->len_a >= 2)
	{
		nb = data->a[data->len_a - 1];
		data->a = stack_del_back(data->a, data->len_a);
		if (!data->a)
			return (0);
		data->a = stack_add_front(data->a, data->len_a - 1, nb);
		if (!data->a)
			return (0);
	}
	if (data->len_b >= 2)
	{
		nb = data->b[data->len_b - 1];
		data->b = stack_del_back(data->b, data->len_b);
		if (!data->b)
			return (0);
		data->b = stack_add_front(data->b, data->len_b - 1, nb);
		if (!data->b)
			return (0);
	}
	return (write(1, "rrr\n", 4));
}
