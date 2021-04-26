run: main 
	./main 

main: encryption.o main.o decryption.o
	gcc	*.o -o main 

main.o: main.c encryption.h decryption.h
	gcc -c main.c

encryption.o: encryption.h encryption.c const.h
	gcc -c encryption.c

decryption.o: decryption.h decryption.c const.h
	gcc -c decryption.c

clean:
	rm -fr *.o main 
	clear