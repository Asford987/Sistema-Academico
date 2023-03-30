#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Aluno{
    struct Aluno* prox;
    int val;
} Aluno;




int main(){
    Aluno* al = (Aluno*)calloc(1,sizeof(Aluno));
}