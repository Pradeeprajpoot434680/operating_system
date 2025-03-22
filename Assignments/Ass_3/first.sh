#!/bin/bash

add()
{
  echo -n "Sum of num1 and num2 is: "
  echo "$1 + $2" | bc
}

subtract()
{
  echo -n "Subtraction of num1 and num2 is: "
  echo "$1 - $2" | bc
}

multiply()
{
  echo -n "Multiplication of num1 and num2 is: "
  echo "$1 * $2" | bc
}

divide()
{
  if [ "$2" -eq 0 ]; then
    echo "Division by 0 is not allowed"
  else
    echo -n "Division of num1 and num2 is: "
    echo "scale=5; $1 / $2" | bc
  fi
}

# Main script loop
while true; do
    echo """
1. Trigonometric operations
2. Arithmetic operations
3. Logarithms
4. Exponent
5. Exit (-1)"""

    read -p "Select an option (-1 to exit): " option

    if [ "$option" -eq -1 ]; then
        echo "Exiting the program. Goodbye!"
        break
    fi

    if [ "$option" -eq 1 ]; then
        echo """
        1. Sine operation
        2. Cos operation
        3. Tan operation"""
        
        read -p "Choose one: " a
        read -p "Enter the angle in radians: " angle
        
        if [ "$a" -eq 1 ]; then
            echo "s($angle)" | bc -l
        elif [ "$a" -eq 2 ]; then
            echo "c($angle)" | bc -l
        elif [ "$a" -eq 3 ]; then
            echo "a($angle)" | bc -l
        else
            echo "Wrong option selected"
        fi

    elif [ "$option" -eq 2 ]; then
        echo """
        1. Addition
        2. Subtraction
        3. Multiplication
        4. Division"""
        
        read -p "Select one: " y
        read -p "Enter the first number: " num1
        read -p "Enter the second number: " num2
        
        if [ "$y" -eq 1 ]; then
            add "$num1" "$num2"
        elif [ "$y" -eq 2 ]; then
            subtract "$num1" "$num2"
        elif [ "$y" -eq 3 ]; then
            multiply "$num1" "$num2"
        elif [ "$y" -eq 4 ]; then
            divide "$num1" "$num2"
        else
            echo "Wrong option selected"
        fi

    elif [ "$option" -eq 3 ]; then
        read -p "Enter the base of the log (positive integer): " base
        read -p "Enter the argument of the log: " arg
        
        if [ "$base" -lt 1 ]; then
            echo "Base must be a positive integer"
        elif [ "$base" -eq 10 ]; then
            echo "l($arg)" | bc -l
        else
            if [[ "$base" =~ ^[0-9]+$ ]]; then
                # Convert log base
                echo "scale=5; l($arg)/l($base)" | bc -l
            else
                echo "Base is not an integer"
            fi
        fi

    elif [ "$option" -eq 4 ]; then
        read -p "Enter the base: " base
        read -p "Enter the exponent: " power
        echo "$base ^ $power" | bc -l

    else
        echo "Invalid option selected"
    fi

    echo "------------------------------------"
done

