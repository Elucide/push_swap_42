/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:20:50 by yschecro          #+#    #+#             */
/*   Updated: 2022/07/11 20:56:50 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_create_comp(t_data *data, int *stack, int len)
{
	int	i;

	i = 0;
	if (len == 0)
		return (0);
	if (data->comp)
		free(data->comp);
	data->comp = (int *)malloc(sizeof(int) * len);
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
