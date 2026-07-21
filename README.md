# push_swap — Tracer Bullet

*This project has been created as part of the 42 curriculum by <matalmei>, <vitormelo>.*

## O que é isso?

Push_swap é um projeto da 42: ordenar números usando duas pilhas (stack A e B) com apenas 11 operações possíveis (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`, `ss`, `rr`, `rrr`). O programa recebe os números como argumento e imprime a sequência de operações necessária pra ordenar.

O estado atual atravessa o sistema inteiro: parsing de args com validação, detecção de flags de estratégia, dispatch pro algoritmo, e um algoritmo O(n²) (selection sort) implementado.

## Estado atual

### Pronto e funcionando

| Módulo | Arquivo | Responsabilidade |
|--------|---------|------------------|
| Stack | `stack.c` | `init` (alocar) e `push` (inserir no topo) |
| Operações push/swap | `ops_swap_push.c` | `sa`, `sb`, `ss`, `pa`, `pb` |
| Operações rotate | `ops_rotate.c` | `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr` |
| Operações rev_rotate | `ops_rev_rotate.c` | `rra`, `rrb`, `rrr` (duplicata de ops_rotate.c) |
| Parsing | `parse.c` | `is_valid_int`, `ft_atol`, `has_duplicates`, `parse_args` |
| Estratégia | `strategy.c` | `detect_strategy` — lê `--simple`, `--medium`, `--complex`, `--adaptive`, `--bench` |
| Dispatch | `dispatch.c` | Roteia `STRAT_SIMPLE` → `selection_sort`, demais → `sort_3` |
| Sort 3 | `sort_3.c` | Algoritmo fixo pra 3 números (só cobre `3 2 1`) |
| Sort Simple | `sort_simple.c` | Selection sort O(n²) com `find_min` + `rotate_n` |
| Main | `main.c` | Detecta estratégia → parseia → dispatch → libera |
| Header | `push_swap.h` | Struct `t_stack`, enum `t_strategy`, protótipos |
| Makefile | `Makefile` | Compila com `-Wall -Wextra -Werror`, regras `all`/`clean`/`fclean`/`re` |

### A implementar

| Arquivo | O que fazer |
|---------|-------------|
| `sort_medium.c` | O(n√n) — chunk-based, bucket adaptado |
| `sort_complex.c` | O(n log n) — radix sort, merge sort adaptado |
| `sort_adaptive.c` | Algoritmo adaptativo baseado em disorder |
| `bench.c` | Contagem de operações e relatório `--bench` no stderr |

## Arquitetura

### Pipeline do main

```
argv → detect_strategy() → t_strategy + bench_mode
     → parse_args()       → t_stack a preenchida (ou "Error" + exit)
     → dispatch()         → algoritmo baseado na t_strategy
     → free()
```

### Estratégias (`t_strategy`)

```c
typedef enum e_strategy
{
    STRAT_SIMPLE,    // --simple:   O(n²) — usa selection_sort
    STRAT_MEDIUM,    // --medium:   O(n√n) — ainda não implementado
    STRAT_COMPLEX,   // --complex:  O(n log n) — ainda não implementado
    STRAT_ADAPTIVE   // --adaptive: default, seleciona por disorder
}   t_strategy;
```

### Parsing

1. Primeiro loop: conta números (ignora flags `--*`)
2. `init(a, count)` — aloca o array
3. `fill_stack` (static): itera `argv` de trás pra frente (primeiro arg = topo da stack), validando com `is_valid_int` + `ft_atol` e checando range `INT_MIN`/`INT_MAX`
4. `has_duplicates` — verifica duplicatas

Em caso de erro, `parse_args` libera a memória e retorna `0`. O main escreve `"Error\n"` no stderr e `exit(1)`.

### Dispatch

```c
void dispatch(t_stack *a, t_stack *b, t_strategy s, int bm)
{
    (void)bm;
    if (s == STRAT_SIMPLE)
        selection_sort(a, b);
    else
        sort_3(a, b);
}
```

STRAT_MEDIUM, STRAT_COMPLEX e STRAT_ADAPTIVE ainda caem em `sort_3` (comportamento parcial).

### Selection sort (`sort_simple.c`)

- `find_min` (static): percorre a stack e retorna índice do menor valor
- `rotate` (static): aplica `ra` ou `rra` N vezes via ponteiro de função
- `selection_sort`: extrai o mínimo → empurra pra B → repete → devolve tudo pra A

Benchmarks com checker_linux:
| n | Ops | Resultado |
|---|-----|-----------|
| 100 | ~1600 | OK (< 2000 ✓) |
| 500 | ~31000 | OK (> 12000, esperado O(n²)) |

## Como compilar e testar

```bash
# Compilar
make

# Testar --simple (selection sort)
./push_swap --simple 3 2 1 | ./checker_linux 3 2 1

# Testar n=100
ARG=$(shuf -i 0-999 -n 100 | tr '\n' ' ')
./push_swap --simple $ARG | ./checker_linux $ARG
echo "Ops: $(./push_swap --simple $ARG | wc -l)"

# Testar erros
./push_swap --simple 42 abc                 # "Error" (não-numérico)
./push_swap --simple 5 3 5                  # "Error" (duplicata)
```
