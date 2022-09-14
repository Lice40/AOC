
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parseString(char * filename, int * array[]){
    FILE* file = fopen(filename,  "r");
    char * line = NULL;
    size_t read;
    size_t len =0;
    int i = 0;
    int nbE = 1;
    char*  ptr;
    char*  str;

    if(file == NULL){
        return (-1);
    }
    while(read = getline(&line, &len, file) != -1){
       while (line[i] != '\0'){
            if(line[i] == ','){
                nbE++;
            }
            i++;
       }
    }   
    *array = malloc (nbE * sizeof(int));
    if (*array == NULL){
        return -1;
    }

    ptr = strtok(line, ",");
    i = 0;
    while(ptr != NULL){
        str =  malloc(strlen(ptr)+1*sizeof(char));
        strcpy(str, ptr);
        //le (*array) doit etre entre parenthèse car sinon celà cause un soucis d'ambiguité pour le compilo
        (*array)[i] = atoi(str);
        ptr = strtok(NULL, ",");
        i++;
        free(str);
    }


    fclose (file);
    return nbE;
}

int  copyFile(int* datas[], int* src, int nbE){
    for (int i=0; i<nbE; i++){
        (*datas)[i] = src[i];
    }

    return 0;
}

int process(int intcode[]){
    int j;
    j=0;
    while(intcode[j] != 99){
        switch(intcode[j]){
            case 1:
                //printf("adding %d and %d result %d, stored at %d \n", intcode[intcode[j+1]], intcode[intcode[j+2]], intcode[intcode[j+1]]+intcode[intcode[j+2]], intcode[intcode[j+3]]);
                intcode[intcode[j+3]] = intcode[intcode[j+1]] + intcode[intcode[j+2]];
                break;
            case 2:
                //printf("multiply %d and %d result %d, stored at %d \n", intcode[intcode[j+1]], intcode[intcode[j+2]], intcode[intcode[j+1]]*intcode[intcode[j+2]], intcode[intcode[j+3]]);
                intcode[intcode[j+3]] = intcode[intcode[j+1]] * intcode[intcode[j+2]];
                break;
            default:
                printf("SA MARCH PA \n");
                return -1;
                break;
        }
        j+=4;
    }
    return (intcode[0]);
}