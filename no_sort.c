/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:11:52 by yschecro          #+#    #+#             */
/*   Updated: 2022/07/06 16:17:59 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	no_sort(t_data *data)
{
	int	lol;
	int	func;

	lol = data->len_b - 1;
	while (data->len_b && lol)
	{
		func = get_pos_b(data, data->comp[lol]);
//		dprintf(1, "comp[lol] = %d, lol = %d\n", data->comp[lol], lol);
		while (data->b[0] != data->comp[lol])
		{
			if (func == 1)
				
			{
				if (!rrot_b(data))
					return (0);
			}
			else if (func == 2)
			{
				if (!rot_b(data))
					return (0);
			}
		}
		lol--;
		if (!push_a(data))
			return (0);
	}
	if (!push_a(data))
		return (0);
//	print_stacks(data);
	return (1);
}
