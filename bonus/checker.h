#ifndef CHECKER_H
# define CHECKER_H

# include "../includes/libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define true 1
# define false 0
# define BUFFER_SIZE 3

typedef struct s_stack
{
	int		*arr;
	int		size;
}			t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}			t_stacks;

void		init_stacks(t_stacks **stack);
void		ft_error(char *msg, t_stacks *stacks);
void		free_stacks(t_stacks *stacks);
int 		is_sorted(t_stack *stack);
void 		read_args(int nb, char **args, t_stacks **stacks);


void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stacks *stacks);

void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);

void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stacks *stacks);

void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stacks *stacks);

#endif
