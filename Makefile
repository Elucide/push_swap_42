SRCS	=		dual_rotate.c \
				ft_atoi.c  \
				main.c\
				move_utils.c\
				no_sort.c\
				parse_single.c\
				push.c\
				quick_sort.c\
				reverse.c\
				solve_utils.c\
				split.c\
				swap.c\
				simple_sort.c\
				ft_calloc.c\
				comp.c

NAME		=	push_swap

OBJ			=	$(SRCS:.c=.o)

DEP	= 			$(SRCS:%.c=%.d)

all			:	$(NAME)

$(CC)		:	gcc

$(NAME)			:	$(OBJ)
				$(CC) $(OBJ) -o $(NAME)

$(OBJ)		:
				$(CC) -Wall -Wextra -Werror -MP -MMD -g3 -c $(SRCS)

clean		:
				rm -f $(OBJ)
				rm -f $(DEP)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all


-include $(DEP)

.PHONY		:	all clean fclean re
