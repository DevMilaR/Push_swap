#include "push_swap.h"
#include <stdio.h>

/*Paso 1: 1.1. Leer los argumentos de la línea de comandos:
Procesar los números que se pasan como parámetros al ejecutar
el programa. 
1.2. Validar la entrada: Verificar que cada argumento sea un número válido,
sin caracteres extraños y que no existan duplicados
ni números fuera del rango permitido
1.3, Almacenar los datos en una estructura:
Convertir los números (cadenas de texto) eb números enteros,
e insertarlos en la estructura de nodo t_list que se definió stack_a
*/

t_list	*find_last_node(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

static void add_node_to_stack(t_list **stack, int number)
{ //agregar un nuevo nodo al final de la lista stack//
	t_list	*node;
	t_list	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->next = NULL; //el nuevo nodo, por ahora, no tiene un nodo siguiente//
	node->number = number; //se almacena el númerp que se pasa como arg en el nodo//
	node->cheapest = 0; //se inicializa en cero//
	if (!(*stack)) //si el stack está vacío//
	{
		*stack = node; //el nuevo nodo será el primer elemento//
		node->previous = NULL; //como es el primer nodo no tiene nodo anterior//
	}
	else //SI EL STACK NO ESTÁ VACÍO//
	{
		last_node = find_last_node(*stack); //encuentra el último nodo de la lista//
		last_node->next = node; //se enlaza el nuevo nodo al final//
		node->previous = last_node; //se enlaza el nuevo nodo con su nodo anterior//
	}
}

//EX: si el stack está vacío: stack -> ^[10] (prev = NULL, next = NULL)//
//si el stack no está vacío: stack antes [10]->[20]->[30] (prev <-> next)
//si agregamos 40 con add_node_to_stack (stack,40) la lista queda así:
// [10]->[20->[30]->[40] 
//donde 40 ->prev = 30// 30-> next = 40 
// 40 ->next = NULL (porque es el último nodo)


void ft_parse_arguments(t_list **stack_a, char **argv, int free_argv)
{
	long	number;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!is_valid_number(argv[i]))
			free_errors(stack_a, argv, free_argv);
		number = ft_atoi(argv[i]);
		if (number > INT_MAX || number < INT_MIN) /*valores posibles para un entero INT*/
			free_errors(stack_a, argv, free_argv);
		if (has_duplicate(*stack_a, (int)number))
			free_errors(stack_a, argv, free_argv);
		add_node_to_stack(stack_a, (int)number); /*se agrega el número a la pila*/
		i++;
	}
}
