/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:58:57 by escura            #+#    #+#             */
/*   Updated: 2023/12/18 16:39:48 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void free_stacks(t_stacks *stacks) {
    if ((stacks)->a->arr != NULL) {
        free((stacks)->a->arr);
    }
    if ((stacks)->b->arr != NULL) {
        free((stacks)->b->arr);
    }
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
	(*stacks)->a->name = 'a';
	(*stacks)->b->name = 'b';
}
