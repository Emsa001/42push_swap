#include "../../includes/push_swap.h"

static void	do_moves(t_stacks *stacks);


void	new_min_stack_a(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->a->arr[0] != stacks->values->min_a)
	{
		i = find_index_stack_a(stacks, stacks->values->min_a);
		size = stacks->a->size;
		if (size % 2 == 0)
		{
			if (i + 1 > size / 2)
				stacks->moves->rra = (size - i);
			else
				stacks->moves->ra = i;
		}
		else
		{
			if (i > size / 2)
				stacks->moves->rra = (size - i);
			else
				stacks->moves->ra = i;
		}
	}
	do_moves(stacks);
}

void	new_max_stack_a(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->a->arr[stacks->a->size - 1] != stacks->values->max_a)
	{
		i = find_index_stack_a(stacks, stacks->values->max_a);
		size = stacks->a->size;
		if (size % 2 == 0)
		{
			if (i + 1 > size / 2)
				stacks->moves->rra = (size - i) - 1;
			else
				stacks->moves->ra = i + 1;
		}
		else
		{
			if (i > size / 2)
				stacks->moves->rra = (size - i) - 1;
			else
				stacks->moves->ra = i + 1;
		}
	}
	do_moves(stacks);
    ra(stacks->a);
}

void	do_moves(t_stacks *stacks)
{
	while (stacks->moves->ra-- != 0)
		ra(stacks->a);
	while (stacks->moves->rra-- != 0)
		rra(stacks->a);
	pa(stacks);
}

