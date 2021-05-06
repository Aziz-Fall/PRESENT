run: main 
	./main 8a5c19 7cc9ee cfdbd2 cc89f3
# run: main
# 	./main 7e6359 411b34 f55c52 1c6195
 
main: encryption.o main.o decryption.o const.o main_key.o attack.o
	gcc	*.o -o main -O3 

main.o: main.c encryption.h decryption.h
	gcc -c -O3 main.c -Wall

encryption.o: encryption.h encryption.c const.h main_key.h
	gcc -c -O3 encryption.c -Wall

decryption.o: decryption.h decryption.c const.h
	gcc -c -O3 decryption.c -Wall

const.o: const.c const.h 
	gcc -c -O3 const.c -Wall

main_key.o: main_key.c main_key.h 
	gcc -c -O3 main_key.c -Wall

attack.o: attack.c attack.h 
	gcc -c -O3 attack.c -Wall

clean:
	rm -fr *.o main 
	clear