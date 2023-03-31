#include "includes.h"


// void set_rng(){
//     time_t t;
//     srand((unsigned) time(&t));
// }

// float rng_f(){
//     return (float)(rand() % 100);
// }

// int rng_codigo_aluno(){
//     FILE* f = fopen(".codaluno.txt", "r");
//     int num = rand() % 100000;
//     int aux;
//     while(!feof(f)){
//         fscanf(f,"%d",&aux);
//         if(num == aux) return rng_codigo_aluno();    
//     }
//     fclose(f);
//     FILE* g = fopen(".codaluno.txt","a");
//     fprintf(g,"%d",num);
//     fclose(g);
//     return num;
// }

// int rng_codigo_disciplina(){
//     FILE* f = fopen(".codis.txt", "r");
//     int num = rand() % 100000;
//     int aux;
//     while(!feof(f)){
//         fscanf(f,"%d",&aux);
//         if(num == aux) return rng_codigo_disciplina();    
//     }
//     fclose(f);
//     FILE* g = fopen(".codis.txt","a");
//     fprintf(g,"%d",num);
//     fclose(g);
//     return num;
// }

Aux_al* completar_aluno(){
    FILE* f = fopen("alunos.txt", "r");
    if(f==NULL) return create_al();
    char line[100];
    int codigo;
    char nome[DIM];
    char cpf[DIM];
    Aux_al* al=create_al();
    while(!feof(f)){
        if(fscanf(f, "%99[^\n]\n", line) != 1){
            return NULL;
        }
        codigo = atoi(line);
        if(fscanf(f, "%99[^\n]\n", line) != 1){
            return NULL;
        }
        strcpy(nome,line);
        if(fscanf(f, "%99[^\n]\n", line) != 1){
            return NULL;
        }
        strcpy(cpf,line);

        input_aluno(al,nome, codigo, cpf);
    }
    fclose(f);
    return al;
}

Aux_di* completar_disciplina(){
    FILE* f = fopen("disciplinas.txt", "r");
    if(f==NULL) return create_di();
    Aux_di *di=create_di();
    char line[100];
    int codigo;
    char prof[DIM2];
    char nome[DIM2];
    int creditos;
    
    while(!feof(f)){
        if(fscanf(f, "%99[^\n]\n", line) != 1){
            return NULL;
        }
        codigo = atoi(line);
        printf("%d",codigo);
        if(fscanf(f, "%99[^\n]\n", line) != 1){
            return NULL;
        }
        strcpy(prof,line);
        printf("%s",prof);
        if(fscanf(f, "%99[^\n]\n", line) != 1){
            return NULL;
        }
        strcpy(nome,line);
        printf("%s",nome);
        if(fscanf(f, "%99[^\n]\n", line) != 1){
            return NULL;
        }
        creditos = atof(line);
        printf("%d",creditos);

        input_disciplina(di, nome, prof, codigo, creditos);
    }
    fclose(f);
    return di;
}

Semestre* completar_semestre(char* nome, Aux_al* al, Aux_di* di){
    char concat[100]="semestre";
    strcat(concat,nome);
    strcat(concat,".txt");
    FILE* f = fopen(concat, "r");
    if(f==NULL) return create_sem(nome);
    int codigo_aluno = 0, codigo_disciplina = 0;
    Semestre* sem = create_sem(nome);
    while(!feof(f)){
        fscanf(f,"%d",&codigo_aluno);
        fscanf(f,"%d",&codigo_disciplina);
        Aluno* a = buscar_aluno(codigo_aluno,al);
        Disciplina* d = buscar_disciplina(codigo_disciplina,di);
        append_aluno_disciplina(a,d,sem);
    }
    fclose(f);
    return sem;
}

void save_al(Aux_al* al){
    FILE* f = fopen("alunos.txt", "w");
    if(f==NULL) return;
    Aluno* aux = al->first;
    while(aux!=NULL){
        fprintf(f,"%d\n",aux->codigo);
        
        fprintf(f,"%s\n",aux->nome);
        
        fprintf(f,"%s\n",aux->cpf);
        
        fprintf(f,"\n");

        aux = aux->prox;
    }
    fclose(f);
}

void save_di(Aux_di* di){
    FILE* f = fopen("disciplinas.txt", "w");
    if(f==NULL) return;

    Disciplina* aux = di->first;
    while(aux!=NULL){
        fprintf(f,"%d\n",aux->codigo);
        
        fprintf(f,"%s\n",aux->prof);
        
        fprintf(f,"%s\n",aux->nome);

        fprintf(f,"%d\n",aux->creditos);
        
        fprintf(f,"\n");

        aux = aux->prox;
    }
    fclose(f);
}

void save_sem(Semestre* sem){
    char concat[100]="semestre";
    strcat(concat,sem->nome);
    strcat(concat,".txt");
    FILE* f = fopen(concat, "w");
    if(f==NULL) return;
    Aluno_Disciplina* aux = sem->first;
    while(aux){
        fprintf(f,"%d\n",aux->aluno->codigo);
        fprintf(f,"%d\n",aux->disciplina->codigo);
        fprintf(f,"\n");
        aux = aux->prox;
    }
    fclose(f);
}