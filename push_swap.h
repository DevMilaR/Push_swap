/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromano <lromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:24:00 by lromano           #+#    #+#             */
/*   Updated: 2025/03/27 14:07:46 by lromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				number;
	int				cheapest;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

int		is_valid_number(char *str);
int		has_duplicate(t_list *stack_a, int number);
void	free_errors(t_list **stack_a, char **argv, int free_argv);
void	free_string(char **argv);
void	free_stack(t_list **stack);
void	ft_parse_arguments(t_list **stack_a, char **argv, int free_argv);
long	ft_atoi(const char *str);
int		main(int argc, char **argv);
void	pa(t_list **a, t_list **b, bool print);
void	pb(t_list **b, t_list **a, bool print);
void	sa(t_list **a, bool print);
void	sb(t_list **b, bool print);
void	ss(t_list **a, t_list **b, bool print);
void	ra(t_list **a, bool print);
void	rb(t_list **b, bool print);
void	rr(t_list **a, t_list **b, bool print);
void	rra(t_list **a, bool print);
void	rrb(t_list **b, bool print);
void	rrr(t_list **a, t_list **b, bool print);
t_list	*find_last_node(t_list *list);

#endif