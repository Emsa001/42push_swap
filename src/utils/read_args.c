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

int	multi_args(char **args, t_stack **stack)
{
	int			i;
	int			j;
	int			sign;
	long int	num;

	sign = 1;
	i = 1;
	j = 0;
	
	while (args[i])
	{
		num = 0;
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == '-')
			{
				if (sign == -1)
					return -1;
				sign = -1;
				j++;
			}
			else if (!ft_isdigit(args[i][j]))
				return -1;
			num = num * 10 + args[i][j] - '0';
			if (num > INT_MAX)
				return -1;
			j++;
		}
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