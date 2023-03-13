#include <stdio.h>

int * rota(int *p,int *x){
    if(x==p){
        printf("iguais");
    }
    printf("%d  %d",*p,*x);
    return p;
}

int main(){
    int *p,x;
    x=5;
    p=&x;
    printf("%d",*p);
    int *a=rota(p,&x);
    printf("---%d",*a);
    return 0;
}