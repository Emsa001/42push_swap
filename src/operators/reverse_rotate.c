/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:08:18 by escura            #+#    #+#             */
/*   Updated: 2023/12/18 18:34:51 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*

rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.

*/

static int reverse_rotate(t_stack *stack){
    int tmp;
    int i;

    if(stack->size < 2)
        return -1;
    tmp = stack->arr[stack->size - 1];
    i = stack->size - 1;
    while(i > 0){
        stack->arr[i] = stack->arr[i - 1];
        i--;
    }
    stack->arr[0] = tmp;
    return 0;
}

void rra(t_stack *stack)
{
    if(reverse_rotate(stack) != -1)
        ft_putendl_fd("rra", 1);
}

void rrb(t_stack *stack)
{
    if(reverse_rotate(stack) != -1)
        ft_putendl_fd("rrb", 1);
}

void rrr(t_stacks *stacks)
{
    if(stacks->a->size > 0 && stacks->b->size > 0){
        reverse_rotate(stacks->a);
        reverse_rotate(stacks->b);
        ft_putendl_fd("rrr", 1);
    }
}
