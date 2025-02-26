#include "push_swap.h"

static void rotate(t_list **stack)
{
    t_list *temp;
    t_list *last;
    
    if (*stack == NULL || (*stack)->next == NULL)  // Si la pila tiene menos de dos elementos, no se puede hacer rotate
        return;
    temp = *stack;              // Guardamos el primer nodo
    *stack = (*stack)->next;    // El segundo nodo pasa a ser el primero
    temp->next = NULL;          // El antiguo primer nodo ya no apunta a nada
    last = *stack;
    while (last->next)          // Buscamos el último nodo
        last = last->next;
    last->next = temp;          // El antiguo primer nodo ahora apunta al final de la pila
}

void	ra(t_list **a, bool print)
{
	rotate(a);
	if (!print)
		write(1, "ra\n", 3);
}

void	rb(t_list **b, bool print)
{
	rotate(b);
	if (!print)
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		write(1, "rr\n", 3);
}
