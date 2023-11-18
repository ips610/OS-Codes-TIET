#!/bin/bash

read first_str
read second_str

if [ $first_str == $second_str ]
then
    echo "Strings are equal"
else
    echo "Strings are not equal"
fi