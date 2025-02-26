#include "push_swap.h"

static void	move_b_to_a(t_list **stack_a, t_list **stack_b)
{
    prep_for_push(stack_a, (*stack_b)->target_node, 'a');
    pa(stack_a, stack_b, false);
}

static void	rotate_both(t_list **stack_a,	t_list **stack_b, t_list *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
		rr(stack_a, stack_b, false);
	current_index(*stack_a);
	current_index(*stack_b);
}

static void	rev_rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
		rrr(stack_a, stack_b, false);
	current_index(*stack_a);
	current_index(*stack_b);
}

static void	move_a_to_b(t_list **stack_a, t_list **stack_b)
{
{
	t_list	*cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(stack_a, stack_b, cheapest_node);
	prep_for_push(stack_a, cheapest_node, 'a');
	prep_for_push(stack_b, cheapest_node->target_node, 'b');
	pb(stack_b, stack_a, false);
}
}

void	sort_big_stacks(t_list **stack_a, t_list **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && !is_stack_sorted(**stack_a))
		pb(stack_b, stack_a, false);
	if (len_a-- > 3 && !is_stack_sorted(**stack_a))
		pb(stack_b, stack_a, false);
	while (len_a-- > 3 && !is_stack_sorted(**stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(*stack_a, *stack_b);
	}
	sort_three(*stack_a);
	while (*stack_b)
	{
		init_nodes_b(**stacka, **tack_b);
		move_b_to_a(a, b);
	}
	current_index(*stack_a);
	min_on_top(stack_a);
}
