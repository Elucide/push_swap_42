/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:40:23 by yschecro          #+#    #+#             */
/*   Updated: 2022/07/10 21:28:58 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_del_front(int *stack, int len)
{
	int	*new;
	int	i;

	i = 0;
	new = (int *)malloc(sizeof(int) * (len + 1));
	if (!new)
		return (0);
	while (i < len - 1)
	{
		new[i] = stack[i + 1];
		i++;
	}
	if (stack)
		free(stack);
	return (new);
}

int	*stack_add_front(int *stack, int len, int nb)
{
	int	*new;
	int	i;

	i = 1;
	new = (int *)malloc(sizeof(int) * (len + 1));
	if (!new)
		return (0);
	new[0] = nb;
	while (i - 1 < len)
	{
		new[i] = stack[i - 1];
		i++;
	}
	if (stack)
		free(stack);
	return (new);
}

int	*stack_add_back(int *stack, int len, int nb)
{
	int	*new;
	int	i;

	i = 0;
	new = (int *)malloc(sizeof(int) * (len + 1));
	if (!new)
		return (0);
	while (i < len)
	{
		new[i] = stack[i];
		i++;
	}
	new[i] = nb;
	if (stack)
		free(stack);
	return (new);
}

int	*stack_del_back(int *stack, int len)
{
	int	*new;
	int	i;

	i = 0;
	new = (int *)malloc(sizeof(int) * (len + 1));
	if (!new)
		return (0);
	while (i < len - 1)
	{
		new[i] = stack[i];
		i++;
	}
	if (stack)
		free(stack);
	return (new);
}
