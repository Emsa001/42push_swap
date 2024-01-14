/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:11:42 by escura            #+#    #+#             */
/*   Updated: 2024/01/14 15:27:32 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int nb, char **args)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (stacks == NULL)
		ft_error("Error: malloc failed", NULL);
	init_stacks(&stacks);
	read_args(nb, args, &stacks);
	sort(&stacks);
	free_stacks(stacks);
	return (0);
}
