#include "includes.h"

void set_rng();
float rng_f();
int rng_a();
int rng_d();
int array_comparator(int* a, int* b);
void store_data(FILE* f);
void save_al(Aux_al* al);
void save_di(Aux_di* di);
void save_sem(Semestre* sem);
Semestre* completar_semestre(char* nome, Aux_al* al, Aux_di* di);
Aux_al* completar_aluno();
Aux_di* completar_disciplina();
// list_aluno* retrieve_student_data(char* file_name);

// list_disciplina* retrieve_discipline_data(char* file_name);