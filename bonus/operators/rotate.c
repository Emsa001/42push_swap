/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:07:04 by escura            #+#    #+#             */
/*   Updated: 2023/12/18 18:35:54 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*

ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
rr : ra and rb at the same time.

*/

static int rotate(t_stack *stack){
    int tmp;
    int i;

    if(stack->size < 2)
        return -1;
    tmp = stack->arr[0];
    i = 0;
    while(i < stack->size - 1){
        stack->arr[i] = stack->arr[i + 1];
        i++;
    }
    stack->arr[stack->size - 1] = tmp;
    return 0;
}

void ra(t_stack *stack)
{
    if(rotate(stack) != -1)
        ft_putendl_fd("ra", 1);
}

void rb(t_stack *stack)
{
    if(rotate(stack) != -1)
        ft_putendl_fd("rb", 1);
}

void rr(t_stacks *stacks)
{
    if(stacks->a->size > 0 && stacks->b->size > 0){
        rotate(stacks->a);
        rotate(stacks->b);
        ft_putendl_fd("rr", 1);
    }
}