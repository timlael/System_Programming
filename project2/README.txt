To compile, unzip project2.zip and navigate to ./project2/mychmod/ in a terminal window.
Issue the make command in project2/mychmod



mychmod is intended to be run from a terminal and passed at least three arguments.
usage is as follows:
./mychmod [-u rwx] [-g rwx] [-o rwx] [-U rwx] [-G rwx] [-O rwx] <filename> [<filename>...]

-u adds rights to user, -U removes
-g adds rights to group, -G removes
-o adds rights to other, -O removes

r is a read attribute
w is a write attribute
x is an execute attribute

At least one lower or upper case user, group or other switch MUST be specified.
At least one r, w or x attribute MUST be specified after each user, group or other switch.
Permutations and order do not matter for switches or attributes.

At least one filename MUST be specified.

Wildcards are acceptable in the filename. 
	(e.g.  ./mychmod -u r test*.* would apply user read rights to all files beginning with "test" with any extension)
	
Conflicting attribute changes are accepted and applied.
However, only the last attribute change in a series of conflicting changes is retained since they are sequentially applied.
	(e.g. ./mychmod -u r -U r -u r -U r test*.*	would add, then remove, then add, then remove user read rights 
	to all files beginning with "test" with any extension)
	
	
Files in project2/mychmod for testing purposes:

-rw-r--r--   1 tmlz5d   student      190 Mar  9 14:07 Makefile
-rw-r--r--   1 tmlz5d   student     3580 Mar 11 10:33 changes.c
-rw-r--r--   1 tmlz5d   student     1265 Mar 11 10:04 files.c
-rw-r--r--   1 tmlz5d   student     2132 Mar 10 11:17 input.c
-rw-r--r--   1 tmlz5d   student     1207 Mar 11 09:38 mychmod.c
-rw-rw----   1 tmlz5d   student        0 Mar  9 14:04 other.txt
-rw-r-----   1 tmlz5d   student        0 Mar 10 10:54 test.doc
-rw-rw----   1 tmlz5d   student        0 Mar 10 09:36 test.txt
-rw-r-----   1 tmlz5d   student        0 Mar 10 10:55 test.xml
-rw-r-----   1 tmlz5d   student        0 Mar 10 10:54 test1.doc
-rw-r-----   1 tmlz5d   student        0 Mar 10 10:54 test2.doc
-rw-rw----   1 tmlz5d   student        0 Mar 10 09:36 test2.txt
-rw-r-----   1 tmlz5d   student        0 Mar 10 10:54 test3.doc
-r--r-----   1 tmlz5d   student        0 Mar 10 09:36 test3.txt
-r--r-----   1 tmlz5d   student        0 Mar 10 09:37 test4.txt
-rw-------   1 tmlz5d   student        0 Mar 10 09:37 test5.txt
	
	
	
