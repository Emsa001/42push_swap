/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:06:03 by escura            #+#    #+#             */
/*   Updated: 2024/01/14 16:49:50 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

static void	free_mem(t_stacks *stacks)
{
	free(stacks->moves);
	free(stacks->cheap);
	free(stacks->values);
}

void	sort_large(t_stacks **stacks)
{
	pb(*stacks);
	pb(*stacks);
	move_cheapest(*stacks);
	sort_three(stacks);
	move_stack_a(*stacks);
	free_mem(*stacks);
}
