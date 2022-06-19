#include "push_swap.h"

int	*stack_del_front(int *stack, int len)
{
	int	*new;
	int	i;

	i = 0;
	new = malloc(sizeof(int) * (len - 1));
	if (!new)
		return (0);
	while (i < len)
	{
		new[i] = stack[i + 1];
		i++;
	}
	free(stack);
	return (new);
}

int	*stack_add_front(int *stack, int len, int nb)
{
	int *new;
	int	i;

	i = 1;
	new = malloc(sizeof(int) * (len + 1));
	if (!new)
		return (0);
	new[0] = nb;
	while (i - 1 < len)
	{
		new[i] = stack[i - 1];
		i++;
	}
	free(stack);	
	return (new);
}


int	*stack_add_back(int *stack, int len, int nb)
{
	int *new;
	int	i;

	i = 0;
	new = malloc(sizeof(int) * len + 1);
	if (!new)
		return (0);
	while (i < len)
	{
		new[i] = stack[i];
		i++;
	}
	new[i] = nb;
	free(stack);
	return (new);
}

int	*stack_del_back(int *stack, int len)
{
	int *new;
	int	i;

	i = 0;
	new = malloc(sizeof(int) * len + 1);
	if (!new)
		return (0);
	while (i < len - 1)
	{
		new[i] = stack[i];
		i++;
	}
	free(stack);
	return (new);
}
