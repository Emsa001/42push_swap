/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:55:55 by escura            #+#    #+#             */
/*   Updated: 2023/12/18 18:36:38 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

/*

sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
ss : sa and sb at the same time.

*/

static int swap(t_stack *stack){
    int tmp;

    if(stack->size < 2)
        return -1;
    tmp = stack->arr[0];
    stack->arr[0] = stack->arr[1];
    stack->arr[1] = tmp;
    return 0;
}

void sa(t_stack *stack)
{
    swap(stack);
}

void sb(t_stack *stack)
{
    swap(stack);
}

void ss(t_stacks *stacks)
{
    swap(stacks->a);
    swap(stacks->b);
}