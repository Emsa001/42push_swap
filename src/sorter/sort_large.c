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

// int find_correct_position(t_stack *stack, int value)
// {
//     int i = 0;
//     while (i < stack->size)
//     {
//         if (stack->arr[i] > value)
//             return (i);
//         i++;
//     }
//     return (i);
// }

// int ft_min(int a, int b)
// {
//     if (a < b)
//         return (a);
//     return (b);
// }

// int find_cheapest(t_stacks *stacks){
//     int moves = 1;
//     int cheapest = INT_MAX;
//     int index = 0;
//     int i = 0;

//     while(i < stacks->a->size)
//     {
//         int pos_in_a = i;
//         int pos_in_b = find_correct_position(stacks->b, stacks->a->arr[i]);
//         int rotate_b = ft_min(pos_in_b, stacks->b->size - pos_in_b);
//         moves = pos_in_a + rotate_b + 1;
//         if (moves < cheapest){
//             index = i;
//             cheapest = moves;
//         }
//         printf("num: %d moves: %d\n",stacks->a->arr[i], moves);
//         i++;
//     }

//     return (index);
// }

void	do_cheap_moves(t_stacks *stacks)
{
	while (stacks->cheap->ra-- != 0)
		ra(stacks->a);
	while (stacks->cheap->rb-- != 0)
		rb(stacks->b);
	while (stacks->cheap->rr-- != 0)
		rr(stacks);
	while (stacks->cheap->rra-- != 0)
		rra(stacks->a);
	while (stacks->cheap->rrb-- != 0)
		rrb(stacks->b);
	while (stacks->cheap->rrr-- != 0)
		rrr(stacks);
	while (stacks->cheap->pb-- != 0)
		pb(stacks);
}

void	move_cheapest(t_stacks *stacks)
{
	struct t_moves	*moves;
	struct t_cheap	*cheap;
	t_values		*values;

	moves = ft_calloc(1, sizeof(t_moves));
	stacks->moves = moves;
	cheap = ft_calloc(1, sizeof(t_cheap));
	stacks->cheap = cheap;
	values = ft_calloc(1, sizeof(t_values));
	stacks->values = values;
	while (stacks->a->size != 3)
	{
        check_max_min_b(stacks);
        // printf("min_b: %d\n", stacks->values->min_b);
		// printf("max_b: %d\n", stacks->values->max_b);
		check_moves(stacks);
		do_cheap_moves(stacks);
	}
}

void sort_large(t_stacks **stacks)
{   
    pb(*stacks);
    pb(*stacks);
    move_cheapest(*stacks);
    sort_three(stacks);
    // move_stack_a(*stacks);
    // // find the number with least amount of moves to push to b in correct order
}