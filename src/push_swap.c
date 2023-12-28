/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:45:11 by escura            #+#    #+#             */
/*   Updated: 2023/12/18 22:08:12 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	show_results(t_stacks *stacks)
{
	int	i;

	i = 0;
	printf("Stack A: ");
	while (i < stacks->a->size)
	{
		printf("%d ", stacks->a->arr[i]);
		i++;
	}
	printf("\nStack B: ");
	i = 0;
	while (i < stacks->b->size)
	{
		printf("%d ", stacks->b->arr[i]);
		i++;
	}
	printf("\n");
}

int	main(int nb, char **args)
{
	t_stacks	*stacks;
	stacks = malloc(sizeof(t_stacks));
	if (stacks == NULL)
		ft_error("Error: malloc failed", NULL);

	// Init stack
	init_stacks(&stacks);

	// Read args and check for errors
	read_args(nb, args, &stacks);

	// sort the stack
	sort(&stacks);

	// show results
	show_results(stacks);

	// free memory
	free_stacks(stacks);
	return (0);
}
