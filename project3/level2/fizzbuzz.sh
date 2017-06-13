#!/bin/bash

#Default FizzBuzz to 20 if no argument passed

if [[ -z "$1" ]]; then
	for i in {1..20}; 
	do
		if [[ "$(($i % 3))" == "0" ]] && [[ "$(($i % 5))" == "0" ]];then
			echo "FizzBuzz"
		elif [[ "$(($i % 3))" == "0" ]];then
			echo "Fizz"
		elif [[ "$(($i % 5))" == "0" ]];then
			echo "Buzz"
		else
			echo "$i"
		fi
	done
else

#Below uses argument passed at command line to control FizzBuzz loop

number=$1
	if [[ "$number" == "0" ]];then			#accounts for a 0 being passed as an argument 
		echo "$number"
	elif [[ "$number" -lt "0" ]];then		#accounts for negative numbers being passed as argument
	i=-1
		while [ "$number" -le "$i" ];
		do
			if [[ $i != 0 ]] && [[ "$(($i % 3))" == "0" ]] && [[ "$(($i % 5))" == "0" ]];then
				echo "FizzBuzz"
			elif [[ $i != 0 ]] && [[ "$(($i % 3))" == "0" ]];then
				echo "Fizz"
			elif [[ $i != 0 ]] && [[ "$(($i % 5))" == "0" ]];then
				echo "Buzz"
			else
				echo "$i"
			fi
		i=$(($i - 1))
		done
	else									#accounts for positive numbers being passed as argument
	i=1
		while [ "$number" -ge "$i" ];
		do
			if [[ $i != 0 ]] && [[ "$(($i % 3))" == "0" ]] && [[ "$(($i % 5))" == "0" ]];then
				echo "FizzBuzz"
			elif [[ $i != 0 ]] && [[ "$(($i % 3))" == "0" ]];then
				echo "Fizz"
			elif [[ $i != 0 ]] && [[ "$(($i % 5))" == "0" ]];then
				echo "Buzz"
			else
				echo "$i"
			fi
		i=$(($i + 1))
		done
	fi
fi
