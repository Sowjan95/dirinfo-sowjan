all: dirinfo.o
	gcc -o program dirinfo.o

main.o: dirinfo.c
	gcc -c dirinfo.c

run:
	./program	