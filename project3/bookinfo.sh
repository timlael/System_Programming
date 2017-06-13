#!/bin/bash
if [[ "$1" == "" ]];then				#check for passed argument. If null prompt for input of 1 book
	echo "Title: "
	read  title
	echo -n $title >> books
	echo "Author: "
	read  author
	echo -n ","$author >> books
	echo "Publisher: "
	read  publisher
	echo -n ","$publisher >> books
	echo "Publication year: "
	read  year
	echo ","$year >> books
else
	if [[ $1 =~ ^[+]?[0-9]+$ ]];then		#If passed argument is not null, validate as an integer with signage using regex
		i=1
		while   [[ "$i" -le "$1" ]] ;do		#iterate through entry for number pased
			echo "Title: "
			read  title
			echo -n $title >> books
			echo "Author: "
			read  author
			echo -n ","$author >> books
			echo "Publisher: "
			read  publisher
			echo -n ","$publisher >> books
			echo "Publication year: "
			read  year
			echo ","$year >> books
			i=$(($i + 1))			#increment loop counter
		done
	elif [[ "$1" == "-f" ]] && [[ "$4" == "print" ]] && [[ "$2" == "-i" ]];then	#look for argument of -f -i SEARCHTERM case insensitive search
		grep -i "$3" books | awk -F, 'BEGIN{printf "%-40s %-40s %-40s %-20s\n\n"," Title:"," Author:"," Publisher:"," Year:"} {printf "%-40s %-40s %-40s %-20s\n",$1,$2,$3,$4}' >> book_print		#grep file for SEARCHTERM and pipe results to awk for formatting and append/create file
	elif [[ "$1" == "-f" ]] && [[ "$3" == "print" ]];then	#look for argument of -f SEARCHTERM
		grep "$2" books | awk -F, 'BEGIN{printf "%-40s %-40s %-40s %-20s\n\n"," Title:"," Author:"," Publisher:"," Year:"} {printf "%-40s %-40s %-40s %-20s\n",$1,$2,$3,$4}' >> book_print		#grep file for SEARCHTERM and pipe results to awk for formatting and append/create file
	elif [[ "$1" == "print" ]]; then		#look for print argument
		 awk -F, 'BEGIN{printf "%-40s %-40s %-40s %-20s\n\n"," Title:"," Author:"," Publisher:"," Year:"} {printf "%-40s %-40s %-40s %-20s\n",$1,$2,$3,$4}' books >> book_print				#print all books in file in formatted file
	else
		echo "Invalid argument"
	fi
fi

