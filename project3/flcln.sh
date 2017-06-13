#!/bin/bash

if [[ "$1" == "" ]]; then								#if argument passed is null
	find . -type f -exec basename \{} \; | xargs du 2>/dev/null | sort -n		#use find in CWD to look for files and pipe results to du for 
											#size information suppress errors by directing to null device
											#pipe du results to sort for size sort
	find . -type f -size 0 -exec rm -i {} \;					#perform find again and execute interactive rm on 0 size files
else
path=$1
	find "$path" -xdev -type f -exec basename \{} \; | xargs du 2>/dev/null | sort -n	#same as above except path is passed as an argument
	find "$path" -xdev -type f -size 0 -exec rm -i {} \;					#also, xdev prevent traversing of othe mounted devices
fi
