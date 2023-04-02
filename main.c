#include "includes.h"




int main(){
    Aux_al *al=completar_aluno();
    Aux_di *di=completar_disciplina();
    Semestre *sem = create_sem("");
    menu_alunos(al,di, sem);
    save_al(al);
    save_di(di);
    free_al(al);
    free_di(di);
}