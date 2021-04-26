run: main 
	./main 

main: encryption.o main.o decryption.o const.o uint80_t.o
	gcc	*.o -o main -fcommon

main.o: main.c encryption.h decryption.h
	gcc -c main.c -fcommon

encryption.o: encryption.h encryption.c const.h uint80_t.h
	gcc -c encryption.c -fcommon

decryption.o: decryption.h decryption.c const.h
	gcc -c decryption.c -fcommon

const.o: const.c const.h 
	gcc -c const.c -fcommon

uint80_t.o: uint80_t.c uint80_t.h 
	gcc -c uint80_t.c -fcommon

clean:
	rm -fr *.o main 
	clear