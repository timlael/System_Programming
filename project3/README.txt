fizzbuzz
fizzbuzz.sh can be run in a bash shell or as an executable. It can be passed an integer (positive or negative) as an argument or run with no argument.
examples of usage:
./fizzbuzz.sh		
./fizzbuzz.sh 22
./fizzbuzz.sh -19
Special Features:
Added ability for sinage input [+-]
Added ability to evaluate negative numbers
Added ability to validate arguments  and warn if a non-integer is passed as an argument

flcln
flcln.sh can also be run in a bash shell or as an executable. Running with no argument will search the CWD and all subdirectories. Passing a path as an argument is also permitted and the search will start in the directory passed and traverse all subdirectories of the provided path.
Example of usage:
./flcln.sh
./flcln.sh ~
./flcln.sh /some/valid/path

bookinfo
bookinfo.sh is also meant to be run in a shell or as an executable.
Running with no argument will prompt the user for the input of one book's information.
If a single argument of an integer is passed, the user will be promted to enter that number of books information.
If the argument passed is print, the entire list will be printed to the book_info file.
The print argument also has optional flags that can be used as follows:
-f search_string will print only books with that search string somewhere in the information
-f -i search_string will do the same, but is case insensitive
the search string can use regular expressions.
Examples of usage:
./bookinfo.sh
./bookinfo.sh 10
./bookinfo.sh -f Mark 
./bookinfo.sh -f -i mark (returns same result as above)
