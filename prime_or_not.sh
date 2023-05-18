#!/bin/bash

read -p "Enter a number: " number

reverse=$(echo $number | rev)

echo "Reverse of the number: $reverse"

is_prime=1

if [ $number -lt 2 ]; then
    is_prime=0
fi

for ((i=2; i<=$number/2; i++))
do
    if [ $((number % i)) -eq 0 ]; then
        is_prime=0
        break
    fi
done

if [ $is_prime -eq 1 ]; then
    echo "The number is prime"
else
    echo "The number is not prime"
fi
