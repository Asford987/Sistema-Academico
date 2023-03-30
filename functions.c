#include "includes.h"


void set_rng(){
    time_t t;
    srand((unsigned) time(&t));
}

float rng_f(){
    return (float)(rand() % 100);
}

int rng_codigo_aluno(){
    FILE* f = fopen(".codaluno.txt", "r");
    int num = rand() % 100000;
    int aux;
    while(!feof(f)){
        fscanf(f,"%d",&aux);
        if(num == aux) return rng_codigo_aluno();    
    }
    FILE* f = fopen(".codaluno.txt","a");
    fprintf(f,"%d",num);
    return num;
}

int rng_codigo_disciplina(){
    FILE* f = fopen(".codis.txt", "r");
    int num = rand() % 100000;
    int aux;
    while(!feof(f)){
        fscanf(f,"%d",&aux);
        if(num == aux) return rng_codigo_disciplina();    
    }
    FILE* f = fopen(".codis.txt","a");
    fprintf(f,"%d",num);
    return num;
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

Semestre* completar_semestre(char* nome, Aux_al* al, Aux_di* di){
    FILE* f = fopen(strcat(strcat("semestre",nome),".txt"), "r");
    if(f==NULL) return create_sem();
    int codigo_aluno = 0, codigo_disciplina = 0;
    Semestre* sem = create_sem();
    while(!feof(f)){
        Aluno_Disciplina* ad = create_node();
        fscanf(f,"%d",&codigo_aluno);
        fscanf(f,"%d",&codigo_disciplina);

        Aluno* a = buscar_aluno(codigo_aluno,al);
        Disciplina* d = buscar_disciplina(codigo_disciplina,di);
        
        ad -> aluno = a;
        ad -> disciplina = d;
        
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
    Aluno_Disciplina* aux = sem->first;
    while(aux){
        fprintf(f,"%d",aux->aluno->codigo);
        fprintf(f,"%d",aux->disciplina->codigo);
        fprintf(f,"\n");
        aux = aux->prox;
    }
}