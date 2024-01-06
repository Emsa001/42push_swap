#include "../../includes/push_swap.h"

int	find_index_stack_b(t_stacks *stacks, int nbr)
{
	t_stack	*head_b;
	int			i;

	i = 0;
	head_b = stacks->b;
	while (i < head_b->size)
	{
		if (head_b->arr[i] == nbr)
			break ;
		i++;
	}
	return (i);
}

int search_num_stack_b(t_stacks *stacks, int nbr)
{
	t_stack	*head_b;
	int			size;
	int			flag;
	int			i;
	int j = 0;

	i = 0;
	flag = 0;
	head_b = stacks->b;
	size = head_b->size;
	while (flag == 0)
	{
		i = 0;
		nbr--;
		j = 0;
		while (i++ < size)
		{
			if (head_b->arr[j] == nbr)
				flag = 1;
			j++;
		}
	}
	return (nbr);
}

void	new_max_or_min_stack_b(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;

	i = find_index_stack_b(stacks, stacks->values->max_b);
	if (stacks->b->arr[0] == stacks->values->max_b)
		return ;
	// printf("	i: %d\n", i);
	size = stacks->b->size;
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
	else
	{
		if (i > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
}

void	new_num_in_stack_b(t_stacks *stacks, int num)
{
	int	i;
	int	size;
	int	nbr;

	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	nbr = search_num_stack_b(stacks, num);
	if(stacks->b->arr[0] == nbr)
		return ;
	i = find_index_stack_b(stacks, nbr);
	size = stacks->b->size;
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
	else
	{
		if (i > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
}
