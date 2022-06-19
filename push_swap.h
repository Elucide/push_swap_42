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

void	print_stacks(t_data *data);
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
int	rot_a(t_data *data);
int	rot_b(t_data *data);
int	rrot_a(t_data *data);
int	rrot_b(t_data *data);
int	rr(t_data *data);
int	rrr(t_data *data);
int	*stack_del_front(int *stack, int len);
int	*stack_add_front(int *stack, int len, int nb);
int	*stack_del_back(int *stack, int len);
int	*stack_add_back(int *stack, int len, int nb);
