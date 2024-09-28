#!/bin/bash

array=(a b c d)

# Get the lengthe of array
LEN=${#array[*]}
echo "Length of the array is: $LEN"

# Print the array elements"
echo "${array[@]}"
echo "----------------------------------"

# Iterate through the array
for ((i=0;i<${#array[*]};i++)); do
    echo "$i : ${array[$i]}"
done
echo "---------------------------------"

# Add new value to the end of the array
array=("${array[@]}" "e")
array[10]="f"   # Add another element at index 10
echo "${array[@]}"
echo "---------------------------------"

# Copy the array to another array
declare -a newarray
for i in ${array[@]}; do
    newarray[${#newarray[*]}]=$i
done
echo "New array values: ${newarray[@]}"
echo "----------------------------------"

# Remove a element from the array
unset array[2]
echo "${array[@]}"
echo "---------------------------------"

# Replace a array element
array[0]="z"
echo "${array[@]}"
echo "---------------------------------"

# Delete entire array
unset array
echo "${array[@]}"

exit 0

