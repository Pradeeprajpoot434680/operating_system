#!/bin/bash

read -p "Enter the filename:(without extension c file):" file
fullname="$file.c"
chmod +x $fullname
gcc $fullname -o $file
./$file
