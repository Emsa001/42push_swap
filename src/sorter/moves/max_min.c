/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:49:55 by escura            #+#    #+#             */
/*   Updated: 2024/01/14 16:48:33 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	check_min(t_stacks *stacks, t_stack *stack);
void	check_max(t_stacks *stacks, t_stack *stack);

void	check_max_min(t_stacks *stacks, t_stack *stack)
{
	if (stack->size > 0)
	{
		check_max(stacks, stack);
		check_min(stacks, stack);
	}
}

void	check_min(t_stacks *stacks, t_stack *stack)
{
	int	i;
	int	*min;

	i = 0;
	if (stack->name == 'a')
		min = &stacks->values->min_a;
	else
		min = &stacks->values->min_b;
	*min = stack->arr[0];
	while (i < stack->size)
	{
		if (*min > stack->arr[i])
			*min = stack->arr[i];
		i++;
	}
}

void	check_max(t_stacks *stacks, t_stack *stack)
{
	int	i;
	int	*max;

	i = 0;
	if (stack->name == 'a')
		max = &stacks->values->max_a;
	else
		max = &stacks->values->max_b;
	*max = stack->arr[0];
	while (i < stack->size)
	{
		if (*max < stack->arr[i])
			*max = stack->arr[i];
		i++;
	}
}
