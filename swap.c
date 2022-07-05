/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:40:02 by yschecro          #+#    #+#             */
/*   Updated: 2022/06/19 21:40:39 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_data *data)
{
	int	temp;

	if (data->len_a > 1)
	{
		temp = data->a[0];
		data->a[0] = data->a[1];
		data->a[1] = temp;
	}
	return(write(1, "sa\n", 3));
}

int	swap_b(t_data *data)
{
	int	temp;

	if (data->len_b > 1)
	{
		temp = data->b[0];
		data->b[0] = data->b[1];
		data->b[1] = temp;
	}
	return(write(1, "sb\n", 3));
}

int	swap_s(t_data *data)
{
	int	temp;

	if (data->len_a > 1)
	{
		temp = data->a[0];
		data->a[0] = data->a[1];
		data->a[1] = temp;
	}
	if (data->len_b > 1)
	{
		temp = data->b[0];
		data->b[0] = data->b[1];
		data->b[1] = temp;
	}
	return(write(1, "ss\n", 3));
}
