

read -p "Enter a number: " number

# Store the original number for comparison later
original_number=$number

reverse=0

while [ $number -gt 0 ]
do
    remainder=$(( $number % 10 ))
    reverse=$(( $reverse * 10 + $remainder ))
    number=$(( $number / 10 ))
done

echo "Reverse of the number: $reverse"

if [ $original_number -eq $reverse ]
then
    echo "The number is a palindrome"
else
    echo "The number is not a palindrome"
fi
