/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:10:12 by escura            #+#    #+#             */
/*   Updated: 2024/01/14 16:18:19 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../includes/libft/libft.h"

# define BUFFER_SIZE 3

typedef struct s_stack
{
	int		*arr;
	int		size;
}			t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}			t_stacks;

void		init_stacks(t_stacks **stack);
void		init_arrays(t_stacks **stacks, int n);
void		ft_error(char *msg, t_stacks *stacks);
void		free_stacks(t_stacks *stacks);
int			is_sorted(t_stack *stack);
void		read_args(int nb, char **args, t_stacks **stacks);
int			is_space(char c);
void		free_split(char **arg);
int			count_size(int nb, char **args);
char		*free_join(char *buffer, char *buf);
void		execute_operations(char *line, t_stacks *stacks, int fd);
int			ft_strcmp(char *s1, char *s2);
char		*get_next_line(int fd);

void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stacks *stacks);

void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);

void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stacks *stacks);

void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stacks *stacks);

#endif
