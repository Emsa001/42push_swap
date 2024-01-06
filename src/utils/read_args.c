/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:08:31 by escura            #+#    #+#             */
/*   Updated: 2023/12/18 16:36:26 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	check_duplicates(t_stack *stack)
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
                return -1;
            j++;
        }
        i++;
    }

	return 0;
}

long int process_arg(char *arg, int *sign)
{
	long int num = 0;
	int j = 0;

	while (arg[j])
	{
		if (arg[j] == '-')
		{
			if (*sign == -1)
				return -1;
			*sign = -1;
			j++;
		}
		else if (!ft_isdigit(arg[j]))
			return -1;
		num = num * 10 + arg[j] - '0';
		if (num > INT_MAX)
			return -1;
		j++;
	}

	return num;
}

int multi_args(char **args, t_stack **stack)
{
	int i;
	int sign;
	long int num;

	sign = 1;
	i = 1;

	while (args[i])
	{
		num = process_arg(args[i], &sign);
		if (num == -1)
			return -1;
		(*stack)->arr[i - 1] = (int)num * sign;
		(*stack)->size++;
		i++;
		sign = 1;
	}

	return 0;
}

void read_args(int nb, char **args, t_stacks **stacks)
{
	int n = 0;
	while (args[n]) n++; 

	(*stacks)->a->arr = (int *)malloc((n - 1) * sizeof(int));
	(*stacks)->b->arr = (int *)malloc((n - 1) * sizeof(int));

	if ((*stacks)->a == NULL || (*stacks)->b == NULL) {
		ft_error("Error", *stacks);
	}

	if (nb < 2)
		ft_error(NULL, *stacks);

	if(multi_args(args,&(*stacks)->a) == -1){
		ft_error("Error", *stacks);
	}
	if(check_duplicates((*stacks)->a) == -1){
		ft_error("Error", *stacks);
	}
}