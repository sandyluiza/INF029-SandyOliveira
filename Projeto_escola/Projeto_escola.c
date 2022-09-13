#include <stdio.h>
#include <string.h>
void aluno();
void professor();
void disciplina();
void inc_aluno();
void inc_prof();
void inc_disc();
void exc_alun();
void exc_prof();
void exc_discip();
void atua_alun();
void atua_prof();
void atua_discip();
void relatorios();
void lista_prof_nasc();
void lista_prof_nome();
void lista_prof_sex();
void lista_aluno_nasci();
void lista_aluno_nome();
void lista_aluno_sex();
void lista_uma_disci();
void lista_disciplina();
void lista_prof();
void lista_aluno();


// estruturas de cadastro básico
typedef struct
{
  char matricula[20];
  char nome[50];
  char sexo[2];
  char dataNasc[12];
  char cpf[13];
}
estru_aluno;
typedef struct
{
  char matricula[20];
  char nome[50];
  char sexo[2];
  char dataNasc[12];
  char cpf[13];
}
estru_professor;
typedef struct
{
  char nome[50];
  char codigo[20];
  char semestre[12];
  char professor[50];
}
estru_disciplina;

// cadastros funções básicas de aluno/professor/disciplina
void aluno()
{
  int opcao_1;
  printf("\nDigite a opção que deseja realizar:\n");
  printf("1 - Incluir aluno\n2 - Excluir aluno\n3 - Atualizar dados de aluno\n");
  scanf("%d", &opcao_1);
  if (opcao_1 == 1)
  {
    inc_aluno();
  }
  else if(opcao_1 == 2)
  {
    exc_alun();
  }
  else if (opcao_1 == 3)
  {
    atua_alun();
  }
}
void professor()
{
  int opcao_2;
  printf("\nDigite a opção que deseja realizar:\n");
  printf("1 - Incluir professor\n2 - Excluir professor\n3 - Atualizar dados de professor\n");
  scanf("%d", &opcao_2);
  if (opcao_2 == 1)
  {
    inc_prof();
  }
  else if(opcao_2 == 2)
  {
    exc_prof();
  }
  else if (opcao_2 == 3)
  {
    atua_prof();
  }
}
void disciplina()
{
  int opcao_3;
  printf("\nDigite a opção que deseja realizar:\n");
  printf("1 - Incluir disciplina\n2 - Excluir disciplina\n3 - Atualizar dados de disciplina\n");
  scanf("%d", &opcao_3);
  if (opcao_3 == 1)
  {
    inc_disc();
  }
  else if(opcao_3 == 2)
  {
    exc_discip();
  }
  else if (opcao_3 == 3)
  {
    atua_discip();
  }
  return;
  // adicionar/excluir alunos na disciplina// fazer depois//
}

// função de incluir
void inc_aluno()
{
  estru_aluno e_aluno[2];
  int i, n = 2;
  for (i=0; i<n; i++)
  {
    getchar();
    printf("\n");
    printf("Informe a matrícula ");
    fgets(e_aluno[i].matricula, 20, stdin);
    size_t l1 = strlen(e_aluno[i].matricula) - 1;
    if (e_aluno[i].matricula[l1] == '\n')
    {
      e_aluno[i].matricula[l1] = '\0';
    }
    printf("Informe o nome ");
    fgets(e_aluno[i].nome, 50, stdin);
    size_t l2 = strlen(e_aluno[i].nome) - 1;
    if (e_aluno[i].nome[l2] == '\n')
    {
      e_aluno[i].nome[l2] = '\0';
    }
    printf("Informe o sexo ");
    fgets(e_aluno[i].nome, 50, stdin);
    size_t l5 = strlen(e_aluno[i].nome) - 1;
    if (e_aluno[i].nome[l5] == '\n')
    {
      e_aluno[i].nome[l5] = '\0';
    }
    printf("Informe a data de nascimento ");
    fgets(e_aluno[i].dataNasc, 12, stdin);
    size_t l3 = strlen(e_aluno[i].dataNasc) - 1;
    if (e_aluno[i].dataNasc[l3] == '\n')
    {
      e_aluno[i].dataNasc[l3] = '\0';
    }
    printf("Informe o CPF ");
    fgets(e_aluno[i].cpf, 13, stdin);
    size_t l4 = strlen(e_aluno[i].cpf) - 1;
    if (e_aluno[i].cpf[l4] == '\n')
    {
      e_aluno[i].cpf[l4] = '\0';
    }
  }
  return;
}
void inc_prof()
{
  estru_professor e_professor[2];
  int i, n = 2;
  for (i=0; i<n; i++)
  {
    getchar();
    printf("\n");
    printf("Informe a matrícula ");
    fgets(e_professor[i].matricula, 20, stdin);
    size_t l1 = strlen(e_professor[i].matricula) - 1;
    if (e_professor[i].matricula[l1] == '\n')
    {
      e_professor[i].matricula[l1] = '\0';
    }
    printf("Informe o nome ");
    fgets(e_professor[i].nome, 50, stdin);
    size_t l2 = strlen(e_professor[i].nome) - 1;
    if (e_professor[i].nome[l2] == '\n')
    {
      e_professor[i].nome[l2] = '\0';
    }
    printf("Informe o sexo ");
    fgets(e_professor[i].nome, 50, stdin);
    size_t l5 = strlen(e_professor[i].nome) - 1;
    if (e_professor[i].nome[l5] == '\n')
    {
      e_professor[i].nome[l5] = '\0';
    }
    printf("Informe a data de nascimento ");
    fgets(e_professor[i].dataNasc, 12, stdin);
    size_t l3 = strlen(e_professor[i].dataNasc) - 1;
    if (e_professor[i].dataNasc[l3] == '\n')
    {
      e_professor[i].dataNasc[l3] = '\0';
    }
    printf("Informe o CPF ");
    fgets(e_professor[i].cpf, 13, stdin);
    size_t l4 = strlen(e_professor[i].cpf) - 1;
    if (e_professor[i].cpf[l4] == '\n')
    {
      e_professor[i].cpf[l4] = '\0';
    }
  }
  return;
}
void inc_disc()
{
  estru_disciplina e_disciplina[2];
  int i, n = 2;
  for (i=0; i<n; i++)
  {
    getchar();
    printf("\n");
    printf("Informe o nome ");
    fgets(e_disciplina[i].nome, 50, stdin);
    size_t l2 = strlen(e_disciplina[i].nome) - 1;
    if (e_disciplina[i].nome[l2] == '\n')
    {
      e_disciplina[i].nome[l2] = '\0';
    }
    printf("Informe o código ");
    fgets(e_disciplina[i].codigo, 20, stdin);
    size_t l5 = strlen(e_disciplina[i].codigo) - 1;
    if (e_disciplina[i].codigo[l5] == '\n')
    {
      e_disciplina[i].codigo[l5] = '\0';
    }
    printf("Informe o semestre ");
    fgets(e_disciplina[i].semestre, 12, stdin);
    size_t l3 = strlen(e_disciplina[i].semestre) - 1;
    if (e_disciplina[i].semestre[l3] == '\n')
    {
      e_disciplina[i].semestre[l3] = '\0';
    }
    printf("Informe o professor ");
    fgets(e_disciplina[i].professor, 50, stdin);
    size_t l4 = strlen(e_disciplina[i].professor) - 1;
    if (e_disciplina[i].professor[l4] == '\n')
    {
      e_disciplina[i].professor[l4] = '\0';
    }
  }
  return;
}

// função de excluir
void exc_alun()
{
  return;
}
void exc_prof()
{
  return;
}
void exc_discip()
{
  return;
}

// atualizar 
void atua_alun()
{
  return;
}
void atua_prof()
{
  return;
}
void atua_discip()
{
  return;
}

// RELATORIOS
void relatorios()
{
  int opcao_relat;
  printf("\nInforme o relatório que deseja gerar:\n");
  printf("1 - Listar alunos\n2 - Listar professores\n3 - Listar disciplinas(dados das disciplinas sem os alunos)\n4 - Listar uma disciplina(dados da disciplina e os alunos matriculados\n5 - Listar alunos por sexo(F/M)\n6 - Listar alunos ordenados por nome\n7 - Listar alunos ordenados por data de nascimento\n8 - Listar professores por sexo(F/M)\n9 - Listar professores ordenados por nome\n10 - Listar professores ordenados por data de nascimento\n");
  scanf("%d", &opcao_relat);
  if (opcao_relat == 1)
  {
    lista_aluno();
  }
  else if(opcao_relat == 2)
  {
    lista_prof();
  }
  else if (opcao_relat == 3)
  {
    lista_disciplina();
  }
  else if(opcao_relat == 4)
  {
    lista_uma_disci();
  }
  else if (opcao_relat == 5)
  {
    lista_aluno_sex();
  }
  else if (opcao_relat == 6)
  {
    lista_aluno_nome();
  }
  else if(opcao_relat == 7)
  {
    lista_aluno_nasci();
  }
  else if (opcao_relat == 8)
  {
    lista_prof_sex();
  }
  else if(opcao_relat == 9)
  {
    lista_prof_nome();
  }
  else if (opcao_relat == 10)
  {
    lista_prof_nasc();
  }
}

// RELATORIOS SEPARADOS
void lista_prof_nasc()
{
  return;
}
void lista_prof_nome()
{
  return;
}
void lista_prof_sex()
{
  return;
}
void lista_aluno_nasci()
{
  return;
}
void lista_aluno_nome()
{
  return;
}
void lista_aluno_sex()
{
  return;
}
void lista_uma_disci()
{
  return;
}
void lista_disciplina()
{
  return;
}
void lista_prof()
{
  return;
}
void lista_aluno()
{
  return;
}

// função para chamar as outras
int main()
{
  int opcao, opcao_cr;
  printf("\nInforme o que deseja realizar:\n");
  printf("1 - Adicionar/modificar/excluir cadastro\n2 - Gerar um relatório\n");
  scanf("%d", &opcao_cr);
  
  if (opcao_cr == 1)
  {
    printf("\nDigite a opção que deseja adicionar/modificar/excluir:\n");
    printf("1 - Aluno\n2 - Professor\n3 - Disciplina\n");
    scanf("%d", &opcao);
    
    if (opcao == 1)
    {
      aluno();
    }
    else if(opcao == 2)
    {
      professor();
    }
    else if (opcao == 3)
    {
      disciplina();
    }
  }
  else if(opcao_cr == 2)
  {
    relatorios();
  }
}