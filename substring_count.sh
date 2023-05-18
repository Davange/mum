#!/bin/bash

# Check if the number of command line arguments is correct
if [ $# -ne 2 ]; then
    echo "Usage: $0 <string> <substring>"
    exit 1
fi

string=$1
substring=$2

count=$(grep -o "$substring" <<< "$string" | wc -l)

echo "Number of occurrences of '$substring' in '$string': $count"
