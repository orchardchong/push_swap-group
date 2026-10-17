NAME = push_swap.a
CFLAGS = -Wall -Wextra -Werror
FUNCS	= disorder_metrics \
		  main \
		  parsing \
		  push \
		  reverse_rotation \
		  rotation \
		  stack \
		  swap \
		  to_clear_and_erase

SRCS = $(FUNCS:=.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

# -C run the make command in ft_printf
# rename libftprintf.a -> push_swap.a
# recompile and update push_swap.a with push_swap's .o files
# location of headers is not stored in .a
$(NAME): $(OBJS)
	make -C ./ft_printf 
	cp ./ft_printf/libftprintf.a $(NAME) 
	ar rcs $(NAME) $(OBJS) 

# -I finds "libft.h" in sub dir
# $@ name of object files follow by target names
# $< is the first prerequisite
%.o: %.c
	cc $(CFLAGS) -c -I ./libft -I ./ft_printf $< -o $@ 

# gdb runs on the compiled program, i.e gdb ./a.out.
# if a.out is not compiled with -g, then mapping of
# source lines to machine address is not known.
# Example:
# 	 main.c:4  has runtime address of 0x40112a
# Without -g, gdb cannot recognize 0x40112a as line 4 
# of main.c, so machine address is needed to set breakpoint.
# set the breakpoint at machine code level.
debug:
	cc -g $(CFLAGS) -I ./libft -I ./ft_printf $(MAIN) $(NAME)

fclean: clean
	make fclean -C ./libft
	make fclean -C ./ft_printf
	rm -f $(NAME)

clean:
	make clean -C ./libft
	make clean -C ./ft_printf
	rm -f $(OBJS)

re: fclean all

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out

.PHONY: all clean fclean re valgrind debug