/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:54:42 by escura            #+#    #+#             */
/*   Updated: 2024/01/14 12:39:08 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	push(t_stack *s1, t_stack *s2)
{
	int	i;

	if (s1->size == 0)
		return (-1);
	i = s2->size;
	while (i > 0)
	{
		s2->arr[i] = s2->arr[i - 1];
		i--;
	}
	s2->arr[0] = s1->arr[0];
	i = 0;
	while (i < s1->size - 1)
	{
		s1->arr[i] = s1->arr[i + 1];
		i++;
	}
	s1->size--;
	s2->size++;
	return (0);
}

void	pa(t_stacks *stacks)
{
	if (push(stacks->b, stacks->a) != -1)
		ft_putendl_fd("pa", 1);
}

void	pb(t_stacks *stacks)
{
	if (push(stacks->a, stacks->b) != -1)
		ft_putendl_fd("pb", 1);
}
