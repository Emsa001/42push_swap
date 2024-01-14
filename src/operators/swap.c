/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:55:55 by escura            #+#    #+#             */
/*   Updated: 2024/01/14 12:37:02 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return (-1);
	tmp = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = tmp;
	return (0);
}

void	sa(t_stack *stack)
{
	if (swap(stack) != -1)
		ft_putendl_fd("sa", 1);
}

void	sb(t_stack *stack)
{
	if (swap(stack) != -1)
		ft_putendl_fd("sb", 1);
}

void	ss(t_stacks *stacks)
{
	if (stacks->a->size > 0 && stacks->b->size > 0)
	{
		swap(stacks->a);
		swap(stacks->b);
		ft_putendl_fd("ss", 1);
	}
}
