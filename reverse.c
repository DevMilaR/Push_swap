#include "push_swap.h"

static void reverse_rotate(t_list **stack)
{
    t_list *temp;
    t_list *second_last;
    
    if (*stack == NULL || (*stack)->next == NULL)// Si la pila tiene menos de dos elementos, no se puede hacer reverse rotate
        return;
    temp = *stack;
    while (temp->next)// Buscamos el último nodo
    {
        second_last = temp;
        temp = temp->next;
    }
    second_last->next = NULL;  // El penúltimo nodo ahora apunta a NULL
    temp->next = *stack;       // El último nodo ahora apunta al primer nodo
    *stack = temp;             // El último nodo ahora pasa a ser el primer nodo
}

void	rra(t_list **a, bool print)
{
	reverse_rotate(a);
	if (!print)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b, bool print)
{
	reverse_rotate(b);
	if (!print)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		write(1, "rrr\n", 4);
}
