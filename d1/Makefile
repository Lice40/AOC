main: main.o
	gcc main.o -o out

main.o: main.c
	gcc -c main.c

clean:
	rm -f out
	rm -f *.o

re: clean main