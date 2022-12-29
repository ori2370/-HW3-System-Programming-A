# Makefile

all: isort txtfind

isort: isort.c
	gcc -o isort isort.c

txtfind: txtfind.c
	gcc -o txtfind txtfind.c

clean:
	rm -f *.o isort txtfind

runtf:
	./txtfind

runs:
	./isort
