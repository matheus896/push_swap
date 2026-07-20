# push_swap — Tracer Bullet

*This project has been created as part of the 42 curriculum by <matalmei>, <vitormelo>.*

## O que é isso?

Push_swap é um projeto da 42: ordenar números usando duas pilhas (stack A e B) com apenas 11 operações possíveis (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`, `ss`, `rr`, `rrr`). O programa recebe os números como argumento e imprime a sequência de operações necessária pra ordenar.

O estado atual atravessa o sistema inteiro: parsing de args com validação, detecção de flags de estratégia, e dispatch pro algoritmo. O que falta são os algoritmos de ordenação em si.

## Estado atual

### Pronto e funcionando

| Módulo | Arquivo | Responsabilidade |
|--------|---------|------------------|
| Stack | `stack.c` | `init` (alocar) e `push` (inserir no topo) |
| Operações | `ops_swap_push.c` | `sa`, `sb`, `ss`, `pa`, `pb` |
| Operações | `ops_rotate.c` | `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr` |
| Parsing | `parse.c` | `is_valid_int`, `ft_atol`, `has_duplicates`, `parse_args` |
| Estratégia | `strategy.c` | `detect_strategy` — lê `--simple`, `--medium`, `--complex`, `--adaptive`, `--bench` |
| Dispatch | `dispatch.c` | **STUB** — chama `sort_3`. Substituir pelo seletor real |
| Sort 3 | `sort_3.c` | Algoritmo fixo pra 3 números |
| Main | `main.c` | Detecta estratégia → parseia → dispatch → libera |
| Header | `push_swap.h` | Struct `t_stack`, enum `t_strategy`, protótipos |

### A implementar

| Arquivo | O que fazer |
|---------|-------------|
| `dispatch.c` | Substituir o stub por um seletor que chama o algoritmo certo baseado na `t_strategy` |
| `sort_simple.c` | O(n²) — min/max extraction, selection sort, etc. |
| `sort_medium.c` | O(n√n) — chunk-based, bucket adaptado |
| `sort_complex.c` | O(n log n) — radix sort, merge sort adaptado |
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

Definidas em `push_swap.h`:

```c
typedef enum e_strategy
{
    STRAT_SIMPLE,    // --simple:   O(n²)
    STRAT_MEDIUM,    // --medium:   O(n√n)
    STRAT_COMPLEX,   // --complex:  O(n log n)
    STRAT_ADAPTIVE   // --adaptive: default, seleciona por disorder
}   t_strategy;
```

`detect_strategy` varre argv. Se achar `--simple`, `--medium`, `--complex` ou `--adaptive`, retorna o enum correspondente. Se achar `--bench`, seta `bench_mode = 1`. Default: `STRAT_ADAPTIVE`.

### Parsing (`parse_args`)

1. Primeiro loop: conta quantos números existem (ignora flags `--*`)
2. `init(a, count)` — aloca o array com capacidade exata
3. `fill_stack` (static helper): segundo loop que valida cada argumento com `is_valid_int` + `ft_atol`, verifica range `INT_MIN`/`INT_MAX`, e dá `push`
4. `has_duplicates` — verifica duplicatas no array final

Em caso de erro, `parse_args` libera a memória e retorna `0`. O main escreve `"Error\n"` no stderr e sai com `exit(1)`.

### Nota sobre `dispatch.c`

O `dispatch.c` atual é um **stub temporário** criado só pra permitir compilação e testes do parser + flags:

```c
void    dispatch(t_stack *a, t_stack *b, t_strategy s, int bm)
{
    (void)s;
    (void)bm;
    sort_3(a, b);
}
```

## Como testar

```bash
# Compilar tudo
gcc -Wall -Wextra -Werror *.c -o push_swap_tb

# Testar parsing e flags
./push_swap_tb 2 1 3                    # ordena (stub chama sort_3)
./push_swap_tb --simple 3 1 2           # com flag de estratégia
./push_swap_tb --bench --complex 5 2 4  # benchmark + estratégia

# Testar erros
./push_swap_tb 42 abc                   # "Error" (não-numérico)
./push_swap_tb 9999999999               # "Error" (overflow)
./push_swap_tb 5 3 5                    # "Error" (duplicata)
./push_swap_tb                          # nada (sem args)

# Validar com checker
./push_swap_tb 3 2 1 | ./checker_linux 3 2 1
```

Os testes de unidade do parser estão em `test_parse.c`:

```bash
gcc -Wall -Wextra -Werror stack.c parse.c strategy.c test_parse.c -o test_parse
./test_parse
```
