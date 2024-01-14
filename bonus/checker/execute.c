/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:12:58 by escura            #+#    #+#             */
/*   Updated: 2024/01/14 16:21:16 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	execute_s(char *line, t_stacks *stacks)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sb(stacks->a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(stacks->b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(stacks);
	else
		return (-1);
	return (0);
}

int	execute_p(char *line, t_stacks *stacks)
{
	if (ft_strcmp(line, "pa\n") == 0)
		pa(stacks);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(stacks);
	else
		return (-1);
	return (0);
}

int	execute_r(char *line, t_stacks *stacks)
{
	if (ft_strcmp(line, "ra\n") == 0)
		ra(stacks->a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(stacks->b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(stacks);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(stacks->a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(stacks->b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(stacks);
	else
		return (-1);
	return (0);
}

void	execute_operations(char *line, t_stacks *stacks, int fd)
{
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (execute_s(line, stacks) == -1 && execute_p(line, stacks) == -1
			&& execute_r(line, stacks) == -1)
			ft_putendl_fd("Error\n", 1);
		free(line);
		line = get_next_line(fd);
	}
}
