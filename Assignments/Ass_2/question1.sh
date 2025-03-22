#!/bin/bash
ps aux --sort=-%mem | head -11
echo "******************************************"
#second method
ps -eo %mem,%cpu,pid --sort=-%mem | head -n 11
# -e is used for tp show all processes
#-o is used for formating we can also use --formate instead of -o
