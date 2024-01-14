/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:58:57 by escura            #+#    #+#             */
/*   Updated: 2024/01/14 16:16:33 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	free_stacks(t_stacks *stacks)
{
	if ((stacks)->a->arr != NULL)
		free((stacks)->a->arr);
	if ((stacks)->b->arr != NULL)
		free((stacks)->b->arr);
	free((stacks)->a);
	free((stacks)->b);
	free(stacks);
}

void	ft_error(char *msg, t_stacks *stacks)
{
	if (msg != NULL)
		ft_putendl_fd(msg, 1);
	if (stacks != NULL)
		free_stacks(stacks);
	exit(0);
}

void	init_stacks(t_stacks **stacks)
{
	(*stacks)->a = malloc(sizeof(t_stack));
	if ((*stacks)->a == NULL)
		ft_error("Error: malloc failed", *stacks);
	(*stacks)->b = malloc(sizeof(t_stack));
	if ((*stacks)->b == NULL)
		ft_error("Error: malloc failed", *stacks);
	(*stacks)->a->arr = NULL;
	(*stacks)->b->arr = NULL;
	(*stacks)->a->size = 0;
	(*stacks)->b->size = 0;
}

void	init_arrays(t_stacks **stacks, int n)
{
	(*stacks)->a->arr = (int *)malloc((n - 1) * sizeof(int));
	(*stacks)->b->arr = (int *)malloc((n - 1) * sizeof(int));
	if ((*stacks)->a->arr == NULL || (*stacks)->b->arr == NULL)
		ft_error("Error", *stacks);
}

int	is_sorted(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->arr[i] > stack->arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
