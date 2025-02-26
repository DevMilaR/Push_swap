#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	int	val1;
	int	val2;
	int	val3;

	val1 = (*stack_a)->nbr;
	val2 = (*stack_a)->next->nbr;
	val3 = (*stack_a)->next->next->nbr;
	if (val1 > val2 && val2 > val3)
	{
		sa(stack_a, false);
		rra(stack_a, false);
	}
	else if (val1 > val2 && val2 < val3 && val1 > val3)
		ra(stack_a, false);
	else if (val1 > val3 && val2 < val3)
		ra(stack_a, false);
	else if (val1 < val2 && val2 > val3 && val1 > val3)
		rra(stack_a, false);
	else if (val1 < val2 && val2 > val3 && val1 < val3)
	{
		sa(stack_a, false);
		ra(stack_a, false);
	}
	else if (val1 > val2 && val2 < val3 && val1 < val3)
		sa(stack_a, false);
}
