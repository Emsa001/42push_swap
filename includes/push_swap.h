/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:50:52 by escura            #+#    #+#             */
/*   Updated: 2023/12/18 22:17:52 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../includes/libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

# define true 1
# define false 0

typedef struct s_stack
{
	int		*arr;
	int		size;
	char	name;
}			t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	struct t_values		*values;
	struct t_moves		*moves;
	struct t_cheap		*cheap;
}			t_stacks;

typedef struct t_values
{
	int					max_a;
	int					min_a;
	int					max_b;
	int					min_b;
}						t_values;

typedef struct t_moves
{
	int					cost;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_moves;

typedef struct t_cheap
{
	int					cost;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_cheap;


void		read_args(int nb, char **args, t_stacks **stacks);
void		init_stacks(t_stacks **stack);

void		ft_error(char *msg, t_stacks *stacks);
void		free_stacks(t_stacks *stacks);

void		sort(t_stacks **stacks);
void 		sort_three(t_stacks **stacks);
void		sort_tiny(t_stacks **stacks);
void		sort_large(t_stacks **stacks);

int			find_max(t_stack *stack);
int			find_min(t_stack *stack);
int			is_sorted(t_stack *stack);

void	check_max_min(t_stacks *stacks, t_stack *stack);
void	new_max_or_min_stack_b(t_stacks *stacks);
void	check_moves(t_stacks *stacks);
void	check_cost(t_stacks *stacks, int i);
void	check_double_moves(t_stacks *stacks);
void	get_top_stack_a(t_stacks *stacks, int i);
void	new_num_in_stack_b(t_stacks *stacks, int num);
void	move_stack_a(t_stacks *stacks);

void	new_min_stack_a(t_stacks *stacks);
void	new_max_stack_a(t_stacks *stacks);
void	new_elem_stack_a(t_stacks *stacks);
int		find_index_stack_a(t_stacks *stacks, int nbr);

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
