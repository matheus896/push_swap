# push_swap

*42 school project by <matalmei>, <vitormelo>.*

Sort numbers using two stacks (A and B) with 11 permitted operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`). The program receives numbers as arguments and prints the sequence of operations needed to sort them.

## State

### Ready

| File | Responsibility |
|------|---------------|
| `src/stack.c` | `init` (allocate), `push` (insert at top) |
| `src/ops_swap_push.c` | `sa`, `sb`, `ss`, `pa`, `pb` |
| `src/ops_rotate.c` | `rot` (static helper), `ra`, `rb`, `rr` |
| `src/ops_rev_rotate.c` | `revrot` (static helper), `rra`, `rrb`, `rrr` |
| `src/parse.c` | `is_valid_int`, `ft_atol`, `has_duplicates`, `parse_args` |
| `src/strategy.c` | `detect_strategy` — parses `--simple`, `--medium`, `--complex`, `--adaptive`, `--bench` |
| `src/dispatch.c` | Routes `STRAT_SIMPLE` → `selection_sort`, `STRAT_MEDIUM` → `chunk_sort`, others → `sort_3` (fallback) |
| `src/sort_3.c` | Hard-coded algorithm for exactly 3 elements |
| `src/sort_simple.c` | Selection sort O(n²): `find_min` (static) + `rotate_n` (static) |
| `src/chunk_sort.c` | Chunk sort O(n√n): `chunk_pass` (static), `is_chunk` (static), `find_max_pos` (static), `move_max_to_top` (static), `chunk_sort` |
| `src/chunk_helpers.c` | `ft_sqrt`, `init_chunk`, `next_chunk`, `chunk_count`, `cosort` |
| `src/bench_count.c` | Operation counter: `bench_count` + benchmark output (`print_bench`) — writes to stderr |
| `src/bench.c` | `compute_disorder` — ratio of out-of-order pairs × 100 (two decimal places) |
| `src/main.c` | Detect strategy → parse → dispatch → free |
| `push_swap.h` | Structs `t_stack`, `t_chunk`, enum `t_strategy`, op defines (`OP_SA`..`OP_RRR`), all prototypes, includes libft/ft_printf |
| `Makefile` | Compiles `src/` into root, compiles `libft/` and `ft_printf/` as dependencies, `-Wall -Wextra -Werror` |

### To implement

| Strategy | Complexity | File (planned) |
|----------|-----------|----------------|
| `--complex` | O(n log n) | `src/sort_complex.c` — radix sort on two stacks |
| `--adaptive` | Per disorder | `src/sort_adaptive.c` — picks algorithm based on `compute_disorder` thresholds |

## Architecture

### Main pipeline

```
argv → detect_strategy() → strategy + bench_mode
     → parse_args()       → t_stack a filled (or "Error" + exit)
     → dispatch()         → algorithm per strategy
     → print_bench()      → stderr (disorder, strategy, operation counts)
     → free()
```

### Data structures

```c
typedef struct s_stack
{
    int *arr;
    int size;
    int cap;
}   t_stack;

typedef struct s_chunk
{
    int min;
    int max;
    int width;
}   t_chunk;

typedef enum e_strategy
{
    STRAT_SIMPLE,    // --simple:   O(n²)
    STRAT_MEDIUM,    // --medium:   O(n√n) chunk sort
    STRAT_COMPLEX,   // --complex:  not yet implemented
    STRAT_ADAPTIVE   // --adaptive: not yet implemented
}   t_strategy;
```

### Chunk sort (`--medium`)

Phase 1: group elements by chunks (width = size / √size), push matching elements from A to B, rotate A to expose new top. Phase 2: restore B to A in descending order by repeatedly finding max and moving it to top, then pushing.

### Benchmark (`--bench`)

All operations call `bench_count(OP_XX)` after `write(1, ...)`. On exit, `print_bench` writes to stderr:

```
Disorder: 63.70%
Strategy: medium (O(n sqrt n))
Operations: 820
pa: 100
pb: 100
ra: 408
rb: 107
rrb: 105
```

Counters live as `static int g_ct[11]` + `static char *g_nm[11]` in `bench_count.c`.

### Libraries

- **libft**: copied into `libft/` — used for `ft_strncmp`, `ft_strlen`, `ft_putstr_fd`, `ft_putnbr_fd`, `ft_calloc`
- **ft_printf**: copied into `ft_printf/` — used only in `test_parse.c` (main program uses `write` + libft fd helpers for output, keeping dependencies minimal)

### Norma compliance

All `src/*.c` files pass norminette. Key constraints observed:
- Max 5 functions per `.c` file
- Max 25 lines per function
- No `typedef` or `struct` declarations in `.c` files
- No `for`, `switch`, or ternary
- Operations with duplicated logic (`rr`/`rrr`) share a static helper (`rot`/`revrot`) to stay under 25 lines

## Usage

```bash
make

# Selection sort (O(n²))
./push_swap --simple 3 2 1 | ./checker_linux 3 2 1

# Chunk sort (O(n√n))
./push_swap --medium 3 2 1 | ./checker_linux 3 2 1

# With benchmark (stderr)
./push_swap --bench --medium 10 5 8 2 1 9 3 7 4 6

# Random test
ARG=$(shuf -i 0-999 -n 100 | tr '\n' ' ')
./push_swap --medium $ARG | ./checker_linux $ARG
echo "Ops: $(./push_swap --medium $ARG | wc -l)"

# Error cases
./push_swap 42 abc       # "Error" (non-numeric)
./push_swap 5 3 5        # "Error" (duplicate)
```

## Benchmarks (checker_linux)

| Strategy | n | Avg ops | Checker |
|----------|---|---------|---------|
| `--simple` | 100 | ~1,600 | OK |
| `--simple` | 500 | ~31,000 | OK |
| `--medium` | 100 | ~800 | OK |
| `--medium` | 500 | ~8,300 | OK |
