
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)//si hay un solo argumento 
	{
		argv = ft_split(argv[1], ' '); //divide el arg en varios números, separados por espacios//
		ft_parse_arguments(&stack_a, argv, 1); //llena la pila A con los números obtenidos de argv
		free_string(argv);
	}
	else //si recibe más de 2 arg significa que los números están separados en los diferentes arg de la línea de comando
		ft_parse_arguments(&stack_a, argv + 1, 0); //se pasa argv + 1, ignorando que el primer argumento es el nombre del programa
	sorting_stack(&stack_a, &stack_b); //función principal para ordenar las pilas
	free_stack(&stack_a);
	return (0);
}
