/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromano <lromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:09:39 by lromano           #+#    #+#             */
/*   Updated: 2025/03/27 14:17:20 by lromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sorted_stack(t_list **a, t_list **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sa(a, false);
	else if (size == 3)
		three_to_sort(a);
	else
		big_stack_to_sort(a, b);
}

bool	stack_is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	push_swap(t_list **a, t_list**b)
{
	if (!stack_is_sorted(*a))
		sorted_stack(a, b);
	return (0);
}
