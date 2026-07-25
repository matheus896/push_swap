_This project has been created as part of the 42 curriculum by matalmei._

# ft_printf — matalmei's implementation

## Description

ft_printf is a project in the 42 Common Core that challenges students to recode the C standard library's `printf` function. The goal is to handle a variable number of arguments using variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`) and produce formatted output that mimics the original `printf` behavior.

This implementation covers the following mandatory conversions:

- **`%c`** — prints a single character
- **`%s`** — prints a string (NULL prints `(null)`)
- **`%p`** — prints a `void *` pointer in hexadecimal format with `0x` prefix
- **`%d`** / **`%i`** — prints a signed decimal (base 10) integer
- **`%u`** — prints an unsigned decimal (base 10) integer
- **`%x`** / **`%X`** — prints a hexadecimal (base 16) number (lowercase/uppercase)
- **`%%`** — prints a literal percent sign

The return value is the total number of characters printed, or `-1` if a `write` error occurs.

## Algorithm and Data Structure

### Architecture

The project is structured in three source files for separation of concerns:

| File | Responsibility |
|---|---|
| `src/ft_printf.c` | Main loop and format dispatch |
| `src/utils.c` | Low-level write helpers and trivial handlers |
| `src/handlers.c` | Conversion-specific handlers |

### Format Parsing (ft_printf.c)

The main function (`ft_printf`) iterates through the format string character by character:

```
ft_printf(format, ...)
  ├── va_start(args, format)
  ├── while each character in format:
  │   ├── if '%' and next char exists:
  │   │     dispatch to handler via ft_eval_format(args, specifier)
  │   │     skip the specifier character
  │   └── else:
  │         write character directly via ft_print_char
  ├── va_end(args)
  └── return total characters printed (or -1 on write error)
```

The dispatch function (`ft_eval_format`) uses an `if-else` chain matching the specifier character (`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`) to the appropriate handler. No jump tables or function pointers are used — simplicity and Norm compliance are prioritized.

### Variadic Function Handling

All variable arguments are accessed through the `va_*` macros:

- `va_start(args, format)` — initializes the argument cursor to the first variadic argument
- `va_arg(args, type)` — reads the current argument and advances the cursor
- `va_end(args)` — cleanup (required by the standard for portability)

Each handler retrieves its argument with the correct type:
- `%c` → `va_arg(args, int)` (char is promoted to int in variadic calls)
- `%s` → `va_arg(args, char *)`
- `%p` → `va_arg(args, void *)`
- `%d` / `%i` → `va_arg(args, int)`
- `%u` → `va_arg(args, unsigned int)`
- `%x` / `%X` → `va_arg(args, unsigned int)`
- `%%` → no argument consumed

### Number Conversion (utils.c)

Numbers are converted using a zero-allocation, recursive approach:

```c
ft_print_nbr(unsigned long n, int base, int upper)
```

- Base 10 for `%d`, `%i`, `%u`
- Base 16 for `%x`, `%X`, `%p`

The recursion divides `n` by `base` until zero, printing digits in reverse order on the way back up. No `malloc` is used — digits are looked up from a string literal (`"0123456789abcdef"` or `"0123456789ABCDEF"`) and written one byte at a time via `write()`.

For signed integers (`%d`/`%i`), the handler tests for negativity, prints a leading `-`, and converts the absolute value to an unsigned long before calling `ft_print_nbr`. This avoids the signed overflow UB that would occur with `-INT_MIN` on a signed `int`.

### Return Value and Error Propagation

- Every `write()` call returns the number of bytes written
- Values are accumulated across all characters and handlers
- If any `write()` call returns `-1`, the function immediately propagates `-1` to the caller
- Each handler has a uniform signature (`int handler(va_list args)`) returning the count

## Instructions

### Compilation

```sh
make        # compiles libftprintf.a
make clean  # removes object files (obj/)
make fclean # removes object files and libftprintf.a
make re     # fclean + all
```

### Installation

Link `libftprintf.a` to your project:

```sh
cc -Wall -Wextra -Werror -o your_program your_program.c -L. -lftprintf
```

### Usage

Include the header:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Meaning of life: %d\n", "world", 42);
    return (0);
}
```

## Resources

### Documentation

- [ft_printf subject](https://intra.42.fr) — official project description
- [Norma 42](https://github.com/42School/norminette) — 42 coding standard
- [stdarg.h — cppreference.com](https://en.cppreference.com/w/c/variadic) — variadic function macros
- [man 3 printf](https://man7.org/linux/man-pages/man3/printf.3.html) — original printf reference
- [man 2 write](https://man7.org/linux/man-pages/man2/write.2.html) — write system call
- [C Programming Language Book] —  1. Session 7.3 Variable-length Argument Lists (pg 168) 2. Session B.7 Variable Argument Lists: <stdarg.h> (pg 282)

### AI Usage

AI (opencode with Claude) was used as a learning companion throughout this project:

- **Concept explanation**: understanding variadic functions, the `va_*` macros, why conversion is needed, and the design of the format string parser
- **Architecture discussion**: structuring the project into files and handlers for extensibility and Norm compliance
- **Code review**: verifying Norm compliance (function count, line limits, forbidden constructs) and edge-case correctness (INT_MIN, NULL pointers, write error propagation)
- **Test validation**: generating test cases and verifying output against the original printf
- **README writing**: organizing this document
