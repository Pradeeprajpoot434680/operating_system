#!/bin/bash

# Function to display the process information
show_processes() {
    clear
    echo "Top-like Command Simulation"
    echo "============================"
    echo ""

    # Get the number of processes running
    total_processes=$(ps aux --no-heading | wc -l)
    echo "Total Processes Running: $total_processes"
    echo ""

    # Display header for process information
    printf "%-10s %-10s %-10s %-10s %-10s %-10s %-20s\n" "PID" "USER" "%CPU" "%MEM" "PRIORITY" "FD" "COMMAND"

    # Get a list of processes
    ps aux --no-heading --sort=-%mem | awk '{printf "%-10s %-10s %-10s %-10s %-10s %-10s %-20s\n", $2, $1, $3, $4, $18, $9, $11}' | head -n 10
}

# Function to display details about a specific process
show_process_details() {
    echo ""
    read -p "Enter the PID of the process you want to inspect: " pid
    echo ""

    if [ -d "/proc/$pid" ]; then
        echo "Process Information for PID: $pid"
        echo "================================="
        echo "1. Memory Info"
        echo "2. CPU Info"
        echo "3. File Descriptors"
        echo "4. Environment Variables"
        echo "5. Command Line"
        echo "6. Back to Main Menu"
        echo ""
        read -p "Choose an option (1-6): " option

        case $option in
            1)
                echo "Memory Info:"
                cat /proc/$pid/status | grep -i "Vm"
                ;;
            2)
                echo "CPU Info:"
                cat /proc/$pid/stat | awk '{print "CPU time: " $14 + $15}'
                ;;
            3)
                echo "File Descriptors:"
                ls /proc/$pid/fd
                ;;
            4)
                echo "Environment Variables:"
                cat /proc/$pid/environ | tr '\0' '\n'
                ;;
            5)
                echo "Command Line:"
                cat /proc/$pid/cmdline
                ;;
            6)
                return
                ;;
            *)
                echo "Invalid option!"
                ;;
        esac
    else
        echo "Process with PID $pid not found."
    fi
}

# Main menu function
main_menu() {
    while true; do
        show_processes
        echo ""
        echo "Options:"
        echo "1. View Process Details"
        echo "2. Exit"
        echo ""
        read -p "Choose an option (1-2): " option

        case $option in
            1)
                show_process_details
                ;;
            2)
                exit 0
                ;;
            *)
                echo "Invalid option!"
                ;;
        esac
    done
}

# Start the program
main_menu
