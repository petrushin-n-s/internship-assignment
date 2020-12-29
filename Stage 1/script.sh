#!/bin/bash

createdir() {
	echo -n "enter directory name: "
	read dir

	if [ -z "$dir" ]
	then
		exit
	elif [ -e "$dir" ]
	then
		rmdir "$dir"
		echo remove existing directory "$dir"
	else
		mkdir "$dir"
		echo create directory "$dir"
	fi
}

createfile() {
	if [ -w "$1" ]
		then
			rm "$1"
			echo remove writable file "$1"
		elif [ -e "$1" ]
		then
			rm "$1"
			echo remove existing file "$1"
		else
			touch "$1"
			chmod u=rw "$1"
			echo create file "$1"
	fi
}

if [ -n "$1" ]; then
	if [ "-h" = "$1" ]; then
		echo create file -f filename
		echo create directory -d
		exit 1
	elif [ "-d" = "$1" -a -z "$2" ]; then
		createdir
	elif [ "-f" = "$1" -a -n "$2" ]; then
		createfile "$2"
	else
		echo use -h for help
	fi
else
	echo use -h for help
fi
