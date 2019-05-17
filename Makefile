NAME				= ft_select
SRC                 = src/ft_select.c \
					  src/t_arg_handling.c \
					  src/ft_move.c \
					  src/ft_select_exit.c \
					  src/read_directory.c \
					  src/ft_size.c \
					  src/tty_configure.c \
					  src/key_commands.c

LIB 				= libft/libft.a
CC                  = clang

.PHONY = all

all:
	@make --directory libft
	@echo "\033[32mft_select compiling...\033[0m"
	@$(CC) -I inc $(SRC) $(LIB)  -o ft_select -ltermcap
	@echo "\033[33mCompiled!\033[0m"


clean:

fclean:
	@rm -f ft_select
