/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:58:30 by escura            #+#    #+#             */
/*   Updated: 2023/12/18 22:18:23 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	more_than_three(t_stacks **stacks)
{
	t_stack	*a;
	int		min_index;
	int		min_value;

	a = (*stacks)->a;
	while (a->size > 3)
	{
		min_index = find_min(a);
		min_value = a->arr[min_index];
		while (a->arr[0] != min_value)
		{
			if (min_index > a->size / 2)
				rra(a);
			else
				ra(a);
		}
		if (is_sorted(a) && (*stacks)->b->size == 0)
			return (-1);
		pb(*stacks);
	}
	return (0);
}

void	sort_tiny(t_stacks **stacks)
{
	t_stack	*a;
	int		max_index;

	if (more_than_three(stacks) == -1)
		return ;
	a = (*stacks)->a;
	max_index = find_max(a);
	if (max_index == 0)
		ra(a);
	else if (max_index == 1)
		rra(a);
	if (a->arr[0] > a->arr[1])
		sa(a);
	if (is_sorted(a) && (*stacks)->b->size == 0)
		return ;
	pa(*stacks);
	pa(*stacks);
}
