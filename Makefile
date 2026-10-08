NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
FUNCS	= ft_printf \
		  ft_convert_c \
		  ft_convert_s \
		  ft_convert_p \
		  ft_convert_d_i \
		  ft_convert_u \
		  ft_convert_x \
		  ft_convert_upper_x \
		  ft_utoa_base

SRCS = $(addprefix ft_printf/, $(FUNCS:=.c))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

# -C run the make command in libft to create libft.a
# rename libft.a -> libftprintf.a
# recompile and update libftprintf.a with ftprintf's .o files
$(NAME): $(OBJS)
	make -C ./libft 
	cp ./libft/libft.a $(NAME) 
	ar rcs $(NAME) $(OBJS) 

# -I finds "libft.h" in sub dir
# $@ name of object files follow by target names
# $< is the first prerequisite
%.o: %.c ft_printf/ft_printf.h
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
	rm -f $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJS)

re: fclean all

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out

.PHONY: all clean fclean re valgrind debug