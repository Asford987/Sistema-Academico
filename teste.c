#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Aluno{
    struct Aluno* prox;
    int val;
} Aluno;




int main(){
    Aluno* al = NULL;
    if(!al) printf("1");
    else printf("0");
    return 0;
}