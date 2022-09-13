#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char** argv) {
    FILE* file = fopen("./inputs.txt",  "r");
    char * line = NULL;
    int fuel_mass = 0;
    int temp = 0;
    int sum =0;
    size_t read;
    size_t len =0;
    if(file == NULL){
        return (EXIT_FAILURE);
    }

    while(read = getline(&line, &len, file) != -1){
        sum = 0;
        //calcul de la masse de fuel necessaire
        temp = atoi(line);
        temp = temp/3;
        temp -=2;
        fuel_mass += temp;
        //calcul de la masse de fuel nécessaire par rapport à la valeur précédente
        while(temp >0){
            temp = temp/3-2;
            if(temp <= 0 ){
                break;
            }
            sum += temp;
        }
        fuel_mass +=sum;
    }
    fclose(file);
    printf("%d\n", fuel_mass);
    return 0;
}