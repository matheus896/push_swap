#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Uso: $0 <simple|medium|complex> <100|500>"
    exit 1
fi

MODE=$1
SIZE=$2

case "$MODE" in
    simple|medium|complex)
        ;;
    *)
        echo "Estratégia inválida."
        echo "Use: simple, medium ou complex."
        exit 1
        ;;
esac

if [ "$SIZE" -ne 100 ] && [ "$SIZE" -ne 500 ]; then
    echo "Quantidade inválida."
    echo "Use 100 ou 500."
    exit 1
fi

echo "========================================"
echo " Push Swap Benchmark"
echo "========================================"
echo "Strategy : $MODE"
echo "Elements : $SIZE"
echo "Runs     : 10"
echo "========================================"

for i in {1..10}
do
    echo
    echo "--------------- Run $i/10 ---------------"

    ARG=$(shuf -i 1-"$SIZE" -n "$SIZE" | tr '\n' ' ')

    ./push_swap $ARG --"$MODE" --bench
done

echo
echo "========================================"
echo " Benchmark finished"
echo "========================================"