# makefile for getquotient.asm
task: main.c input.c inrnd.c output.c getquotient.o
	gcc -g -o task main.c input.c inrnd.c output.c getquotient.o -no-pie
getquotient.o: getquotient.asm
	nasm -f elf64 -g -F dwarf getquotient.asm -l getquotient.lst
