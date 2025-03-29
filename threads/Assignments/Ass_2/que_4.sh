#!/bin/bash

process_directory() {
    local target_dir="$1"
    echo "Working directory: $target_dir"

    for item in "$target_dir"/*; do
        if [[ -d "$item" ]]; then
            echo "$item is a directory"
            process_directory "$item"

        elif [[ -f "$item" ]]; then
            echo "Processing file: $item"

            # Extract filename and extension
            file_name="${item%.*}"
            extension="${item##*.}"
            upper_name=$(basename "$file_name" | tr '[:lower:]' '[:upper:]')

            # Change extension "txt" to "tex"
            if [[ "$extension" == "txt" ]]; then
                extension="tex"
            fi

            # Rename the file if needed
            if [[ "$upper_name" != "$(basename "$file_name")" ]]; then
                new_name="$(dirname "$item")/$upper_name.$extension"
                mv "$item" "$new_name"
                echo "Renamed $item to $new_name"
            else
                echo "File '$item' is already in upper case."
            fi
        fi
    done
}

# Main script starts here
read -p "Enter the path: " path
echo "Path entered: $path"

current_dir=$(pwd)
target_dir="$current_dir/$path"
echo "Target directory: $target_dir"

# Check if the directory exists
if [ -d "$target_dir" ]; then
    echo "Directory exists. Starting recursive processing..."
    process_directory "$target_dir"
else
    echo "Error: Directory does not exist!"
    exit 1
fi
