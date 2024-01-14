/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_max_min_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:50:12 by escura            #+#    #+#             */
/*   Updated: 2024/01/14 16:47:51 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static void	do_moves(t_stacks *stacks)
{
	while (stacks->moves->ra-- != 0)
		ra(stacks->a);
	while (stacks->moves->rra-- != 0)
		rra(stacks->a);
	pa(stacks);
}

void	new_min_stack_a(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->a->arr[0] != stacks->values->min_a)
	{
		i = find_index_stack_a(stacks, stacks->values->min_a);
		size = stacks->a->size;
		if (size % 2 == 0)
		{
			if (i + 1 > size / 2)
				stacks->moves->rra = (size - i);
			else
				stacks->moves->ra = i;
		}
		else
		{
			if (i > size / 2)
				stacks->moves->rra = (size - i);
			else
				stacks->moves->ra = i;
		}
	}
	do_moves(stacks);
}

static void	new_max_stack_a_2(t_stacks *stacks)
{
	int	i;
	int	size;

	if (stacks->a->arr[stacks->a->size - 1] != stacks->values->max_a)
	{
		i = find_index_stack_a(stacks, stacks->values->max_a);
		size = stacks->a->size;
		if (size % 2 == 0)
		{
			if (i + 1 > size / 2)
				stacks->moves->rra = (size - i) - 1;
			else
				stacks->moves->ra = i + 1;
		}
		else
		{
			if (i > size / 2)
				stacks->moves->rra = (size - i) - 1;
			else
				stacks->moves->ra = i + 1;
		}
	}
}

void	new_max_stack_a(t_stacks *stacks)
{
	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	new_max_stack_a_2(stacks);
	do_moves(stacks);
	ra(stacks->a);
}

void	get_top_stack_a(t_stacks *stacks, int i)
{
	int	size;

	stacks->moves->pb = 1;
	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	size = stacks->a->size;
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stacks->moves->rra = (size - i);
		else
			stacks->moves->ra = i;
	}
	else
	{
		if (i > size / 2)
			stacks->moves->rra = (size - i);
		else
			stacks->moves->ra = i;
	}
}
