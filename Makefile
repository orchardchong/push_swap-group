NAME = push_swap
LIBFTPRINTF = ./ft_printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I . -I ./libft -I ./ft_printf -I ./get_next_line

ALGO_DIR = src/algorithm
BONUS_DIR = src/bonus
MAIN_DIR = src/main
OPS_DIR = src/ops
NORM_DIRS = $(ALGO_DIR) $(BONUS_DIR) $(MAIN_DIR) $(OPS_DIR) get_next_line 

ALGO  = adaptive chunk radix_utils radix selection
MAIN  = bench disorder_metrics is_sorted main parsing stack to_clear_and_erase
OPS	  = push reverse_rotation rotation swap

FUNCS = $(addprefix $(ALGO_DIR)/, $(ALGO)) \
		$(addprefix $(MAIN_DIR)/, $(MAIN)) \
		$(addprefix $(OPS_DIR)/, $(OPS))

SRCS = $(FUNCS:=.c)
OBJS = $(SRCS:.c=.o)

BONUS_NAME = checker
BONUS_FUNCS = $(BONUS_DIR)/checker_bonus \
			  $(BONUS_DIR)/checker_utils_bonus \
			  get_next_line/get_next_line \

# checker reuses every push_swap object except main.o (two main())
BONUS_OBJS = $(BONUS_FUNCS:=.o) $(filter-out $(MAIN_DIR)/main.o, $(OBJS))


all: $(NAME)
# during linking ,-I flag is no needed.
# when *.c has changes, object files will be recompiled using -I. 
# Only compiles the updated *.c files

# Compiling *.o files with -g will be ignored by cc,
# the debug info such as line number is in *.c,
# -g during compiliation then will store the info in *.o
$(NAME): $(OBJS) $(LIBFTPRINTF)
	cc $(CFLAGS) $(OBJS) $(LIBFTPRINTF) -o $(NAME)

$(LIBFTPRINTF):
	make -C ./ft_printf

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFTPRINTF)
	cc $(CFLAGS) $(BONUS_OBJS) $(LIBFTPRINTF) -o $(BONUS_NAME)


visual: 
	rm -f $(BONUS_DIR)/checker_bonus.o
	make bonus CFLAGS="$(CFLAGS) -D VISUAL=1"
	rm -f $(BONUS_DIR)/checker_bonus.o
# gdb runs on the compiled program, i.e gdb ./a.out.
# if a.out is not compiled with -g, then mapping of
# source lines to machine address is not known.
# Example:
# 	 main.c:4  has runtime address of 0x40112a
# Without -g, gdb cannot recognize 0x40112a as line 4 
# of main.c, so machine address is needed to set breakpoint.
# set the breakpoint at machine code level.

# push_swap.h included ft_printf.h, ft_printf.h included
# libft.h, so need to tell compiler where to find them using -I
%.o: %.c push_swap.h
	cc $(CFLAGS) -c -g  $(INCLUDES) $< -o $@

# Only recompile funcs in bonus/ when checker_bonus.h changes
$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c $(BONUS_DIR)/checker_bonus.h push_swap.h
	cc $(CFLAGS) -c -g  $(INCLUDES) $< -o $@

fclean: clean
	make fclean -C ./ft_printf
	rm -f $(NAME) $(BONUS_NAME)

clean:
	make clean -C ./ft_printf
	rm -f $(OBJS) $(BONUS_OBJS)

re: fclean all

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap $(ARGS)

norm:
	norminette $(NORM_DIRS) push_swap.h
.PHONY: all clean fclean re valgrind bonus visual norm