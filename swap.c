#include "push_swap.h"

static void swap(t_list **stack)
{
    t_list *temp;
    
    if (*stack == NULL || (*stack)->next == NULL)// Si la pila tiene menos de dos elementos, no se puede hacer swap
        return;
    temp = *stack;               // Guardamos el primer nodo
    *stack = (*stack)->next;     // El segundo nodo pasa a ser el primero
    temp->next = (*stack)->next; // El primer nodo ahora apunta al tercer nodo
    (*stack)->next = temp;       // El antiguo primer nodo pasa a ser el segundo
}

void	sa(t_list **a, bool print)
{
	swap(a);
	if (!print)
		write(1, "sa\n", 3);
}

void	sb(t_list **b, bool print)
{
	swap(b);
	if (!print)
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		write(1, "ss\n", 3);
}
