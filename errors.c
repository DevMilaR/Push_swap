#include "push_swap.h" /*Manejo de errores y validaciones*/

void free_stack(t_list **stack)
{
    t_list *temp;

    if (!stack || !*stack)  // Verifica si stack es NULL o está vacío
        return;

    while (*stack)
    {
        temp = (*stack)->next;  
        free(*stack);  
        *stack = temp;  
    }
    *stack = NULL;  // Asegura que el puntero quede en NULL después de liberar
}

void free_string(char **argv)
{
    int i;

    if (!argv)  // Si argv es NULL, no hay nada que liberar
        return;

    i = 0;
    while (argv[i])  // Recorremos cada string dentro del array
    {
        free(argv[i]);  // Liberamos la memoria de cada string
        i++;
    }
    free(argv);  // Finalmente, liberamos el array de punteros
}

void free_errors(t_list **stack_a, char **argv, int free_argv)
{
    if (free_argv)  // Si args_provided es distinto de 0 (true), libera los argumentos
        free_string(argv);  // Libera memoria de los argumentos
    free_stack(stack_a);  // Libera la pila
    write(2, "Error\n", 6);  // Escribe "Error" en stderr
    exit(1);  // Termina el programa indicando un error
}

int is_valid_number(char *str) 
{
    if (!str || !(*str)) // Verifica si el string es NULL o vacío
        return (0);
    if (*str == '+' || *str == '-') // Si empieza con signo
        str++;
    if (!ft_isdigit(*str)) // Debe haber al menos un dígito después del signo
        return (0);
    while (*str) 
    {
        if (!ft_isdigit(*str))
            return (0);
        str++;
    }
    return (1);
}

int has_duplicate(t_list *stack_a, int number)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a->number == number)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
