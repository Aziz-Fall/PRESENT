# PRESENT
In cryptography, an SP-network, or substitution–permutation network (SPN), is a series of linked mathematical operations used in block cipher algorithms such as AES (Rijndael), 3-Way, Kalyna, Kuznyechik, *PRESENT*, SAFER, SHARK, and Square. 

In this project, *2PRESENT24* is used and we implement the middle attack against the 2PRESENT24 encryption.

To Perform the attack you need to pass as argument the two pairs of clear message and encrypted to the main executable *main*  in the file *Makefile* as follow
***./main m1 c1 m2 c2***
and run the commande ***make*** 
To delete all files objects you run the command ***make clean***
in your terminal.
Make sure that you have installed makefile in you computer.

You can also compile all the program
as follow ***gcc *.c -o main -O3*** and run it ***./main m1 c1 m2 c2***.


