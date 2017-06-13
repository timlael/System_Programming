#!/bin/bash

#Default FizzBuzz to 20 if no argument passed

if [[ -z "$1" ]]; then									#check for no argument passed
	for i in {1..20}; 								#default case loops 1..20
	do
		if [[ "$(($i % 3))" == "0" ]] && [[ "$(($i % 5))" == "0" ]];then	#check for values meeting both conditions below first
			echo "FizzBuzz"
		elif [[ "$(($i % 3))" == "0" ]];then					#check for values mod 3 resulting in 0
			echo "Fizz"
		elif [[ "$(($i % 5))" == "0" ]];then					#check for values mod 5 resulting in 0
			echo "Buzz"
		else
			echo "$i"							#values that meet none of the above are printed as-is
		fi
	done
	
#Below uses argument passed at command line to control FizzBuzz loop

else
number=$1
	if [[ $number =~ ^[-+]?[0-9]+$ ]];then						#checks to make sure the argument is an integer using regex
		if [[ "$number" == "0" || "$number" == "-0" || "$number" == "+0" ]];then	#accounts for 0,+0 or -0 being passed as an argument 
			echo "FizzBuzz"
		elif [[ "$number" -lt "0" ]];then					#accounts for negative integers being passed as argument
		i=-1
			while [ "$number" -le "$i" ];					#while argument passed is less than counter
			do								#same as evaluation loop above
				if [[ $i != 0 ]] && [[ "$(($i % 3))" == "0" ]] && [[ "$(($i % 5))" == "0" ]];then 
					echo "FizzBuzz"
				elif [[ $i != 0 ]] && [[ "$(($i % 3))" == "0" ]];then
					echo "Fizz"
				elif [[ $i != 0 ]] && [[ "$(($i % 5))" == "0" ]];then
					echo "Buzz"
				else
					echo "$i"
				fi
			i=$(($i - 1))							#decrease counte for negative case
			done
		else									#accounts for positive integers being passed as argument
		i=1
			while [ "$number" -ge "$i" ];					#while argument passed is greater than counter
			do								#same evaluation loop as above
				if [[ $i != 0 ]] && [[ "$(($i % 3))" == "0" ]] && [[ "$(($i % 5))" == "0" ]];then
					echo "FizzBuzz"
				elif [[ $i != 0 ]] && [[ "$(($i % 3))" == "0" ]];then
					echo "Fizz"
				elif [[ $i != 0 ]] && [[ "$(($i % 5))" == "0" ]];then
					echo "Buzz"
				else
					echo "$i"
				fi
			i=$(($i + 1))							#increase counter for positive case
			done
		fi
	else
		echo "If used, argument must be an integer"				#warn non-integer input
	fi
fi
