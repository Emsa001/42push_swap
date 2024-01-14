/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:50:04 by escura            #+#    #+#             */
/*   Updated: 2024/01/14 16:48:28 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	do_moves_order(t_stacks *stacks);
void	put_in_order(t_stacks *stacks);

void	move_stack_a(t_stacks *stacks)
{
	while (stacks->b->size > 0)
	{
		check_max_min(stacks, stacks->a);
		if (stacks->b->arr[0] < stacks->values->min_a)
			new_min_stack_a(stacks);
		else if (stacks->b->arr[0] > stacks->values->max_a)
			new_max_stack_a(stacks);
		else
			new_elem_stack_a(stacks);
	}
	check_max_min(stacks, stacks->a);
	put_in_order(stacks);
}

void	put_in_order(t_stacks *stacks)
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
	do_moves_order(stacks);
}

void	do_moves_order(t_stacks *stacks)
{
	while (stacks->moves->ra-- != 0)
		ra(stacks->a);
	while (stacks->moves->rra-- != 0)
		rra(stacks->a);
}

int	find_index_stack_a(t_stacks *stacks, int nbr)
{
	int	i;

	i = 0;
	while (i < stacks->a->size)
	{
		if (stacks->a->arr[i] == nbr)
			break ;
		i++;
	}
	return (i);
}
