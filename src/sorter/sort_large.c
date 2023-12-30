/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:06:03 by escura            #+#    #+#             */
/*   Updated: 2023/12/19 01:05:02 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*

sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.

*/

void	do_cheap_moves(t_stacks *stacks)
{
	while (stacks->cheap->ra-- != 0)
		ra(stacks->a);
	while (stacks->cheap->rb-- != 0)
		rb(stacks->b);
	while (stacks->cheap->rr-- != 0)
		rr(stacks);
	while (stacks->cheap->rra-- != 0)
		rra(stacks->a);
	while (stacks->cheap->rrb-- != 0)
		rrb(stacks->b);
	while (stacks->cheap->rrr-- != 0)
		rrr(stacks);
	while (stacks->cheap->pb-- != 0)
		pb(stacks);
}

void	move_cheapest(t_stacks *stacks)
{
	struct t_moves	*moves;
	struct t_cheap	*cheap;
	t_values		*values;

	moves = ft_calloc(1, sizeof(t_moves));
	stacks->moves = moves;
	cheap = ft_calloc(1, sizeof(t_cheap));
	stacks->cheap = cheap;
	values = ft_calloc(1, sizeof(t_values));
	stacks->values = values;
	while (stacks->a->size != 3)
	{
        check_max_min(stacks, stacks->b);
		check_moves(stacks);
		do_cheap_moves(stacks);
	}
}

static void free_mem(t_stacks *stacks){
	free(stacks->moves);
	free(stacks->cheap);
	free(stacks->values);
}


void sort_large(t_stacks **stacks)
{   
	pb(*stacks);
	pb(*stacks);
	move_cheapest(*stacks);
	sort_three(stacks);
	move_stack_a(*stacks);

	free_mem(*stacks);
}