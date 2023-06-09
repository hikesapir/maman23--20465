fibon: fibon.o helpers.o
	gcc -Wall -ansi -pedantic fibon.o helpers.o -o fibon
fibon.o: fibon.c helpers.h
	gcc -c -Wall -ansi -pedantic fibon.c -o fibon.o
helpers.o: helpers.c helpers.h
	gcc -c -Wall -ansi -pedantic helpers.c -o helpers.o
 


