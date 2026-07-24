#!/bin/bash

sum=0
min=999999
max=0

echo "===== Selection Sort (500 números) ====="

for i in {1..10}
do
    ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' ')
    ops=$(./push_swap $ARG | awk '/Numero op:/ {print $3}')

    echo "Teste $i: $ops"

    ((sum += ops))

    if ((ops < min)); then
        min=$ops
    fi

    if ((ops > max)); then
        max=$ops
    fi
done

echo
echo "Resumo"
echo "--------------------------"
echo "Média     : $((sum / 10))"
echo "Menor     : $min"
echo "Maior     : $max"
echo "Amplitude : $((max - min))"

echo
echo "Meta da 42 (500 números)"
echo "--------------------------"
media=$((sum / 10))

if ((media < 5500)); then
    echo "🏆 Excelente (< 5500)"
elif ((media < 8000)); then
    echo "✅ Boa (< 8000)"
elif ((media < 12000)); then
    echo "✔ Passa (< 12000)"
else
    echo "❌ Acima do limite (> 12000)"
fi