#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int parseString(char * filename, int ** array);

int main(int argc, char** argv) {
    int* intcode;
    int nbInt;
    int j;

    nbInt = parseString("./input.txt", &intcode);
    if(nbInt == -1){
        exit(EXIT_FAILURE);
    }
    
    // for(int i =0; i < nbInt; i++){
    //     printf("%d\n", intcode[i]);
    // }


    j=0;
    while(intcode[j] != 99){
        switch(intcode[j]){
            case 1:
                printf("adding %d and %d result %d, stored at %d \n", intcode[intcode[j+1]], intcode[intcode[j+2]], intcode[intcode[j+1]]+intcode[intcode[j+2]], intcode[intcode[j+3]]);
                intcode[intcode[j+3]] = intcode[intcode[j+1]] + intcode[intcode[j+2]];
                break;
            case 2:
                printf("multiply %d and %d result %d, stored at %d \n", intcode[intcode[j+1]], intcode[intcode[j+2]], intcode[intcode[j+1]]*intcode[intcode[j+2]], intcode[intcode[j+3]]);
                intcode[intcode[j+3]] = intcode[intcode[j+1]] * intcode[intcode[j+2]];
                break;
            default:
                printf("SA MARCH PA \n");
                break;
        }
        j+=4;
    }
    printf("%d\n", intcode[0]);
    
    
    free(intcode);
    return 0;
}