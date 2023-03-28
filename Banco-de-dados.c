#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 30
#define DIM2 30
#define CPF 12


typedef struct Aluno Aluno ;
typedef struct Disciplina Disciplina ;
typedef struct Cadastro Cadastro;

struct Aluno{
    char nome[DIM];
    int codigo;
    char cpf[12];
    Aluno *prox;
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
};

typedef struct Semestre Semestre;
typedef struct Aluno_Disciplina Aluno_Disciplina;
struct Semestre{
    Aluno_Disciplina *first;
    Aluno_Disciplina *end;
    char nome[DIM];
};

struct Aluno_Disciplina{
    Aluno *aluno;
    Disciplina *disciplina;
    Aluno_Disciplina *prox;
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
        return;
    }
    strcpy(new->nome,nome);
    strcpy(new->prof,prof);
    new->codigo=codigo;
    new->creditos=creditos;
    new->prox=NULL;
    di->end->prox=new;
    di->end=new;
}

void append_aluno(Aux_al *al){
    char nome[DIM];
    int codigo;
    char cpf[CPF];
    printf("Digite o nome: ");
    scanf("%s",nome);
    printf("\nDigite o codigo do aluno: ");
    scanf("%d",&codigo);
    printf("\nDigite o cpf: ");
    scanf("%s",cpf);
    Aluno *aux=al->first;
    while(aux!=NULL){
        if(aux->codigo==codigo){
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
        strcpy(new->cpf,cpf);
        return;
    }
    strcpy(new->nome,nome);
    new->codigo=codigo;
    new->prox=NULL;
    strcpy(new->cpf,cpf);
    al->end->prox=new;
    al->end=new;
}

void print_al(Aux_al *al){
    Aluno *aux=al->first;
    while(aux!=NULL){
        printf("%s - %d\n",aux->nome,aux->codigo);
        aux=aux->prox;
    }
    return;
}

void print_di(Aux_di *di){
    Disciplina *aux=di->first;
    while(aux!=NULL){
        printf("%s - %d\n",aux->nome,aux->codigo);
        aux=aux->prox;
    }
    return;
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
        append_disciplina(di);
        printf("\nDeseja cadastrar mais disciplinas? (digite 0 para nao ou 1 para sim) ");
        scanf("%d",&continuar);
    }
    while(continuar);
}

void remove_al(Aux_al *al){
    int codigo;
    Aluno *aux=al->first,*aux2;
    printf("digite o codigo do aluno:");
    scanf("%d",&codigo);
    if(aux==NULL) return;
    if(aux->codigo==codigo){
        al->first=al->first->prox;
        free(aux);
        return;
    }
    else{
        while(aux->prox!=NULL){
            if(aux->prox->codigo==codigo){
                aux2=aux->prox;
                aux->prox=aux->prox->prox;
                free(aux2);
                return;
            }
            aux=aux->prox;
        }
        printf("Nao foi possivel encontrar o aluno com codigo %d. Digite novamente\n",codigo);
        return;
    }
}

void remove_di(Aux_di *di){
    int codigo;
    Disciplina *aux=di->first,*aux2;
    printf("digite o codigo da disciplina:");
    scanf("%d",&codigo);
    if(aux==NULL)return;
    if(aux->codigo==codigo){
        di->first=di->first->prox;
        free(aux);
        return;
    }
    else{
        while(aux->prox!=NULL){
            if(aux->prox->codigo==codigo){
                aux2=aux->prox;
                aux->prox=aux->prox->prox;
                free(aux2);
                return;
            }
            aux=aux->prox;
        }
        printf("Nao foi possivel encontrar o aluno com codigo %d. Digite novamente\n",codigo);
        return;
    }
}

Aluno * buscar_aluno(int codigo, Aux_al *al){
    Aluno *aux=al->first;
    while(aux!=NULL){
        if(aux->codigo==codigo){
            return aux;
        }
        aux=aux->prox;
    }
    return NULL;
}

Disciplina *buscar_disciplina(int codigo, Aux_di* di){
    Disciplina *aux=di->first;
    while(aux!=NULL){
        if(aux->codigo==codigo){
            return aux;
        }
        aux=aux->prox;
    }
    return NULL;
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


////////////////////////// DESSA PARTE PRA BAIXO SAO AS FUNÇOES ESPECIFICAS DO SEMESTRE


Aluno_Disciplina* buscar_aluno_disciplina(Aluno *aluno,Disciplina *disciplina,Semestre *sem){
    Aluno_Disciplina *aux=sem->first;
    while(aux!=NULL){
        if(aux->aluno==aluno && aux->disciplina==disciplina){
            return aux;
        }
        aux=aux->prox;
    }
    return NULL;
}

int append_aluno_disciplina(Aluno *aluno,Disciplina *disciplina,Semestre *sem){
    Aluno_Disciplina *aux=sem->first;
    if(aux==NULL){
        Aluno_Disciplina *new=(Aluno_Disciplina*)malloc(sizeof(Aluno_Disciplina));
        new->aluno=aluno;
        new->disciplina=disciplina;
        new->prox=NULL;
        sem->first=new;
        sem->end=new;
        return 1;
    }
    if(buscar_aluno_disciplina(aluno,disciplina,sem)!=NULL) return 0;
    Aluno_Disciplina *new=(Aluno_Disciplina*)malloc(sizeof(Aluno_Disciplina));
    new->aluno=aluno;
    new->disciplina=disciplina;
    new->prox=NULL;
    sem->end->prox=new;
    sem->end=new;
    return 1;
}

void free_semestre(Semestre *sem){
    Aluno_Disciplina *aux=sem->first,*temp;
    while(aux!=NULL){
        temp=aux;
        aux=aux->prox;
        free(temp);
    }
    free(sem);
}

void insercao_semestre(Semestre *sem,Aux_al *al,Aux_di *di){
    int continuar;
    do{
        int codigo_al,codigo_di,printar;
        Aluno *aluno;
        Disciplina *disciplina;
        printf("Voce deseja ver a lista de alunos? (digite 0 para nao ou 1 para sim)");
        scanf("%d",&printar);
        if(printar==1) print_al(al);
        printf("digite o codigo do aluno: ");
        scanf("%d",&codigo_al);
        aluno=buscar_aluno(codigo_al,al);
        if(aluno==NULL) {
            printf("\naluno nao encontrado\n");
            printf("\nDeseja tentar novamente? (digite 0 para nao ou 1 para sim) ");
            scanf("%d",&continuar);
            if(continuar==0) break;
            else continue;
        }
        printar=0;
        printf("Voce deseja ver a lista de disciplinas? (digite 0 para nao ou 1 para sim)");
        scanf("%d",&printar);
        if(printar==1) print_di(di);
        printf("digite o codigo da disciplina que voce deseja cadastrar o aluno: ");
        scanf("%d",&codigo_di);
        disciplina= buscar_disciplina(codigo_di,di);
        if(disciplina==NULL){
            printf("\ndisciplina nao encontrada\n");
            printf("\nDeseja tentar novamente? (digite 0 para nao ou 1 para sim) ");
            scanf("%d",&continuar);
            if(continuar==0) break;
            else continue;
        }
        if(!append_aluno_disciplina(aluno,disciplina,sem)){
            printf("o aluno ja esta cadastrado");
        }
        printf("\nDeseja cadastrar mais alunos em disciplinas? (digite 0 para nao ou 1 para sim) ");
        scanf("%d",&continuar);
    }
    while(continuar);
    return;

}

int remove_aluno_disciplina(Semestre *sem,Aux_al *al,Aux_di *di){
    int codigo_al,codigo_di;
    printf("Digite o codigo do Aluno: ");
    scanf("%d",&codigo_al);
    Aluno *aluno=buscar_aluno(codigo_al,al);
    if(aluno==NULL){
        printf("Nao foi encontrado esse aluno, deseja tentar novamente? (digite 0 para nao ou 1 para sim");
        int novamente;
        scanf("%d",&novamente);
        if(novamente==1)return 0;
        else{
            remove_aluno_disciplina(sem,al,di);
            return 0;
        }
    }
    printf("Digite o codigo da Disciplina: ");
    scanf("%d",&codigo_di);
    Disciplina *disciplina=buscar_disciplina(codigo_di,di);
    if(disciplina==NULL){
        printf("Nao foi encontrada essa disciplina, deseja tentar novamente? (digite 0 para nao ou 1 para sim");
        int novamente;
        scanf("%d",&novamente);
        if(novamente==1)return 0;
        else{
            remove_aluno_disciplina(sem,al,di);
            return 0;
        }
    }
    Aluno_Disciplina *aux=sem->first,*aux2;
    if(aux==NULL){
        printf("nao ha nenhum aluno cadastrado a nenhuma disciplina nesse semestre");
        return 0;
    }
    if(aux->aluno==aluno && aux->disciplina==disciplina){
        sem->first=sem->first->prox;
        free(aux);
        return 0;
    }
    while(aux->prox!=NULL){
        if(aux->prox->aluno==aluno && aux->prox->disciplina==disciplina){
            aux2=aux->prox;
            aux->prox=aux->prox->prox;
            free(aux2);
            return 1;
        }
        aux=aux->prox;
    }
    return 0;
}

void print_dis_al(Aux_al *al,Aux_di *di,Semestre *sem){
    int codigo;
    Aluno *aluno;
    Disciplina *aux=di->first;
    printf("Digite o codigo do aluno");
    scanf("%d",&codigo);
    aluno=buscar_aluno(codigo,al);
    if(aluno==NULL){
        printf("nao foi possivel encontrar um aluno com codigo %d",codigo);
        return;
    }
    while(aux!=NULL){
        if(buscar_aluno_disciplina(aluno,aux,sem)!=NULL){
            printf("%s - %s\n",aluno->nome,aux->nome);
        }
        aux=aux->prox;
    }
    return;
}

void print_alu_di(Aux_al *al,Aux_di *di,Semestre *sem){
    int codigo;
    Aluno *aux=al->first;
    Disciplina *disciplina;
    printf("Digite o codigo da disciplina");
    scanf("%d",&codigo);
    disciplina=buscar_disciplina(codigo,di);
    if(disciplina==NULL){
        printf("nao foi possivel encontrar uma disciplina com codigo %d",codigo);
        return;
    }
    while(aux!=NULL){
        if(buscar_aluno_disciplina(aux,disciplina,sem)!=NULL){
            printf("%s - %s\n",aux->nome,disciplina->nome);
        }
        aux=aux->prox;
    }
    return;
}

void menu_semestre(Semestre *sem,Aux_al *al,Aux_di *di){
    printf("Voce esta no semestre %s\nO que voce deseja fazer?\n",sem->nome);
    printf("1 - cadastrar um aluno em uma disciplina\n2 - Remover um aluno de uma disciplina\n3 - Consultar as disciplinas de um aluno\n4 - Consultar os alunos cadastrados em uma disciplina\n5 - Sair\n");
    int opcao;
    scanf("%d",&opcao);
    switch (opcao){
        case 1:
            insercao_semestre(sem,al,di);
            break;
        case 2:
            remove_aluno_disciplina(sem,al,di);
            break;
        case 3:
            print_dis_al(al,di,sem);
            break;
        case 4:
            print_alu_di(al,di,sem);
            break;
        case 5:
            return;
        default:
            break;
    }
    menu_semestre(sem,al,di);


    //inserçao
    //remoçao
    //consultas de disciplinas de um aluno
    //consultas dos alunos em uma disciplina
    //salvamento (obrigatorio?)
}

void menu_alunos(Aux_al *al,Aux_di *di){
    printf("Voce esta no menu principal\nO que voce deseja fazer?");
    printf("\n0 - Entrar em um semestre\n1 - Ver os alunos cadastrados\n2 - Ver as disciplinas cadastradas\n3 - adicionar novos alunos\n4 - adiconar novas disciplinas\n5 - remover algum aluno\n6 - remover alguma disciplina\n7 - Sair\n");
    int opcao;
    scanf("%d",&opcao);
    Semestre *sem=(Semestre*)malloc(sizeof(Semestre));
    switch (opcao){
        case 0:
            printf("\nQual semestre voce quer entrar?\n");//nesse ponto ele mostra a lista de semestres que já existem e pede pro usuario escolher um, o semestre pode estar vazio
            char nome[DIM2];
            scanf("%s",nome);
            //nesse ponto ele pega monta a lista encadeada pelo arquivo .txt, caso o arquivo .txt esteja vazio ele faz end e first ser nulo
            //sem=complete_semestre(nome)
            sem->end=NULL;
            sem->first=NULL;
            strcpy(sem->nome,nome);
            menu_semestre(sem,al,di);
            break;
        case 1:
            print_al(al);
            break;
        case 2:
            print_di(di);
            break;
        case 3:
            cadastrar_alunos(al);
            break;
        case 4:
            cadastrar_disciplinas(di);
            break;
        case 5:
            remove_al(al);
            break;
        case 6:
            remove_di(di);
            break;
        case 7:
            //save_sem();
            free_semestre(sem);
            return;
            break;
        default:
            break;
    }
    menu_alunos(al,di);
}

int main(){

    Aux_al *al=(Aux_al*)malloc(sizeof(Aux_al));//*al=completar_alunos(), se vazio aponta pra null nas duas entradas
    Aux_di *di=(Aux_di*)malloc(sizeof(Aux_di));// ' ' 
    //al=completar_alunos();
    al->first=NULL;
    al->end=NULL;
    di->first=NULL;
    di->end=NULL;
    menu_alunos(al,di);
    //save_al();
    //save_di();
    free_al(al);
    free_di(di);
}

    //fopen(aluno,disciplina)
    //se já tiver arquivo pergunta se quer entrar ou recomeçar
    //se vazio pergunta se quer preencher
    ////preenche a lista encadeada
    //menu de modificações do aluno/disciplinas e entrar em um semestre(inclui sair do menu)

    //pergunta qual semestre
    //se ja tiver arquivo pergunta se quer entrar ou recomeçar
    //se vazio pergunta se quer preencher
    ////preenche a lista encadeada
    //menu de modificações do semestre (inclui sair do menu)
    //saindo salva o semestre e apaga a lista encadeada do semestre

    //saindo, volta pro menu aluno/disciplinas
    //saindo full salva o arquivo aluno/disciplinas e libera a lista encadeada
