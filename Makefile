run: main 
	./main 

main: encryption.o main.o decryption.o const.o main_key.o
	gcc	*.o -o main 

main.o: main.c encryption.h decryption.h
	gcc -c main.c 

encryption.o: encryption.h encryption.c const.h main_key.h
	gcc -c encryption.c 

decryption.o: decryption.h decryption.c const.h
	gcc -c decryption.c 

const.o: const.c const.h 
	gcc -c const.c 

main_key.o: main_key.c main_key.h 
	gcc -c main_key.c 

clean:
	rm -fr *.o main 
	clear