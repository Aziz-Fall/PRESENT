run: main 
	./main 

main: encryption.o main.o decryption.o const.o
	gcc	*.o -o main -fcommon

main.o: main.c encryption.h decryption.h
	gcc -c main.c -fcommon

encryption.o: encryption.h encryption.c const.h
	gcc -c encryption.c -fcommon

decryption.o: decryption.h decryption.c const.h
	gcc -c decryption.c -fcommon

const.o: const.c const.h 
	gcc -c const.c -fcommon

clean:
	rm -fr *.o main 
	clear