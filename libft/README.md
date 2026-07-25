_This project has been created as part of the 42 curriculum by matalmei._

# Libft

## Description

Libft is the first project at 42 School. It consists of reimplementing a selection of functions from the C standard library (libc), as well as additional utility functions and linked list manipulation functions, all bundled into a static library (`libft.a`).

The goal is to build a solid understanding of how these functions work at a fundamental level — memory management, string manipulation, character classification, and list operations — by writing them from scratch without relying on external libraries.

The library is organized in three parts:

- **Part 1 — Libc functions**: Reimplementations of standard functions such as `ft_strlen`, `ft_memcpy`, `ft_strchr`, `ft_atoi`, `ft_calloc`, `ft_strdup`, and others.
- **Part 2 — Additional functions**: Utility functions not present in the standard library or with different behavior, including `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, and output functions (`ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`).
- **Part 3 — Linked list functions**: Functions to manipulate singly linked lists, including `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, and `ft_lstmap`.

## Instructions

### Requirements

- GCC or Clang compiler
- GNU Make
- 42 Norm-compatible environment

### Compilation

Clone the repository and run `make` to compile the library:

```sh
make
```

This generates `libft.a` at the root of the repository. Additional Makefile rules:

- `make all` — same as `make`
- `make clean` — removes object files (`.o`)
- `make fclean` — removes object files and the library (`libft.a`)
- `make re` — runs `fclean` followed by `all`

### Usage

Include the header in your source files:

```c
#include "libft.h"
```

Link against the library when compiling:

```sh
cc -Wall -Wextra -Werror your_program.c -L. -lft
```

## Library structure

| File | Description |
|------|-------------|
| `libft.h` | Header with all function prototypes and the `t_list` struct |
| `Makefile` | Build rules for compiling the static library |
| `ft_*.c` | Implementation files, one function (plus its statics) per `.c` file |

### Functions list

#### Part 1 — Libc functions

`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_strlen`, `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_strlcpy`, `ft_strlcat`, `ft_toupper`, `ft_tolower`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_memchr`, `ft_memcmp`, `ft_strnstr`, `ft_atoi`, `ft_calloc`, `ft_strdup`.

#### Part 2 — Additional functions

`ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`.

#### Part 3 — Linked list functions (bonus)

`ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`.

## Resources

- [C Programming Language - 2nd Edition (K&R)](https://en.wikipedia.org/wiki/The_C_Programming_Language)
- [Man pages (Linux programmer's manual)](https://man7.org/linux/man-pages/index.html)
- 42 School Norminette documentation.
