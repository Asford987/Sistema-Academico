
// typedef struct Cadastro Cadastro;

typedef struct Aluno{
    char nome[DIM];
    int codigo;
    char cpf[12];
    struct Aluno *prox;
} Aluno;

typedef struct Aux_al{
    Aluno *first;
    Aluno *end;
} Aux_al;

typedef struct Disciplina{
    char nome[DIM];
    char prof[DIM];
    int codigo;
    int creditos;
    struct Disciplina *prox;
} Disciplina;

typedef struct Aux_di{
    Disciplina *first;
    Disciplina *end;
} Aux_di;

typedef struct Aluno_Disciplina{
    Aluno *aluno;
    Disciplina *disciplina;
    struct Aluno_Disciplina *prox;
} Aluno_Disciplina;

typedef struct Semestre{
    Aluno_Disciplina *first;
    Aluno_Disciplina *end;
    char nome[DIM];
} Semestre;