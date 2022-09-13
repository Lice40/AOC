#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int parseString(char * filename, int ** array);

int main(int argc, char** argv) {
    int* intcode;
    int nbInt;
  

    nbInt = parseString("./input.txt", &intcode);
    if(nbInt == -1){
        exit(EXIT_FAILURE);
    }

    for(int i =0; i < nbInt; i++){
        //printf("%d\n", intcode[i]);
    }

    free(intcode);

    printf("%d\n", nbInt);
    return 0;
}