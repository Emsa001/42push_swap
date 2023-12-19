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

/*

void rotate_to_top(t_stack *stack, int index)
{
    int i;
    int size;

    i = 0;
    size = stack->size;
    if (index > size / 2)
    {
        while (i < size - index)
        {
            rra(stack);
            i++;
        }
    }
    else
    {
        while (i < index)
        {
            ra(stack);
            i++;
        }
    }
}

void	sort_large(t_stacks **stacks)
{
    int	min_index;
    int	max_index;
    
    max_index = find_max((*stacks)->a);

    t_stack *a = (*stacks)->a;
    t_stack *b = (*stacks)->b;

    while(a->size > 0)
    {
        int min_index = find_min((*stacks)->a);
        rotate_to_top(a, min_index);
        pb(*stacks);
    }

    while(b->size > 0)
        pa(*stacks);
   
}

*/


void sort_large(t_stacks **stacks)
{
    pb(*stacks);
    pb(*stacks);
    // find the number with least amount of moves to push to b in correct order
}