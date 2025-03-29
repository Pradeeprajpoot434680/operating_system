#!/bin/bash
show_processes(){
    clear
    echo "Top command simulation"
	# it will count all the running processes
    all_processes=$(ps aux --no-heading | wc -l)
    echo "Total running processes $all_processes"
   printf "%-10s %-10s %-10s %-10s %-10s %-10s\n" "PID" "USER" "%CPU" "%MEM" "PRIORITY" "COMMAND"
   ps aux --no-heading | awk '{printf "%-10s %-10s %-10s %-10s %-10s %-10s\n", $2,$1,$3,$4,$18,$11}'
   }
show_processes


show_process_detail(){
   while true; do
    read -p "Enter the PID of the process:(-1 for exit) " pid
      if [ "$pid" -eq -1 ]; then
        echo "Exiting..."
        break
    fi
    if ps -p "$pid" > /dev/null; then
        ps -p "$pid" -o pid,ppid,uid,uname,cmd,%mem,%cpu,start,time,stat
    else
        echo "No process found with PID $pid."
    fi
   done
}

show_process_detail
