#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    FILE* f = fopen("teste.txt","r");
    char line[99];
    while(fscanf(f, "%99[^\n]\n", line) == 1){
        printf("%s\n",line);
    }
}