/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:09:17 by escura            #+#    #+#             */
/*   Updated: 2024/01/14 17:01:32 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int nb, char **args)
{
	char		*line;
	int			fd;
	t_stacks	*stacks;

	line = NULL;
	fd = STDIN_FILENO;
	stacks = malloc(sizeof(t_stacks));
	if (stacks == NULL)
		ft_error("Malloc Error", NULL);
	init_stacks(&stacks);
	read_args(nb, args, &stacks);
	execute_operations(line, stacks, fd);
	if (is_sorted(stacks->a) && stacks->b->size == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stacks(stacks);
	return (0);
}
