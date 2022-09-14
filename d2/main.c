#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int parseString(char * filename, int ** array);
int  copyFile(int* datas[], int* src, int nbE);
int process(int intcode[]);

int main(int argc, char** argv) {
    int* intcode;
    int * temp;
    int nbInt;
    int i,j;
    int test;
    int found =0;
    int valueExpected = 19690720;
    int valueFound;

    nbInt = parseString("./input.txt", &intcode);
    if(nbInt == -1){
        exit(EXIT_FAILURE);
    }
    temp = malloc(nbInt*sizeof(int));

    while(i < 99 && !found){
        j=0;
        while(j<99 && !found){
            printf("trying combination %d, %d...", i,j);
            test = copyFile(&temp, intcode, nbInt);
            if(test == -1){
                exit (EXIT_FAILURE);
            }
            temp[1] = i;
            temp[2] = j;
            valueFound = process(temp);
            if(valueFound == valueExpected){
                found =1;
                printf("value found! code: %d\n", 100*i+j);
            }
            j++;
            printf(" value %d NOK\n", valueFound);
        }
        i++;
    }
   
    
    free (temp);
    free(intcode);
    return 0;
}