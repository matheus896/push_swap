# push_swap

_This project has been created as part of the 42 curriculum by matalmei, vfreitas._

## Description

**push_swap** sorts a list of integers using two stacks (`a` and `b`) and a restricted set of 11 operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`). The program outputs the shortest sequence of operations needed to sort stack `a` in ascending order.

The project enforces four distinct strategies selectable at runtime via flags, each in a different complexity class:

| Flag | Strategy | Complexity | Algorithm |
|------|---------|-------------|-----------|
| `--simple` | STRAT_SIMPLE | O(n²) | Selection sort |
| `--medium` | STRAT_MEDIUM | O(n√n) | Chunk-based sort |
| `--complex` | STRAT_COMPLEX | O(n log n) | Binary radix sort (LSD) |
| `--adaptive` | STRAT_ADAPTIVE | Per disorder | Not yet implemented |
| `--bench` | (mode) | — | Writes performance report to stderr |

`--adaptive` is the default strategy when no flag is provided (falls back to `sort_3` until fully implemented).

---

## Learner Contributions

### Matheus Almeida (`matalmei`)

- **Project architecture**: `push_swap.h` header design, `t_stack` array-based model with `size`/`cap`, `t_chunk` struct, `t_strategy` enum, operation code defines (`OP_SA`..`OP_RRR`)
- **Core pipeline**: `main.c` (parse → dispatch → benchmark → free), `dispatch.c` (strategy router)
- **Stack & operations**: `stack.c` (`init`, `push`), `ops_swap_push.c` (`sa`, `sb`, `ss`, `pa`, `pb`), `ops_rotate.c` (shared `rot` helper + `ra`/`rb`/`rr`), `ops_rev_rotate.c` (shared `revrot` helper + `rra`/`rrb`/`rrr`)
- **Parsing & validation**: `parse.c` (`is_valid_int`, `ft_atol`, `has_duplicates`, `parse_args`) — overflow-safe integer parsing with proper `Error` handling
- **Sort 3**: `sort_3.c` — hardcoded optimal sort for exactly 3 elements
- **Benchmark system**: `bench_count.c` (operation counters + `print_bench` stderr output), `bench.c` (`compute_disorder` — pair-based disorder metric 0–100%)
- **Build system**: `Makefile` with `libft/` and `ft_printf/` as compiled dependencies, `-I.` include path, `-Wall -Wextra -Werror`
- **Norma compliance**: File splitting to respect 5-function/25-line limits, elimination of `typedef`/`struct` in `.c` files, shared operation helpers
- **Libft & ft_printf integration**: Both libraries embedded as source copies, compiled via their own Makefiles as `.a` archives

### Vitor Melo (`vitormelo`)

- **Chunk sort**: `chunk_sort.c` — O(n√n) algorithm with `chunk_pass` (phase 1: group-by-chunk) and `restore_stack` (phase 2: max-extraction from B to A)
- **Strategy detection**: `strategy.c` (`detect_strategy`) — parses `--simple`, `--medium`, `--complex`, `--adaptive`, `--bench` from command-line arguments
- **Simple algorithm**: `sort_simple.c` — selection sort O(n²) via `find_min` + `rotate_n`
- **Chunk helpers**: `chunk_helpers.c` (`ft_sqrt`, `init_chunk`, `next_chunk`, `chunk_count`, `cosort`)
- **Binary radix sort**: `binary_radix_sort.c` — O(n log n) LSD radix sort operating on binary representation of element rank, with `radix_pass` per bit
- **Operation output**: `print_op` function in `main.c` — unified operation printing via `write`
- **Norma fixes**: Whitespace corrections in `push_swap.h`, `binary_radix_sort.c`, `main.c`

---

## Algorithm Explanations

### Selection Sort — O(n²)

```
while A is not empty:
    find minimum value in A (linear scan)
    rotate A until minimum is at top
    push A → B
push all back B → A
```

N iterations over a shrinking stack of size n, n−1, ..., 1 produce the O(n²) bound. The `find_min` helper scans stack A sequentially; `rotate_n` brings the found element to the top using the shorter path (`ra` or `rra`). This is the baseline: simple, correct, and serves as the "pass" reference for random inputs up to 100 elements (<2000 ops).

### Chunk Sort — O(n√n)

Chunk sort is a bucket sort adaptation on two stacks. Instead of sorting elements directly, it groups them into √n chunks of width √n.

**Phase 1 — Partitioning**: An auxiliary sorted array is created via `cosort` (selection sort on a copy, preserving the original stack). Indices [0, n−1] are divided into k chunks of width `n / √n`. For each chunk, we scan the top of A: if the top element's rank falls within the current chunk range, push to B; otherwise rotate A. This repeats until A is empty.

**Phase 2 — Restoration**: B is returned to A in order by repeatedly finding the maximum element in B (`find_max_pos`), rotating B until that element is at the top (`move_max_to_top`), and pushing to A.

**Why √n**: k = √n chunks of √n elements each balances the cost of phase 1 (n operations × k passes = n√n) with phase 2 (finding max in B of size up to n, done n times = n² if naive; but the max-finding is amortized because B shrinks as we push back). The chunk width formula `n / ft_sqrt(n)` ensures the partitioning granularity matches the theoretical optimum.

### Binary Radix Sort — O(n log n)

LSD (Least Significant Digit) radix sort using the **binary representation of each element's rank** as the sorting key.

1. Compute the sorted order via `cosort`
2. For each bit position from 0 to log₂(n):
   - Scan A from top to bottom
   - If the bit at this position in the element's rank is 0 → push to B
   - If it is 1 → rotate A (keep in A)
   - After the pass, push all elements from B back to A (pa loop)

After bit position `i`, elements whose rank has bit `i` = 0 are on top of those with bit `i` = 1. After all log₂(n) bits, the stack is fully sorted.

**Why binary instead of decimal**: With only two stacks, binary (base 2) maps naturally to two destinations per pass — bit=0→B, bit=1→A. Decimal (base 10) would require 10 partitions per digit, impossible with two stacks without additional complexity.

**Why deterministic cost**: Each pass processes exactly n elements regardless of input order. With log₂(n) passes, the total is exactly n × log₂(n). For n=100: 7 passes × 100 elements + 100 pushes back = 700+400 ≈ 1084 ops. For n=500: 9 passes × 500 + 500 pushes back = 4500+2284 ≈ 6784 ops.

---

## Architecture

### Data structures

```c
typedef struct s_stack
{
    int *arr;    // dynamic array (contiguous memory)
    int size;    // current element count
    int cap;     // allocated capacity
}   t_stack;

typedef struct s_chunk
{
    int min;     // start index in sorted array
    int max;     // end index in sorted array
    int width;   // elements per chunk
}   t_chunk;
```

**Why array over linked list**: (1) Index-based access O(1) — every operation is a contiguous shift, not pointer traversal. (2) Cache-friendly — elements are adjacent in memory. (3) Single allocation per stack — less malloc/free overhead vs per-node allocation.

### Pipeline

```
argv → detect_strategy() → strategy + bench_mode
     → parse_args()       → t_stack a (or "Error\n" + exit)
     → dispatch()         → selected algorithm
     → print_bench()      → stderr (if --bench)
     → free()
```

### Benchmark (`--bench`)

All 11 operation functions call `bench_count(OP_XX)` after `write`. Counters live as `static int g_ct[11]` + `static char *g_nm[11]` in `bench_count.c` (file-scoped, not global). Disorder is computed via pair comparison before any sorting operation. Output to stderr:

```
Disorder: 52.88%
Strategy: complex (O(n log n))
Operations: 1084
pa: 384
pb: 384
ra: 316
```

---

## Instructions

```bash
make

# Strategies
./push_swap --simple 3 2 1                    # O(n²) selection sort
./push_swap --medium 3 2 1                     # O(n√n) chunk sort
./push_swap --complex 3 2 1                    # O(n log n) radix sort

# Benchmark (stderr)
./push_swap --bench --complex 10 5 8 2 1

# Random test with checker
ARG=$(shuf -i 0-999 -n 100 | tr '\n' ' ')
./push_swap --complex $ARG | ./checker_linux $ARG
echo "Ops: $(./push_swap --complex $ARG | wc -l)"

# Error cases
./push_swap 42 abc            # Error (non-numeric)
./push_swap 5 3 5             # Error (duplicate)
```

## Performance

| Strategy | n | Avg ops | Checker | Grade |
|----------|---|---------|---------|-------|
| `--simple` | 100 | ~1,600 | OK | Pass (<2000) |
| `--simple` | 500 | ~31,000 | OK | O(n²) expected |
| `--medium` | 100 | ~800 | OK | Good (<1500) |
| `--medium` | 500 | ~8,000 | OK | Good (<8000) |
| `--complex` | 100 | 1,084 | OK | Good (<1500) |
| `--complex` | 500 | 6,784 | OK | Good (<8000) |

---

## Resources

### References
- **Knuth, D. E.** — _The Art of Computer Programming, Vol. 3: Sorting and Searching_ — foundational text on algorithm analysis and complexity
- **Cormen, T. H. et al.** — _Introduction to Algorithms_ — radix sort, bucket sort, complexity analysis
- **42 Norm** — project coding standard (max 5 functions/file, 25 lines/function, no `for`/`switch`/ternary)

### AI Usage
- **Algorithm reasoning**: AI helped explain first-principles justification for chunk width (√n), radix base choice (binary vs decimal), and operation counting model
- **Benchmark design**: AI suggested static array counter pattern over string-matching, and stderr output format matching the subject specification
- **No AI-generated algorithms**: All sorting logic (selection, chunk, radix) was designed and implemented by the learners
