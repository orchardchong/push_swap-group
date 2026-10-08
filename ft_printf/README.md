*This project has been created as part of the 42 curriculum by junlim.*

# ft_printf

## Description
ft_printf is a custom reimplementation of the C standard library's `printf()` function. It recreates the core behavior of `printf` using variadic arguments (`va_list`, `va_arg`), handling the conversions `cspdiuxX%`. The goal is to understand how format strings are parsed and how variadic functions work internally, without implementing the original `printf`'s buffer management. Since most of the functions can be resued from `libft`, only an extra function needed to convert unsigned values to string as `ft_itoa` only handles signed int.

## Project structure

```
ft_printf/
├── libft/                  
├── ft_printf.h            
├── ft_printf.c             # Parses the format string, handle conversions
├── ft_convert_c.c          ┐
├── ft_convert_s.c          │
├── ft_convert_p.c          │
├── ft_convert_d_i.c        ├─ # Each conversion in 1 file (except d & i)
├── ft_convert_u.c          │
├── ft_convert_x.c          │
├── ft_convert_X.c          ┘
├── ft_utoa_base.c          # Helper function for %puxX
├── Makefile                
├── README.md
└── .gitignore
```

## Instructions

### Compilation
```bash
make        # compiles *.c files and archives them into libftprintf.a
make clean  # removes *.o files
make fclean # removes *.o files and libftprintf.a
make re     # recompiles everything from scratch
```

### Usage
Link `libftprintf.a` against a `.c` file that has `main()`:

```bash
cc ft_printf.c -L . -l:libftprintf.a
```

## Notes on known behaviors and edge cases

1. **String literal checking**: ft_printf doesn't check for string literal format errors at compile time. It was done by the compiler does for the real `printf` (via `-Wformat`).
2. **Unknown specifiers**: ft_printf doesn't check for unknown specifiers; they are skipped.
3. **No matching argument**: ft_printf doesn't check for a missing matching argument (undefined behavior).
4. **Overflow / wraparound basics**
````
   -3 -2 -1  0  1   2   <- range from -3 to 2
    3  4  5  6  7   8   <- if every range value + 6
    9 10 11 12 13  14
    ...
````
   Vertically, if we keep subtracting the number with total values in the range, we can get the smallest representation. For example, `10` maps to `-2` via `10 - 6 - 6`.

## Resources
- https://man7.org/linux/man-pages/man3/printf.3.html
- https://www.geeksforgeeks.org/c/variadic-functions-in-c/
- https://cppreference.com/c/variadic

**Use of AI:**
- Review already-written implementations and point out issues or edge cases. Sparks discussion of trade-offs to have better understanding.
- Do README and summarized notes in the format of inline comments.