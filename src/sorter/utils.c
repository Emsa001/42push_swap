/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:47:43 by escura            #+#    #+#             */
/*   Updated: 2023/12/18 22:19:37 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_max(t_stack *stack)
{
	int	i;
	int	max;
	int	index;

	i = 0;
	max = stack->arr[0];
	index = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] > max)
		{
			max = stack->arr[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	find_min(t_stack *stack)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = stack->arr[0];
	index = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] < min)
		{
			min = stack->arr[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int *sort_int_array(int *arr, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;
	temp = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size )
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int is_sorted(t_stack *stack)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < stack->size)
    {
        j = i + 1;
        while(j < stack->size )
        {
            if(stack->arr[i] > stack->arr[j])
                return (false);
            j++;
        }
		i++;
    }
    return (true);
}
