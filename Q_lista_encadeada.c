#include <stdio.h>
#include <stdlib.h>

typedef struct Lista Lista;
struct Lista{
    int value;
    Lista *prox;
};

Lista * buscar_ultimo(Lista *uno){
        Lista * aux = uno;
        while(aux->prox!=NULL){
            aux=aux->prox;
            //printf("--\n");
            //printf("%d\n\n",aux->value);
        }
        return aux;
    }
void append(Lista *uno, int num){
    Lista *ult,*new;
    new=(Lista*)malloc(sizeof(Lista));
    ult=(Lista*)malloc(sizeof(Lista));
    ult=buscar_ultimo(uno);
    new->value=num;
    ult->prox=new;
    new->prox=NULL;
}

void print_lista(Lista *uno){
    Lista *aux=uno;
    while(aux->prox!=NULL || aux==NULL){
        printf("%d ",aux->value);
        aux=aux->prox;
    }
    printf("%d",aux->value);
}

void free_lista(Lista *uno){
    Lista *aux=uno,*duo=uno;
    while(duo!=NULL){
        aux=duo;
        //printf("%d",duo->value);
        duo=aux->prox;
        //printf("%d",duo->value);
        printf("-");
        free(aux);
    }
    
    //uno=NULL;

    print_lista(uno);
}

int main(){
    int n=0,num=2;
    printf("Quantos elementos voce quer adicionar? ");
    scanf("%d",&n);
    Lista uno,*ult;
    printf("Digite o 1 elemento :");
    scanf("%d",&num);
    uno.value=num;
    uno.prox=NULL;
    for(int i=0;i<n-1;i++){
        printf("Digite o %d elemento :",i+2);
        scanf("%d",&num);
        append(&uno,num);
    }

    print_lista(&uno);
    free_lista(&uno);    
    printf("//");
    print_lista(&uno);
    //printf("%d",(*buscar_ultimo(&uno)).value);
    return 0;
}