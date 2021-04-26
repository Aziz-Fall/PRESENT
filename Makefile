run: main 
	./main 

main: encryption.o main.o 
	gcc	*.o -o main 

main.o: main.c encryption.h 
	gcc -c main.c

encryption.o: encryption.h const.h encryption.c
	gcc -c encryption.c

clean:
	rm -fr *.o main 
	clear