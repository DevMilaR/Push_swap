#include "push_swap.h"

static void    push(t_list **src, t_list **dest)
{
    t_list *temp;

    if (*src == NULL)  // Si la pila de origen está vacía, no hay nada que hacer
        return;
    temp = *src;        // Guardamos el primer nodo de la pila de origen
    *src = (*src)->next;  // El segundo nodo de la pila de origen pasa a ser el primero
    temp->next = *dest;   // El primer nodo de la pila de origen ahora apunta a la pila de destino
    *dest = temp;         // El primer nodo de la pila de origen se convierte en el primer nodo de la pila de destino
}

void	pa(t_list **a, t_list **b, bool print)
{
	push(a, b);
	if (!print)
		write(1, "pa\n", 3);
}

void	pb(t_list **b, t_list **a, bool print)
{
	push(b, a);
	if (!print)
		write(1, "pb\n", 3);
}
