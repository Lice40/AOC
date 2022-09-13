main: main.o utils.o 
	gcc main.o utils.o -fsanitize=address -g -o out

main.o: main.c
	gcc -c main.c -fsanitize=address -g

utils.o: utils.c
	gcc -c utils.c -fsanitize=address -g

clean:
	rm -f out
	rm -f *.o

re: clean main