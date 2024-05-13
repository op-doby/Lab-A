part-0 : main.o numbers.o add.o 
	gcc -m32 -g -Wall -o part-0 main.o numbers.o add.o 
main.o : main.c 
	gcc -m32 -g -Wall -c main.c
numbers.o : numbers.c 
	gcc -m32 -g -Wall -c numbers.c
add.o: add.s
	nasm -g -f elf32 -w+all add.s -o add.o
.PHONY: clean all
clean :
	rm -f part-0 *.o
all: part-0

