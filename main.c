#include "includes.h"

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
