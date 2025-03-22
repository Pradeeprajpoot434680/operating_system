#!/bin/bash
my_find_with_filename() {
  echo "Files are *************** "
  grep -r -l "$1" .
}

my_find()
{
  ls -aR
}
echo """
	1. my_find command
	2.search file
	"""
read -p "Enter one choice:" choice
if [ "$choice" -eq 1 ]
then
    my_find
elif [ $choice -eq 2 ]
then
  read -p "Enter the string or pattern to search for: " search_pattern
  #-z secarch that string is empty or not
  if [[ -z "$search_pattern" ]]; then
    echo "You must enter a search pattern."
    exit 1
  fi

  echo "Searching for files or directories matching the pattern '$search_pattern'"
  #function call with argument
  my_find_with_filename "$search_pattern"

else
  echo "Invalid choice. Please enter 1 or 2."
  exit 1
fi
