# push_swap
# push_swap-group
# push_swap-group
*This project has been created as part of the 42 curriculum by ochong, junlim*

# Description
Push_swap is an algorithmic sorting project that challenges developers to sort data on a stack with a highly restricted set of operations, aiming for the lowest possible number of actions. Utilizing two stacks (Stack A and Stack B), the program calculates the most efficient series of moves to sort a random sequence of integers in ascending order.

Rather than relying on standard array-based sorting, this project demands custom implementations that map to specific Push_swap operations (sa, pb, ra, rra, etc.), forcing strategic resource management and memory routing. The program evaluates an initial "disorder metric" and dynamically selects the most mathematically efficient sorting strategy based on the data size and entropy.

# Instructions
## Compilation

The project utilizes a Makefile for streamlined compilation.

1. Compile the program: make
2. Remove object files: make clean
3. Remove object files and executable: make fclean
4. Recompile entirely: make re