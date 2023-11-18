#!/bin/bash
#Fibonacci Series

read n
a=0
b=1
echo $a
echo $b

for (( i=0; i<n-2; i++ )); do
    c=$(( $a + $b ))
    echo $c
    a=$b
    b=$c
done