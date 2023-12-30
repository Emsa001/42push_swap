/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:54:42 by escura            #+#    #+#             */
/*   Updated: 2023/12/18 18:30:55 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

/*

pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty

*/

static int push(t_stack *s1, t_stack *s2)
{
	if (s1->size == 0) {
		return -1;
	}

	// Shift all elements in s2 upwards
	int i = s2->size;
	while (i > 0) {
		s2->arr[i] = s2->arr[i - 1];
		i--;
	}

	// Place the top element from s1 at the bottom of s2
	s2->arr[0] = s1->arr[0];

	// Shift all elements in s1 downwards
	i = 0;
	while (i < s1->size - 1) {
		s1->arr[i] = s1->arr[i + 1];
		i++;
	}

	s1->size--;
	s2->size++;

	return 0;
}

void pa(t_stacks *stacks)
{
	push(stacks->b, stacks->a);
}

void pb(t_stacks *stacks)
{
	push(stacks->a, stacks->b);
}
