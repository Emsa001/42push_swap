#include "../../includes/push_swap.h"

int	search_stack_a(t_stacks *stacks, int nbr);
void	do_moves_elem_stack_a(t_stacks *stacks);

void	new_elem_stack_a(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->a->arr[0] != search_stack_a(stacks, stacks->b->arr[0]))
	{
		i = find_index_stack_a(stacks, search_stack_a(stacks, stacks->b->arr[0]));
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
	do_moves_elem_stack_a(stacks);
}

void	do_moves_elem_stack_a(t_stacks *stacks)
{
	while (stacks->moves->ra-- != 0)
		ra(stacks->a);
	while (stacks->moves->rra-- != 0)
		rra(stacks->a);
	pa(stacks);
}

int	search_stack_a(t_stacks *stacks, int nbr)
{
	t_stack	*head_a;
	int			size;
	int			flag;
	int			i;

	i = 0;
	flag = 0;
	head_a = stacks->a;
    size = stacks->a->size;
	while (flag == 0)
	{
		i = 0;
		nbr++;
		head_a = stacks->a;
		while (i++ < size)
		{
			if (head_a->arr[i - 1] == nbr)
				flag = 1;
		}
	}
	return (nbr);
}