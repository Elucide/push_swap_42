/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:24:53 by yschecro          #+#    #+#             */
/*   Updated: 2022/07/10 21:26:02 by yschecro         ###   ########.fr       */
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

int	is_sorted(t_data *data, int *stack, int len)
{
	int	i;

	if (!ft_create_comp(data, stack, len))
		return (1);
	i = 0;
	while (i < len)
	{
		if (stack[i] != data->comp[i])
			return (0);
		i++;
	}
	return (1);
}

int	setup(int ac, char **av, t_data *data)
{
	if (!ft_data_init(data))
		return (free(data->a), free(data->b), write(1, "Error\n", 6));
	if (!ft_parse(ac, av, data))
		return (free(data->a), free(data->b), write(1, "Error\n", 6));
	if (!data->len_a)
		return (free(data->a), free(data->b), 1);
	if (!tab_check(data))
		return (free(data->a), free(data->b), write(1, "Error\n", 6));
	if (is_sorted(data, data->a, data->len_a))
		return (free(data->a), free(data->comp), free(data->b), 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (setup(ac, av, &data))
		return (1);
	if (ft_sort(&data))
		return (free(data.a), free(data.b), free(data.comp), 1);
	return (free(data.a), free(data.b), free(data.comp), 1);
}
