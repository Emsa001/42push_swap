#include "../../includes/push_swap.h"

void print_cost(t_stacks *stacks)
{
    printf("	cost: %d\n", stacks->cheap->cost);
    printf("	pb: %d\n", stacks->cheap->pb);
    printf("	ra: %d\n", stacks->cheap->ra);
    printf("	rb: %d\n", stacks->cheap->rb);
    printf("	rr: %d\n", stacks->cheap->rr);
    printf("	rra: %d\n", stacks->cheap->rra);
    printf("	rrb: %d\n", stacks->cheap->rrb);
    printf("	rrr: %d\n", stacks->cheap->rrr);
}

void	check_moves(t_stacks *stacks)
{
	int			i;
	t_stack	    *a;

	a = stacks->a;
	i = 0;
	while (i++ < a->size)
	{
		get_top_stack_a(stacks, i - 1);
		if (a->arr[i- 1] > stacks->values->max_b || \
			a->arr[i - 1] < stacks->values->min_b)
			new_max_or_min_stack_b(stacks);
		else
			new_num_in_stack_b(stacks, a->arr[i - 1]);
		check_double_moves(stacks);
		check_cost(stacks, i);
        // print_cost(stacks);
	}
}

void	check_cost(t_stacks *stacks, int i)
{
	stacks->moves->cost = stacks->moves->pb + stacks->moves->ra
		+ stacks->moves->rb + stacks->moves->rr + stacks->moves->rra
		+ stacks->moves->rrb + stacks->moves->rrr;
	if (i == 1 || (stacks->cheap->cost > stacks->moves->cost))
	{
		stacks->cheap->cost = stacks->moves->cost;
		stacks->cheap->pb = stacks->moves->pb;
		stacks->cheap->ra = stacks->moves->ra;
		stacks->cheap->rb = stacks->moves->rb;
		stacks->cheap->rr = stacks->moves->rr;
		stacks->cheap->rra = stacks->moves->rra;
		stacks->cheap->rrb = stacks->moves->rrb;
		stacks->cheap->rrr = stacks->moves->rrr;
	}
}

void	check_double_moves(t_stacks *stacks)
{
	stacks->moves->rr = 0;
	stacks->moves->rrr = 0;
	while (stacks->moves->ra != 0 && stacks->moves->rb != 0)
	{
		stacks->moves->ra--;
		stacks->moves->rb--;
		stacks->moves->rr++;
	}
	while (stacks->moves->rra != 0 && stacks->moves->rrb != 0)
	{
		stacks->moves->rra--;
		stacks->moves->rrb--;
		stacks->moves->rrr++;
	}
}
