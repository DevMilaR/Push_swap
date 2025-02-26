#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include <limits.h>

typedef struct s_list
{
    int             number; //número almacenado en el nodo
    int             cheapest; //número mínimo de movimientos
    int			index;
	int				push_cost;
	int				above_median;
	struct s_list	*target_node;
    struct s_list   *next; //puntero al siguiente nodo de la lista
    struct s_list   *previous; //puntero al nodo anterior de la lista
} t_list;

int         is_valid_number(char *str);
int         has_duplicate(t_list *stack_a, int number);
void        free_errors(t_list **stack_a, char **argv, int free_argv);
void        free_string(char **argv);
void	    free_stack(t_list **stack);
void        ft_parse_arguments(t_list **stack_a, char **argv, int free_argv);
t_list      *find_last_node(t_list *list);
int         ft_atoi(const char *str);
int         ft_isdigit(int c);
void	    pa(t_list **a, t_list **b, bool print);
void	    pb(t_list **b, t_list **a, bool print);
void	    sa(t_list **a, bool print);
void	    sb(t_list **b, bool print);
void	    ss(t_list **a, t_list **b, bool print);
void	    ra(t_list **a, bool print);
void	    rb(t_list **b, bool print);
void	    rr(t_list **a, t_list **b, bool print);
void	    rra(t_list **a, bool print);
void	    rrb(t_list **b, bool print);
void	    rrr(t_list **a, t_list **b, bool print);
void        current_index(t_list *stack);
void        set_cheapest(t_list *stack);
void        init_nodes_a(t_list *stack_a, t_list *stack_b);
void        init_nodes_b(t_list *stack_a, t_list *stack_b);
void        min_on_top(t_list **stack_a);
int         main(int argc, char **argv);
void        sort_big_stacks(t_list **stack_a, t_list **stack_b);
void        sort_three(t_list **stack);
void        sort_stack(t_list **stack_a, t_list **stack_b);
bool        is_stack_sorted(t_list *stack);
void        sorting_stack(t_list **stack_a, t_list **stack_b);
int         ft_stack_size(t_list *stack);
int         stack_len(t_list *stack);
t_list      *get_cheapest(t_list *stack);
void        prep_for_push(t_list **stack, t_list *top_node, char stack_name);
t_list      *find_min(t_list *stack);
t_list      *find_max(t_list *stack);
size_t	    ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	    **ft_split(char const *s, char c);

#endif