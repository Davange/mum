#!/bin/bash

# Read user input for array of numbers
read -p "Enter the numbers (space-separated): " -a numbers

# Function to perform bubble sort
bubble_sort() {
    local arr=("$@")
    local n=${#arr[@]}

    for ((i = 0; i < n-1; i++))
    do
        for ((j = 0; j < n-i-1; j++))
        do
            if ((arr[j] > arr[j+1]))
            then
                # Swap the elements
                local temp=${arr[j]}
                arr[j]=${arr[j+1]}
                arr[j+1]=$temp
            fi
        done
    done

    # Print the sorted array
    echo "Sorted Array:"
    for ((i = 0; i < n; i++))
    do
        echo "${arr[i]}"
    done
}

# Call the bubble sort function with the array
bubble_sort "${numbers[@]}"
