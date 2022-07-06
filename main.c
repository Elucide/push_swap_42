/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:31:55 by yschecro          #+#    #+#             */
/*   Updated: 2022/07/06 16:00:23 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_data_init(t_data *data)
{
	data->len_a = 0;
	data->len_b = 0;
	data->j = 0;
	data->min = 0;
	data->max = 0;
	data->a = malloc(1);
	data->b = malloc(1);
	data->comp = NULL;
	if (!data->a || !data->b)
		return (0);
	data->mid = 0;
	data->pivot = 0;
	return (1);
}

void	print_stacks(t_data *data)
{
	int	i;

	i = 0;
	printf("\n----------------------------------------------------\n");
	dprintf(1, "	pivot: %d\n", data->pivot);
	dprintf(1, "	\n	stack A: ");
	while (i < data->len_a)
	{
		dprintf(1, "%d, ", data->a[i]);
		i++;
	}
	dprintf(1, "\n");
	dprintf(1, "	stack B: ");
	i = 0;
	while (i < data->len_b)
	{
		dprintf(1, "%d, ", data->b[i]);
		i++;
	}
	dprintf(1, "\n");
	dprintf(1, "	stack comp: ");
	if (data->comp)
	{
		i = 0;
		while (i < data->len_a)
		{
			dprintf(1, "%d, ", data->comp[i]);
			i++;
		}
	}
	dprintf(1, "\n");
	printf("----------------------------------------------------\n");
}

int main(int ac, char **av)
{

	t_data	data;

	if (!ft_data_init(&data))
		return (0);
	if (!ft_parse(ac, av, &data))
		return (write(1, "parsing error\n", 14));
	if (!data.len_a || !tab_check(&data))
		return (write(1, "parsing error\n", 14));
	if (!ft_create_comp(&data))
		return (0);
	data.min = data.comp[0];
	data.max = data.comp[data.len_a];
//	print_stacks(&data);
	if (data.len_a >= 10)
	{
		if (!ft_quick_quick_sort(&data))
			return (0);
	}
	no_sort(&data);
//	while (data.len_b)
//	{
//		if (!push_a(&data))
//			return (0);
//	}
	print_stacks(&data);
	free(data.a);
	free(data.b);
	free(data.comp);
	return (1);	
}
