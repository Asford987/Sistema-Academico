#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void question_1(int n), question_3(),question_4(),question_6(int n),question_7(int n);
int question_2(int n,int aux),question_5(int n);

int main(){
    int num, n;
    printf("Qual Questao Voce quer resolver ? ");
    scanf("%d",&num);
    switch(num){
    case 1:
        printf("escolha n: ");
        scanf("%d",&n);
        question_1(n);
        break;
    case 2:
        printf("escolha n: ");
        scanf("%d",&n);
        question_2(n,2);
        break;
    case 3:
        question_3();
        break;
    case 4:
        question_4();
        break;
    case 5:
        printf("escolha n: ");
        scanf("%d",&n);
        printf("%d",question_5(n));
        break;
    case 6:
        printf("escolha n: ");
        scanf("%d",&n);
        question_6(n);
        break;
    case 7:
        printf("escolha n: ");
        scanf("%d",&n);
        question_7(n);
        break;
    
    default:
        break;
    }
return 0;
}

void question_1 (int n){  
        for (int i=2; i<n; i+=2){
            printf("%d ",i);
        }
    }

int question_2 (int n, int aux){
        printf("%d ",aux);
        if (aux==2*((n-1)/2) ){
            return 0;
        }
        question_2(n,aux+2);
    }

void question_3(){
        FILE *f;
        f=fopen("q3.txt","r");
        if (!f){
            exit(1);
        }
        int var,soma=0,prod=1;
        while(!feof(f)){
            fscanf(f,"%d",&var);
            if (var%2==1){
                soma+=var;
            }
            else{
                prod*=var;
            }
            }
        fclose(f);
        printf("%d %d",prod,soma);
    }

void question_4(){
    FILE *f;
    f=fopen("q4.txt","r");
    char gen;
    int soma1=0,cont1=0,nota,soma2=0,cont2=0;
    if(!f){
        exit(1);
    }
    while(!feof(f)){
        fscanf(f,"%c %d",&gen,&nota);
        fflush(stdin);
        if(gen=='M'){
            soma1+=nota;
            cont1++;
        }
        else if(gen=='F'){
            soma2+=nota;
            cont2++;
        }
    }
    if(cont1==0){
        if(cont2==0){
            exit(1);
        }
        else{
            printf("F %.1f",(float)soma2/cont2);
        }
    }
    else if (cont2==0){
        printf("M %.1f",(float)soma1/cont1);
    }
    else if ((float)soma1/cont1>=(float)soma2/cont2){
        printf("M %.1f",(float)soma1/cont1);
    }
    else{
        printf("F %.1f",(float)soma2/cont2);
    }
    fclose(f);
}

int question_5(int n){
    if(n==1 || n==0){
        return n;
    }
    return question_5(n-1)+ question_5(n-2);
}

void question_6(int n){
    int fn=1,fn_=0,aux=0;
    for(int i=1;i<n;i++){
        aux=fn;
        fn+=fn_;
        fn_=aux;
    }
    printf("%d",fn);
}

void bubble_sort(int *v,int n){
        int cont=1,aux=0,rr=0;
        while(cont!=0){
            cont=0;
            for(int j=0;j<n-1;j++){
                rr++;
                if(v[j]>v[j+1]){
                    cont=1;
                    aux=v[j];
                    v[j]=v[j+1];
                    v[j+1]=aux;
                }
            }
        }
    }

void question_7(int n){
    int v[n];
    for(int i=0;i<n;i++){
        v[i]=rand()%100;
    }
    bubble_sort(v,n);
    for(int i=0;i<n;i++){
        printf("%d ",v[i]);
        }
}
