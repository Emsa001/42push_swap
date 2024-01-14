/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:31:18 by escura            #+#    #+#             */
/*   Updated: 2024/01/14 17:01:13 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static int	check_duplicates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < (stack)->size)
	{
		j = i + 1;
		while (j < (stack)->size)
		{
			if ((stack)->arr[i] == (stack)->arr[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static long int	process_atoi(char *arg, int *j, int *sign)
{
	long int	num;

	num = 0;
	while (arg[*j])
	{
		if ((arg[*j] == '-' || arg[*j] == '+') && (*sign != -1 && *sign != 2))
		{
			if (arg[*j] == '-')
				*sign = -1;
			else
				*sign = 2;
			(*j)++;
		}
		else
		{
			if (!ft_isdigit(arg[*j]) || num > (INT_MAX - (arg[*j] - '0')) / 10)
				return (-1);
			num = num * 10 + arg[*j] - '0';
			(*j)++;
		}
	}
	return (num);
}

static long int	process_arg(char *arg, int *sign)
{
	long int	num;
	int			j;

	j = 0;
	num = process_atoi(arg, &j, sign);
	if (j == 1 && (arg[0] == '-' || arg[0] == '+'))
		return (-1);
	return (num);
}

static int	multi_args(char **args, int i, int j, t_stacks **stacks)
{
	int			sign;
	long int	num;

	sign = 1;
	while (args[i])
	{
		num = process_arg(args[i], &sign);
		if (num == -1)
			return (-1);
		(*stacks)->a->arr[j] = (int)num * sign;
		(*stacks)->a->size++;
		sign = 1;
		i++;
		j++;
	}
	return (0);
}

void	read_args(int nb, char **args, t_stacks **stacks)
{
	char	**nums;

	init_arrays(stacks, count_size(nb, args));
	if (nb < 2)
		ft_error(NULL, *stacks);
	if (nb == 2)
	{
		nums = ft_split(args[1], ' ');
		if (nums == NULL)
			ft_error("Error", *stacks);
		if (multi_args(nums, 0, 0, stacks) == -1)
		{
			free_split(nums);
			ft_error("Error", *stacks);
		}
		free_split(nums);
	}
	else if (multi_args(args, 1, 0, stacks) == -1)
		ft_error("Error", *stacks);
	if (check_duplicates((*stacks)->a) == -1)
		ft_error("Error", *stacks);
}
