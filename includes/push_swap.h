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
}			t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}			t_stacks;

void		read_args(char **args, t_stacks **stacks);
void		init_stacks(t_stacks **stack);

void		ft_error(char *msg, t_stacks *stacks);
void		free_stacks(t_stacks *stacks);

void		sort(t_stacks **stacks);
void		sort_tiny(t_stacks **stacks);
void		sort_large(t_stacks **stacks);

int			find_max(t_stack *stack);
int			find_min(t_stack *stack);
int			is_sorted(t_stack *stack);

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
