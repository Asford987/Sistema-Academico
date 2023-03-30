#include "includes.h"


void set_rng(){
    time_t t;
    srand((unsigned) time(&t));
}

float rng_f(){
    return (float)(rand() % 100);
}

int rng_a(){
    int aux = rand() % 100000;
    if(1){ // TODO: verificar se ja existe
        return aux;
    }else{
        return rng_a();
    }
    
}

int rng_d(){
    int aux = rand() % 10000;
    if(1){ // TODO: verificar se ja existe
        return aux;
    }else{
        return rng_d();
    }
}

int array_comparator(int* a, int* b){
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
        if(a[i]!=b[i]) return 0;
    }
    return 1;
}

Aux_al* completar_aluno(){
    FILE* f = fopen("alunos.txt", "r");
    
    if(f==NULL) return create_al();
    
    char line[100];
    while(!feof(f)){
        Aluno* al = new_aluno();
        if(fscanf(f, "%99[^\n]\n", line) != 1){
            return NULL;
        }
        al -> codigo = atoi(line);
        if(fscanf(f, "%99[^\n]\n", line) != 1){
            return NULL;
        }
        strcpy(al->nome,line);
        if(fscanf(f, "%99[^\n]\n", line) != 1){
            return NULL;
        }
        strcpy(al->cpf,line);
        fscanf(f, "%99[^\n]\n", line);
    }
}

Aux_di* completar_disciplina(){
    FILE* f = fopen("disciplinas.txt", "r");
    if(f==NULL) return create_di();
    
    char line[100];
    
    while(!feof(f)){
        Disciplina* dis = new_disciplina();
        if(fscanf(f, "%99[^\n]\n", line) != 1){
            return NULL;
        }
        dis -> codigo = atoi(line);
        if(fscanf(f, "%99[^\n]\n", line) != 1){
            return NULL;
        }
        strcpy(dis->prof,line);
        if(fscanf(f, "%99[^\n]\n", line) != 1){
            return NULL;
        }
        strcpy(dis->nome,line);
        if(fscanf(f, "%99[^\n]\n", line) != 1){
            return NULL;
        }
        dis->creditos = (float)atof(line);
        fscanf(f, "%99[^\n]\n", line);
    }
}

Semestre* completar_semestre(char* nome){
    FILE* f = fopen(strcat(strcat("semestre",nome),".txt"), "r");
    if(f==NULL) return create_sem();
    while(!feof(f)){

    }
}

void save_al(Aux_al* al){
    FILE* f = fopen("alunos.txt", "w");
    if(f==NULL) return;
    Aluno* aux = al->first;
    while(aux){
        fprintf(f,"%d\n",aux->codigo);
        
        fprintf(f,"%s\n",aux->nome);
        
        fprintf(f,"%s\n",aux->cpf);
        
        fprintf(f,"\n");

        aux = aux->prox;
    }
}

void save_di(Aux_di* di){
    FILE* f = fopen("disciplinas.txt", "w");
    if(f==NULL) return;

    Disciplina* aux = di->first;
    while(aux){
        fprintf(f,"%d\n",aux->codigo);
        
        fprintf(f,"%s\n",aux->prof);
        
        fprintf(f,"%s\n",aux->nome);

        fprintf(f,"%f",aux->creditos);
        
        fprintf(f,"\n");

        aux = aux->prox;
    }
}

void save_semester(Semestre* sem){
    FILE* f = fopen(strcat(strcat("semestre",sem->nome),".txt"), "w");
    if(f==NULL) return;

}