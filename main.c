#include "includes.h"




int main(){
    Aux_al *al=create_al();
    Aux_di *di=create_di();
    menu_alunos(al,di);
    save_al(al);
    save_di(di);
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
