*This project has been created as part of the 42 curriculum by junlim.*

# Libft

## Description

**Libft** is a custom C library that reimplements a set of standard C library
(`libc`) functions from scratch, along with several additional utility and
linked-list functions. The goal of the project is to build a solid
understanding of how these fundamental functions work internally, and to
produce a small, reusable toolbox (`libft.a`) that can be reused throughout
the rest of the 42 curriculum.

The library is split into three parts:

- **Part 1 — Libc functions**: Reimplementations of standard C functions each
  prefixed with `ft_`.
- **Part 2 — Additional functions**: Functions for string manipulation and file descriptors outputs.
- **Part 3 — Linked list**: A singly linked list with creation, insertion, iteration, mapping, and cleanup operations.

## Instructions

### Compilation

The project is built with a `Makefile` that respects the standard 42 rules
and compiles every `.c` file with `-Wall -Wextra -Werror`.

```bash
make        # compiles *.c files into *.o files, archived into libft.a
make clean  # removes *.o
make fclean # removes *.o then libft.a
make re     # recompile everything and creates libft.a
```

### Usage

Once compiled, `libft.a` can be linked against a .c file that has `main()`:

```bash
cc your_program.c -L. -lft -I. -o your_program
```

Include the header in your source files to access the prototypes:

```c
#include "libft.h"
```

## Library Overview

### Character classification

- `ft_isalpha` — checks if a character is an alphabetic letter (a-z, A-Z)
- `ft_isdigit` — checks if a character is a digit (0-9)
- `ft_isalnum` — checks if a character is alphabetic or a digit
- `ft_isascii` — checks if a character is within the ASCII range (0-127)
- `ft_isprint` — checks if a character is printable (including space)

### Character conversion

- `ft_toupper` — converts a lowercase letter to uppercase
- `ft_tolower` — converts an uppercase letter to lowercase

### Memory (raw buffers)

- `ft_memset` — fills a block of memory with a given byte value
- `ft_bzero` — fills a block of memory with zero bytes
- `ft_memcpy` — copies a block of memory to another (non-overlapping)
- `ft_memmove` — copies a block of memory to another (handles overlap safely)
- `ft_memchr` — searches for a byte within a block of memory
- `ft_memcmp` — compares two blocks of memory byte by byte

### Allocation

- `ft_calloc` — allocates zero-initialized memory for an array of elements
- `ft_strdup` — duplicates a string into newly allocated memory

### String length & copy

- `ft_strlen` — returns the length of a null-terminated string
- `ft_strlcpy` — copies a string into a buffer with a size limit
- `ft_strlcat` — appends a string to a buffer with a size limit

### String search & compare

- `ft_strchr` — finds the first occurrence of a character in a string
- `ft_strrchr` — finds the last occurrence of a character in a string
- `ft_strncmp` — compares two strings up to a given number of characters
- `ft_strnstr` — finds the first occurrence of a substring within a length limit

### Conversion

- `ft_atoi` — converts a string to an integer
- `ft_itoa` — converts an integer to a newly allocated string

### String manipulation

- `ft_substr` — extracts a substring from a string
- `ft_strjoin` — concatenates two strings into a newly allocated string
- `ft_strtrim` — trims leading/trailing characters from a string
- `ft_split` — splits a string into an array of substrings by a delimiter
- `ft_strmapi` — applies a function to each character of a string, building a new string
- `ft_striteri` — applies a function to each character of a string in place

### File descriptor output

- `ft_putchar_fd` — writes a character to a given file descriptor
- `ft_putstr_fd` — writes a string to a given file descriptor
- `ft_putendl_fd` — writes a string followed by a newline to a given file descriptor
- `ft_putnbr_fd` — writes an integer to a given file descriptor

### Linked list

- `ft_lstnew` — creates a new list node
- `ft_lstadd_front` — adds a node to the front of a list
- `ft_lstsize` — counts the number of nodes in a list
- `ft_lstlast` — returns the last node of a list
- `ft_lstadd_back` — adds a node to the end of a list
- `ft_lstdelone` — deletes a single node and its content
- `ft_lstclear` — deletes and frees an entire list
- `ft_lstiter` — applies a function to each node's content
- `ft_lstmap` — creates a new list by applying a function to each node's content

## Resources

- [The Linux `man` pages](https://man7.org/linux/man-pages/) —
  reference for the prototypes and behavior of every reimplemented libc
  function.
- [Neso Academy's Introduction to linked list in C](https://www.youtube.com/watch?v=R9PTBwOzceo&list=PLpYOpjNLz0aGIL9xaFHbw16uEmFxzy2rs) — helps with understanding basic of linked list.
- [Makefile tutorial](https://makefiletutorial.com/#pattern-rules) —
 recompilation and clean up becomes an easier process when setting up or changes are made.

**Use of AI**:
- Review already-written implementations and point out issues or edge cases. Sparks discussion of trade-offs to have better understanding.
- Do README and summarized notes in the format of inline comments.