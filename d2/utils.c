
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
        printf("%s\n", str);
        *array[i] = atoi(str);
        ptr = strtok(NULL, ",");
        i++;
        free(str);
    }


    fclose (file);
    return nbE;
}

