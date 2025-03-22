#!/bin/bash
read -p "Enter the file name (without extension):" file
fullname="${file}.c"
chmod +x $fullname
gcc $fullname -o $file
./$file
