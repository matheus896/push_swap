# push_swap — Tracer Bullet

*This project has been created as part of the 42 curriculum by <matalmei>, <vitormelo>.*

## O que é isso?

Push_swap é um projeto da 42: ordenar números usando duas pilhas (stack A e B) com apenas 11 operações possíveis (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`, `ss`, `rr`, `rrr`). O programa recebe os números como argumento e imprime a sequência de operações necessária pra ordenar.

Este **tracer bullet** é uma implementação mínima que funciona, mas só pra **3 números**. É a base do projeto: uma vez que você vê 3 números sendo ordenados de verdade, o pipeline inteiro faz sentido. O resto é expandir.

## Arquivos

| Arquivo | O que contém |
|---------|-------------|
| `push_swap.h` | Header: struct `t_stack`, protótipos de todas as funções |
| `stack.c` | `init` (alocar array) e `push` (inserir no topo) |
| `ops_swap_push.c` | `sa`, `sb` (swap topo), `pa`, `pb` (push entre stacks) |
| `ops_rotate.c` | `ra` (topo vai pra base) |
| `sort_3.c` | `sort_3` — lógica de ordenação pra 3 números |
| `main.c` | Lê args, chama sort_3, imprime operações, libera memória |

A struct que representa uma pilha:

```c
typedef struct s_stack
{
    int *arr;      // array dinâmico com os números
    int size;      // quantos elementos estão na pilha agora
    int cap;       // capacidade máxima (sem realocar)
}   t_stack;
```

O topo da pilha é sempre `arr[size - 1]`. `size = 0` significa pilha vazia.

## Compilar e testar

```bash
# Compilar
gcc -Wall -Wextra -Werror *.c -o push_swap_tb

# Testar: imprimir operações pra ordenar 3 2 1
./push_swap_tb 3 2 1

# Validar com o checker (ele executa suas operações)
./push_swap_tb 3 2 1 | ./checker_linux 3 2 1
# Deve imprimir "OK"

# Testar outras ordens
./push_swap_tb 2 3 1 | ./checker_linux 2 3 1
./push_swap_tb 1 3 2 | ./checker_linux 1 3 2
./push_swap_tb 3 1 2 | ./checker_linux 3 1 2
```

## Como funciona

**Pipeline do main:**
1. Cria duas stacks com capacidade pra 3 números cada
2. Lê os argumentos de trás pra frente (porque o primeiro argumento é o topo da stack, o checker espera assim)
3. Chama `sort_3`, que imprime as operações
4. Libera a memória

**sort_3 — o algoritmo:**
1. Empurra os 2 primeiros elementos de A pra B (`pb`, `pb`)
2. Se os 2 em B estiverem fora de ordem, troca (`sb`)
3. Traz os 2 de volta pra A (`pa`, `pa`)
4. Rotaciona A duas vezes (`ra`, `ra`) pra colocar o elemento que ficou em A na posição certa

É um algoritmo fixo (não genérico) — funciona especificamente pra 3 números porque o caso tem só 6 permutações possíveis e essa sequência resolve todas.

**Detalhe importante:** `sa` imprime "sa\n" e mexe na stack A. `sb` imprime "sb\n" e mexe na stack B. O checker não sabe qual função C você chamou, ele lê o texto da operação. Por isso `sa` e `sb` são funções separadas, mesmo tendo o mesmo código interno.

## AI Usage

Este código foi desenvolvido com auxílio de IA (Claude) como tutor. A IA:
- Ajudou a depurar o bug `sa` vs `sb` (o checker rejeitava porque imprimíamos "sa\n" quando deveria ser "sb\n")
- Ajudou a corrigir a ordem de leitura dos argumentos (topo = primeiro argumento)
- Explicou conceitos e guiou o cadet
