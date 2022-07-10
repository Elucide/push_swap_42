/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:46:35 by yschecro          #+#    #+#             */
/*   Updated: 2022/07/07 15:47:37 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(t_data *data, int nb)
{
	int	i;

	i = 0;
	while (data->a[i] != nb)
		i++;
	if (i >= data->len_a / 2)
		return (1);
	return (2);
}

int	get_pos_b(t_data *data, int nb)
{
	int	i;

	i = 0;
	while (data->b[i] != nb)
		i++;
	if (i >= data->len_b / 2)
		return (1);
	return (2);
}
