#include "../../includes/push_swap.h"

void	check_min_b(t_stacks *stacks);
void	check_max_b(t_stacks *stacks);

void	check_max_min_b(t_stacks *stacks)
{
	if (stacks->b->size > 0)
	{
		check_max_b(stacks);
		check_min_b(stacks);
	}
}

void	check_min_b(t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->values->min_b = stacks->b->arr[0];
	while (i < stacks->b->size)
	{
		if (stacks->values->min_b > stacks->b->arr[i])
			stacks->values->min_b = stacks->b->arr[i];
		i++;
	}
}

void	check_max_b(t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->values->max_b = stacks->b->arr[0];
	while (i < stacks->b->size)
	{
		if (stacks->values->max_b < stacks->b->arr[i])
			stacks->values->max_b = stacks->b->arr[i];
		i++;
	}
}
