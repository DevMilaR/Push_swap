/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromano <lromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:21:48 by lromano           #+#    #+#             */
/*   Updated: 2025/02/27 17:48:17 by lromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_last_node(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

static void	add_node_to_stack(t_list **stack, int number)
{
	t_list	*node;
	t_list	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->next = NULL;
	node->number = number;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->previous = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->previous = last_node;
	}
}

void	ft_parse_arguments(t_list **stack_a, char **argv, int free_argv)
{
	long	number;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (is_valid_number(argv[i]))
			free_errors(stack_a, argv, free_argv);
		number = ft_atoi(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			free_errors(stack_a, argv, free_argv);
		if (has_duplicate(*stack_a, (int)number))
			free_errors(stack_a, argv, free_argv);
		add_node_to_stack(stack_a, (int)number);
		i++;
	}
}
