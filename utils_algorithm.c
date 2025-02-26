#include "push_swap.h"

int	ft_stack_size(t_list *stack)
{
	int		size;
	t_list	*current;

	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}