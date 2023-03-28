Aluno_Disciplina* buscar_aluno_disciplina(Aluno *aluno,Disciplina *disciplina,Semestre *sem);
int append_aluno_disciplina(Aluno *aluno,Disciplina *disciplina,Semestre *sem);
void free_semestre(Semestre *sem);
void insercao_semestre(Semestre *sem,Aux_al *al,Aux_di *di);
int remove_aluno_disciplina(Semestre *sem,Aux_al *al,Aux_di *di);
void print_dis_al(Aux_al *al,Aux_di *di,Semestre *sem);
void print_alu_di(Aux_al *al,Aux_di *di,Semestre *sem);
void menu_semestre(Semestre *sem,Aux_al *al,Aux_di *di);
void menu_alunos(Aux_al *al,Aux_di *di);