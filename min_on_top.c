#include "push_swap.h"

void	min_on_top(t_list **stack_a)
{
	while ((*stack_a)->number != find_min(*stack_a)->number)
	{
		if (find_min(*stack_a)->above_median)
			ra(stack_a, false);
		else
			rra(stack_a, false);
	}
}
