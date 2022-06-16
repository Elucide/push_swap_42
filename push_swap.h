#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_data
{
	int	*a;
	int	*b;
	int	i;
	int	j;
	int len_a;
	int	len_b;
}	t_data;

int ft_atoi(char *str);
int	ft_split_int(char *str, t_data *data);
int	fill_a(int nb, t_data *data);
int ft_parse(int ac, char **av, t_data *d);
int try_arg(char *arg, char *str);
int	ft_data_init(t_data *data);
int	tab_check(t_data *data);
int	swap_a(t_data *data);
int	swap_b(t_data *data);
int	swap_s(t_data *data);
int	push_a(t_data *data);
int	push_b(t_data *data);
int	clean_stack(int	*stack, int len);
int	add_stack(int *stack, int len, int nb);
