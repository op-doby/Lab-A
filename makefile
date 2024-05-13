edit : main.o numbers.o add.s 
	cc -o out main.o numbers.o add.s 
main.o : main.c stdlib.h stdio.h string.h
	cc -c main.c
numbers.o : numbers.c stdlib.h stdio.h
	cc -c numbers.c
clean :
	rm out main.o numbers.o