#include "push_swap.h"

void	sort_stack(t_list **stack_a, t_list **stack_b) //ordena la stack a dependiendo de su tamaño)
{
	int	size;

	size = ft_stack_size(*stack_a);
	if (size == 2)
		sa(stack_a, false);
	else if (size == 3)
		sort_three(stack_a);
	else
		sort_big_stacks(stack_a, stack_b);
}

bool	is_stack_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sorting_stack(t_list **stack_a, t_list **stack_b)
{
	if (!is_stack_sorted(*stack_a))
		sort_stack(stack_a, stack_b);
	return ;
}
