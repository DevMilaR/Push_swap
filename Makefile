NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

#colors 
YELLOW = \033[1;33m
GREEN = \033[1;32m
RED = \033[1;31m
NC = \033[0m

SRC_FILES = srcs/errors.c srcs/parser.c srcs/ft_printf/ft_printf.c\
			srcs/push.c srcs/swap.c srcs/rotate.c srcs/reverse.c \
			srcs/ft_printf/ft_putchar.c srcs/ft_printf/ft_putnbr.c srcs/ft_printf/ft_putstr.c\
			srcs/init_a_to_b.c srcs/main.c srcs/init_b_to_a.c srcs/min_on_top.c \
			srcs/sort_big_stack.c srcs/sort_small_stack.c srcs/sorting_stack.c \
			srcs/utils_algorithm.c srcs/utils_parsing.c srcs/utils_stack.c srcs/ft_split.c
		
OBJS = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
		@echo "$(YELLOW)Linking object files...$(NC)"
		$(CC) $(OBJS) $(LIBS) $(MLXFLAGS) -o $(NAME)
		@echo "$(GREEN)Executable $(NAME) created!$(NC)"
	
%.o: %.c
	@echo "$(YELLOW)Compiling: $<$(NC)"
	@$(CC) $(CFLAGS) -o $@ -c $< 
	@echo "$(GREEN)Compiled! $<$(NC)"
	
clean:
	@$(RM) $(OBJS)
	@echo "$(RED)OBJS cleaned!$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)EXECUTABLE cleaned!$(NC)"

re: fclean all

.PHONY: all clean fclean re