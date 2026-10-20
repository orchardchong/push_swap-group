NAME = push_swap
LIBFTPRINTF = ./ft_printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror
FUNCS	= disorder_metrics \
		  main \
		  parsing \
		  push \
		  reverse_rotation \
		  rotation \
		  stack \
		  swap \
		  to_clear_and_erase \
		  radix_utils \
		  radix \
<<<<<<< HEAD
		  adaptive \
		  selection \
		  is_sorted \
=======
		  chunk
>>>>>>> 680898dfe8041dff099c1fe27bf779d5afd44c15

SRCS = $(FUNCS:=.c)
OBJS = $(SRCS:.c=.o)

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

# gdb runs on the compiled program, i.e gdb ./a.out.
# if a.out is not compiled with -g, then mapping of
# source lines to machine address is not known.
# Example:
# 	 main.c:4  has runtime address of 0x40112a
# Without -g, gdb cannot recognize 0x40112a as line 4 
# of main.c, so machine address is needed to set breakpoint.
# set the breakpoint at machine code level.

# push_swap.h included ft_printf.h, ft_printf.h included
# libft.h, so need to tell compiler where to find them using
# -I
%.o: %.c push_swap.h
	cc $(CFLAGS) -c -g -I ./libft -I ./ft_printf $< -o $@ 

fclean: clean
	make fclean -C ./ft_printf
	rm -f $(NAME)

clean:
	make clean -C ./ft_printf
	rm -f $(OBJS)

re: fclean all

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap $(ARGS)

.PHONY: all clean fclean re valgrind