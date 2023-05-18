#!/bin/bash

# Recursive method to calculate factorial
function factorial_recursive {
    if [ $1 -eq 0 ]; then
        echo 1
    else
        local prev_factorial=$(( $1 - 1 ))
        local prev_result=$(factorial_recursive $prev_factorial)
        echo $(( $1 * $prev_result ))
    fi
}

# Non-recursive method to calculate factorial
function factorial_non_recursive {
    local result=1
    for ((i=1; i<=$1; i++))
    do
        result=$(( $result * $i ))
    done
    echo $result
}

read -p "Enter a number: " number

recursive_result=$(factorial_recursive $number)
echo "Factorial using recursive method: $recursive_result"

non_recursive_result=$(factorial_non_recursive $number)
echo "Factorial using non-recursive method: $non_recursive_result"
