/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_single.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:40:26 by yschecro          #+#    #+#             */
/*   Updated: 2022/07/10 16:16:49 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tab_check(t_data *data)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	while (i < data->len_a - 1)
	{
		j = i + 1;
		nb = data->a[i];
		while (j < data->len_a)
		{
			if (nb == data->a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcheck(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	try_arg(char *arg, char *str)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_strcheck(str, arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_parse(int ac, char **av, t_data *d)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		if (!try_arg(av[1], "-1234567890\t\v\n\r\f "))
			return (0);
		if (!ft_split_int(av[1], d))
			return (0);
	}
	else if (ac == 1)
		return (write(1, "Error\n", 6), 0);
	else
	{
		while (i < ac - 1)
		{
			if (!try_arg(av[i + 1], "-1234567890\t\v\n\r\f "))
				return (0);
			fill_a(ft_atoi(av[i + 1]), d);
			i++;
		}
	}
	return (1);
}
