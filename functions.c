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

void store_data(FILE* f){
    f = fopen("dados.txt","w");
    if(f==NULL){
        int d = 0;
        printf("Falha em abrir arquivo!\n");
        printf("Tentar novamente: 1\nCancelar: 2\n");
        scanf("%d",&d);
        if(d == 2){
            char c='\0';
            printf("Tem certeza? Todos os dados serão perdidos (Y/N): ");
            scanf("%c",&c);
            printf("\n");
            if(c == 'y' || c == 'Y') return;
            else store_data(f);
        }
        else store_data(f);
    }

}

Aux_al* completar_aluno(){
    FILE* f = fopen("alunos.txt", "r");
    if(f==NULL) return create_al();
    while(!feof(f)){

    }
}

Aux_di* completar_disciplina(){
    FILE* f = fopen("disciplinas.txt", "r");
    if(f==NULL) return create_di();
    while(!feof(f)){

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

}

void save_di(Aux_di* di){
    FILE* f = fopen("disciplinas.txt", "w");
    if(f==NULL) return;
    
}

void save_semester(Semestre* sem){
    FILE* f = fopen(strcat(strcat("semestre",sem->nome),".txt"), "w");
    if(f==NULL) return;

}
// list_aluno* retrieve_student_data(char* file_name){
//     FILE* f = fopen(file_name,"r");
//     if(f == NULL){
//     }
//     int codigo;
//     char nome[30];
//     char cpf[12];
//     int i = 0, step = 4;
//     while(!feof(f)){
//         fscanf(f,"%d",&codigo);
//         for(int j=0;j<30;j++){
            
//         }

//         i+=step;
//     }
// }
// list_disciplina* retrieve_discipline_data(char* file_name){
//     FILE* f = fopen(file_name,"r");
//     if(f == NULL){
//     }
//     int codigo[4];
//     char nome[70];
//     char professor[70];
//     float credito;
//     int i = 0, step = 4;
//     while(!feof(f)){
//         for(int j = 0; j< 4; j++){
//             fscanf(f,"%d",&codigo[j]);
//         }
//         for(int j=0;j<30;j++){

//         }
//         i+=step;
//     }
// }