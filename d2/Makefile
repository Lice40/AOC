
FLAGS := -o
NAME := gravityAssist
CC := gcc
DEBUG := -fsanitize=address -g

BLK =    \e[30m
RED    =    \e[31m
GRN =    \e[32m
YLW =    \e[33m
BLU    =    \e[34m
PPL    =    \e[35m
CYA    =    \e[36m
END    =    \e[0m

$(NAME): main.o utils.o 
	@$(CC) main.o utils.o $(DEBUG) $(FLAGS) $(NAME)
	@printf "\t$(GRN)compiling$(END)\n"

all: $(NAME)

main.o: main.c
	@$(CC) -c main.c $(DEBUG)

utils.o: utils.c
	@$(CC) -c utils.c $(DEBUG)

clean:
	@rm -f $(NAME)
	@rm -f *.o

re: clean $(NAME)