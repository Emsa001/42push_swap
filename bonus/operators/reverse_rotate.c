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

#include "../checker.h"

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
    reverse_rotate(stack);
}

void rrb(t_stack *stack)
{
    reverse_rotate(stack);
}

void rrr(t_stacks *stacks)
{
    reverse_rotate(stacks->a);
    reverse_rotate(stacks->b);
}
