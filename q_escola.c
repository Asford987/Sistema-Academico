#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 30
#define DIM2 30


typedef struct Aluno Aluno ;
typedef struct Disciplina Disciplina ;
typedef struct Cadastro Cadastro;

struct Aluno{
    char nome[DIM];
    int codigo;
    char cpf[12];
    Aluno *prox;
    Disciplina *disciplinas[DIM2];
    };

typedef struct Aux_al Aux_al;
struct Aux_al{
    Aluno *first;
    Aluno *end;
};

struct Disciplina{
    char nome[DIM];
    char prof[DIM];
    int codigo;
    int creditos;
    Disciplina *prox;
    Aluno *alunos[DIM2];
};

typedef struct Aux_di Aux_di;
struct Aux_di{
    Disciplina *first;
    Disciplina *end;
};

void append_disciplina(Aux_di *di){
    char nome[DIM];
    char prof[DIM];
    int codigo;
    int creditos;
    printf("Digite o nome da Disciplina: ");
    scanf("%s",nome);
    printf("\nDigite o nome do professor: ");
    scanf("%s",prof);
    printf("\nDigite o codigo da disciplina: ");
    scanf("%d",&codigo);
    printf("\nDigite o numero de creditos da disciplina: ");
    scanf("%d",&creditos);
    Disciplina *aux=di->first;
    while(aux!=NULL){
        if(aux->codigo==codigo){
            printf("Essa Disciplina ja esta na cadastrada\n");
            return ;
        }
        aux=aux->prox;
    }
    Disciplina *new;
    new = (Disciplina*)malloc(sizeof(Disciplina));
    if(di->first==NULL){
        di->first=new;
        di->end=new;
        strcpy(new->nome,nome);
        strcpy(new->prof,prof);
        new->codigo=codigo;
        new->creditos=creditos;
        new->prox=NULL;
        new->alunos[0]=NULL;
    }
    strcpy(new->nome,nome);
    strcpy(new->prof,prof);
    new->codigo=codigo;
    new->creditos=creditos;
    new->prox=NULL;
    new->alunos[0]=NULL;
    di->end->prox=new;
    di->end=new;
}

void append_aluno(Aux_al *al){
    char nome[DIM];
    int codigo;
    char cpf[12];
    printf("Digite o nome: ");
    scanf("%s",nome);
    printf("\nDigite o codigo do aluno: ");
    scanf("%d",&codigo);
    printf("\nDigite o cpf: ");
    scanf("%s",cpf);
    Aluno *aux=al->first;
    while(aux!=NULL){
        if(!strcmp(aux->cpf,cpf)){
            printf("Esse aluno ja esta cadastrado\n");
            return ;
        }
        aux=aux->prox;
    }
    Aluno *new;
    new = (Aluno*)malloc(sizeof(Aluno));
    if(al->first==NULL){
        al->first=new;
        al->end=new;
        strcpy(new->nome,nome);
        new->codigo=codigo;
        new->prox=NULL;
        new->disciplinas[0]=NULL;
        strcpy(new->cpf,cpf);
        return;
    }
    strcpy(new->nome,nome);
    new->codigo=codigo;
    new->prox=NULL;
    new->disciplinas[0]=NULL;
    strcpy(new->cpf,cpf);
    al->end->prox=new;
    al->end=new;
}

void add_disciplina(Aluno *aluno,Disciplina *disciplina){
    int i=0;
    while((aluno->disciplinas)[i]!=NULL){
        i++;
    }
    (aluno->disciplinas)[i]=disciplina;
    (aluno->disciplinas)[i+1]=NULL;
}

void add_aluno(Aluno *aluno,Disciplina *disciplina){
    int i=0;
    while((disciplina->alunos)[i]!=NULL){
        i++;
    }
    (disciplina->alunos)[i]=aluno;
    (disciplina->alunos)[i+1]=NULL;
}

void print_al(Aux_al *al){
    Aluno *aux=al->first;
    while(aux->prox!=NULL || aux==NULL){
        printf("%d ",aux->codigo);
        aux=aux->prox;
    }
    printf("%d \n",aux->codigo);
}

void print_di(Aux_di *di){
    Disciplina *aux=di->first;
    while(aux->prox!=NULL || aux==NULL){
        printf("%d ",aux->codigo);
        aux=aux->prox;
    }
    printf("%d ",aux->codigo);
}

void cadastrar_alunos(Aux_al *al){
    int continuar;
    do{
        append_aluno(al);
        printf("\nDeseja cadastrar mais alunos? (digite 0 para nao ou 1 para sim) ");
        scanf("%d",&continuar);
    }
    while(continuar);
}

void cadastrar_disciplinas(Aux_di *di){
    int continuar;
    do{
        if(di->first==NULL){
            char nome[DIM];
            char prof[DIM];
            int codigo;
            int creditos;
            printf("Digite o nome da Disciplina: ");
            scanf("%s",nome);
            printf("\nDigite o nome do professor: ");
            scanf("%s",prof);
            printf("\nDigite o codigo da disciplina: ");
            scanf("%d",&codigo);
            printf("\nDigite o numero de creditos da disciplina: ");
            scanf("%d",&creditos);
            Disciplina *new;
            new = (Disciplina*)malloc(sizeof(Disciplina));
            strcpy(new->nome,nome);
            strcpy(new->prof,prof);
            new->codigo=codigo;
            new->creditos=creditos;
            new->prox=NULL;
            new->alunos[0]=NULL;
            di->first=new;
            di->end=new;
        }
        else{
            append_disciplina(di);
        }
        printf("\nDeseja cadastrar mais disciplinas? (digite 0 para nao ou 1 para sim) ");
        scanf("%d",&continuar);
    }
    while(continuar);
}

Aluno * buscar_aluno(int codigo, Aux_al *al){
    Aluno *aux=al->first;
    while(aux!=NULL){
        if(aux->codigo==codigo){
            return aux;
        }
        aux=aux->prox;
    }
    printf("Nao foi possivel encontrar o aluno com codigo %d. Digite novamente\n",codigo);
    return NULL;
}

void remove_al(Aux_al *al, int codigo){
    Aluno *aux=al->first;
    if(aux->codigo==codigo){
        al->first=al->first->prox;
        return;
    }
    else{
        while(aux!=NULL){
            if(aux->prox->codigo==codigo){
                aux->prox=aux->prox->prox;
                return;
            }
            aux=aux->prox;
        }
        printf("Nao foi possivel encontrar o aluno com codigo %d. Digite novamente\n",codigo);
        return;
    }
}

void remove_di(Aux_di *di, int codigo){
    Disciplina *aux=di->first;
    if(aux->codigo==codigo){
        di->first=di->first->prox;
        return;
    }
    else{
        while(aux!=NULL){
            if(aux->prox->codigo==codigo){
                aux->prox=aux->prox->prox;
                return;
            }
            aux=aux->prox;
        }
        printf("Nao foi possivel encontrar o aluno com codigo %d. Digite novamente\n",codigo);
        return;
    }
}

Disciplina *buscar_disciplina(int codigo, Aux_di* di){
    Disciplina *aux=di->first;
    while(aux!=NULL){
        if(aux->codigo==codigo){
            return aux;
        }
        aux=aux->prox;
    }
    printf("Nao foi possivel encontrar a disciplina com codigo %d. Digite novamente\n",codigo);
    return NULL;
}

void cadastrar_al_di(Aux_al *al,Aux_di *di){
    int continuar=1;
    do{
        int codigo_al,codigo_di;
        Aluno *aluno;
        Disciplina *disciplina;
        printf("digite o codigo do aluno: ");
        scanf("%d",&codigo_al);
        aluno=buscar_aluno(codigo_al,al);
        if(aluno==NULL) {
            printf("\naluno nao encontrado\n");
            continue;
        }

        printf("digite o codigo da disciplina que voce deseja cadastrar o aluno: ");
        scanf("%d",&codigo_di);
        disciplina= buscar_disciplina(codigo_di,di);
        if(disciplina==NULL){
            printf("\ndisciplina nao encontrada\n");
            continue;
        }

        add_aluno(aluno,disciplina);
        add_disciplina(aluno,disciplina);
        printf("\nDeseja cadastrar mais alunos em disciplinas? (digite 0 para nao ou 1 para sim) ");
        scanf("%d",&continuar);
    }
    while(continuar);
}

void free_al(Aux_al *al){
    Aluno *aux=al->first;
    while(aux!=NULL){
        Aluno *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    free(al);
}

void free_di(Aux_di *di){
    Disciplina *aux=di->first;
    while(aux!=NULL){
        Disciplina *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    free(di);
}

// void nulo_al(Aux_al *al){
//     Aluno *aux=al->first,*prox;
//     while(aux!=NULL){
//         for(int i=0;i<DIM2;i++){
//             (aux->disciplinas)[i]=NULL;
//             free((aux->disciplinas)[i]);
//         }
//         aux=aux->prox;
//     }
// }

// void nulo_di(Aux_di *di){
//     Disciplina *aux=di->first;
//     while(aux!=NULL){
//         for(int i=0;i<DIM2;i++){
//             (aux->alunos)[i]=NULL;
//             free((aux->alunos)[i]);
//         }
//         aux=aux->prox;
//     }
// }

void printar_disciplinas(Aux_al *al){
    int codigo;
    printf("digite o codigo do aluno: ");
    scanf("%d",&codigo);
    Aluno *aluno=buscar_aluno(codigo,al);
    printf("As disciplinas sao: ");
    for(int i=0;(aluno->disciplinas)[i]!=NULL;i++){
        printf("%s ",(aluno->disciplinas)[i]->nome);
    }
    return;
}

void printar_alunos(Aux_di *di){
    int codigo;
    printf("digite o codigo da disciplina: ");
    scanf("%d",&codigo);
    Disciplina *disciplina=buscar_disciplina(codigo,di);
    printf("Os alunos são: ");
    for(int i=0;(disciplina->alunos)[i]!=NULL;i++){
        printf("%s ",(disciplina->alunos)[i]->nome);
    }
    return;
}

int main(){
    while(1){
        int novo,salvar,escolha,oq,codigo_al,codigo_di;
        char sem[10];
        printf("Voce gostaria de cadastrar um novo semestre (digite 1) ou visualizar um ja salvo (digite 0)?");
        scanf("%d",&novo);
        if(novo){
            Aux_di *di;
            Aux_al *al;
            al=(Aux_al*)malloc(sizeof(Aux_al));
            di=(Aux_di*)malloc(sizeof(Aux_di));
            al->first=NULL;
            al->end=NULL;
            di->first=NULL;
            di->end=NULL;
            printf("qual semestre voce quer adicionar? (digite na forma 2018.2)");
            scanf("%s",sem);
            printf("CADASTRE AS INFORMACOES DOS ALUNOS\n");
            cadastrar_alunos(al);
            printf("CADASTRE AS INFORMACOES DAS DISCIPLINAS\n");
            cadastrar_disciplinas(di);
            printf("CADASTRE OS ALUNOS NAS DISCIPLINAS\n");
            cadastrar_al_di(al,di);
            
            printf("o que voce deseja fazer? (digite o numero correspondente)\n\n0 - cadastrar um aluno\n1 - cadastrar uma disciplina\n2 - remover aluno\n3 - remover disciplina\n4 - consultar disciplinas de um aluno\n5 - consultar alunos de uma disciplina\n");
            scanf("%d",&oq);
            switch (oq){
                case 0:
                    append_aluno(al);
                    break;
                case 1:
                    append_disciplina(di);
                    break;
                case 2:
                    printf("digite o codigo do aluno: ");
                    scanf("%d",&codigo_al);
                    remove_al(al,codigo_al);
                    break;
                case 3:
                    printf("digite o codigo do aluno: ");
                    scanf("%d",&codigo_di);
                    remove_di(di,codigo_di);
                    break;
                case 4:
                    printar_disciplinas(al);
                    break;
                case 5:
                    printar_alunos(di);
                    break;

            }

            printf("voce gostaria de salvar?(digite 1 para sim ou 0 para nao)");
            scanf("%d",salvar);
            if(salvar){
            
            }
            else{
                printf("voce gostaria de recomeçar? (digite 1 para sim ou 0 para nao)");
                scanf("%d",escolha);
                if(!escolha){
                    free_di(di);
                    free_al(al); 
                    return 0;  
                }
            }
            free_di(di);
            free_al(al);
        }
    }
    // print_al(al);
    // print_di(di);

    // nulo_al(al);
    // nulo_di(di);

}