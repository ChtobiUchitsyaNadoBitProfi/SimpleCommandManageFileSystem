.PHONY: clean

all: SMFS

SMFS: bin/main.o bin/SMFS.o
	gcc -Wall bin/main.o bin/SMFS.o -o SMFS

bin/SMFS.o: src/SMFS.c
	gcc -c src/SMFS.c -o bin/SMFS.o

bin/main.o: src/main.c
	gcc -c src/main.c -o bin/main.o

clean: 
	rm -rf bin/*.o
	rm -rf SMFS