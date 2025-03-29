#!/bin/bash
func()
{
  read -p "Enter the path: " path
  echo "Path entered: $path"
  current_dir=$(pwd)
  target_dir="$current_dir/$path"
  echo $target_dir
#if [ -d "$target_dir" ]; then
 #   cd "$target_dir" || exit
  #  echo "Changed directory to: $(pwd)"
#else
 #   echo "Error: Directory does not exist!"
#fi

  files=$(ls -lr $target_dir | awk '{print $9}')
  for file in $files;do
    filename="${file%.*}"
    extension="${file##*.}"
    upper_name=$(echo "$filename" | tr '[:lower:]' '[:upper:]')
    if [[ "$extension" == "txt" ]]
    then extension="tex"
    fi
    if [[ upper_name != filename ]]
    then
       mv "$target_dir/$file" "$target_dir/$upper_name.$extension"
   else
	echo "file is already in upper case"
   fi
done
