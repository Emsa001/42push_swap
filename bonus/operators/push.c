/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:54:42 by escura            #+#    #+#             */
/*   Updated: 2024/01/14 13:11:12 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

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
	push(stacks->b, stacks->a);
}

void	pb(t_stacks *stacks)
{
	push(stacks->a, stacks->b);
}
