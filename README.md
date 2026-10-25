
*This project has been created as part of the 42 curriculum by ochong, junlim.*

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

## Execution
1. Standard Execution

        ./push_swap 23 16 7712 19 2 917 7

2. Force a specific algorithm strategy

        ./push_swap --simple 5 4 3 2 1
        ./push_swap --medium 67 87 12 457
        ./push_swap --complex 157 18 3 72

3. To view bench

        ./push_swap --bench 52 143 8 819

## Algorithm Explanation
### Simple Algorithm
#### Implementation
Selection Sort Adaptation
#### Justification
Ideal for small datasets (e.g., the 5-number test). The algorithm locates the smallest integer in Stack A and pushes it to Stack B. A critical optimization calculates the median index of the stack: if the target number is in the top half, we use ra (rotate up); if in the bottom half, we use rra (reverse rotate down).

### Medium Algorithm
#### Implementation
Chunk-Based Sorting
#### Justification
 Designed for mid-sized datasets or data with moderate disorder metrics ($0.20 \le \text{disorder} < 0.50$). This approach partitions Stack A into $\sqrt{n}$ manageable chunks based on value ranges. It pushes these chunks to Stack B in stages, reducing the search space, before pushing them back to Stack A in the correct sequence.
### Complex Algorithm
#### Implementation
Radix-Sort
#### Justification
Required for large, highly disordered datasets (e.g., the 500-number test). Because our operations simulate bitwise shifts, a binary Radix sort processes the integers bit by bit (from Least Significant to Most Significant).

### Adaptive Algorithm
#### Implementation
Auto Allocation based on Disorder Metric
#### Justification
< 0.20 Disorder: Routes to Simple $O(n^2)$

< 0.50 Disorder: Routes to Medium $O(n\sqrt{n})$

$\ge$ 0.50 Disorder: Routes to Complex $O(n \log n)$

# Resources & AI Usage
Youtube - The Explanation of the overall project flows and getting information from there

AI Usage 
- Tracing the root cause of Segmentation fault
- Brainstorming ideas on the project flow together
