#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
int main();
void alu_prof_disci();
void inse_alu_discip();
void exclu_alu_discip();

// estruturas de cadastro básico
typedef struct
{
  char matricula[20];
  char nome[50];
  char sexo[5];
  char dataNasc[12];
  char cpf[13];
}
estru_aluno;
typedef struct
{
  char matricula[20];
  char nome[50];
  char sexo[5];
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
  char aluno[50][100];
}
estru_disciplina;

// CHAMAR AS FUNÇÕES DE ADICIONAR MODIFICAR E EXCLUIR
void aluno(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  int opcao_1;
  printf("\nDigite a opção que deseja realizar:\n");
  printf("1 - Incluir aluno\n2 - Excluir aluno\n3 - Atualizar dados de aluno\n4 - Voltar\n");
  scanf("%d", &opcao_1);
  if (opcao_1 == 1)
  {
    inc_aluno(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if(opcao_1 == 2)
  {
    exc_alun(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if (opcao_1 == 3)
  {
    atua_alun(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if (opcao_1 == 4)
  {
    alu_prof_disci(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else
  {
    printf("Opção inválida.\n");
    aluno(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
}
void professor(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  int opcao_2;
  printf("\nDigite a opção que deseja realizar:\n");
  printf("1 - Incluir professor\n2 - Excluir professor\n3 - Atualizar dados de professor\n4 - Voltar\n");
  scanf("%d", &opcao_2);
  if (opcao_2 == 1)
  {
    inc_prof(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if(opcao_2 == 2)
  {
    exc_prof(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if (opcao_2 == 3)
  {
    atua_prof(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if (opcao_2 == 4)
  {
    alu_prof_disci(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else
  {
    printf("Opção inválida.\n");
    professor(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
}
void disciplina(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  int opcao_3;
  printf("\nDigite a opção que deseja realizar:\n");
  printf("1 - Incluir disciplina\n2 - Excluir disciplina\n3 - Atualizar dados de disciplina\n4 - Inserir aluno em disciplina\n5 - Excluir aluno de disciplina\n6 - Voltar\n");
  scanf("%d", &opcao_3);
  if (opcao_3 == 1)
  {
    inc_disc(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if(opcao_3 == 2)
  {
    exc_discip(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if (opcao_3 == 3)
  {
    atua_discip(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if (opcao_3 == 4)
  {
    inse_alu_discip(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if (opcao_3 == 5)
  {
    exclu_alu_discip(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if (opcao_3 == 6)
  {
    alu_prof_disci(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else
  {
    printf("Opção inválida.\n");
    disciplina(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
}

// INCLUIR CADASTROS
void inc_aluno(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  getchar();
  printf("\n");
  printf("Informe a matrícula ");
  fgets(e_aluno[qtdAluno].matricula, 20, stdin);
  size_t l1 = strlen(e_aluno[qtdAluno].matricula) - 1;
  if (e_aluno[qtdAluno].matricula[l1] == '\n')
  {
    e_aluno[qtdAluno].matricula[l1] = '\0';
  }
  printf("Informe o nome ");
  fgets(e_aluno[qtdAluno].nome, 50, stdin);
  size_t l2 = strlen(e_aluno[qtdAluno].nome) - 1;
  if (e_aluno[qtdAluno].nome[l2] == '\n')
  {
    e_aluno[qtdAluno].nome[l2] = '\0';
  }
  printf("Informe o sexo ");
  fgets(e_aluno[qtdAluno].sexo, 2, stdin);
  size_t l5 = strlen(e_aluno[qtdAluno].sexo) - 1;
  if (e_aluno[qtdAluno].sexo[l5] == '\n')
  {
    e_aluno[qtdAluno].sexo[l5] = '\0';
  }
  getchar();
  printf("Informe a data de nascimento ");
  fgets(e_aluno[qtdAluno].dataNasc, 12, stdin);
  size_t l3 = strlen(e_aluno[qtdAluno].dataNasc) - 1;
  if (e_aluno[qtdAluno].dataNasc[l3] == '\n')
  {
    e_aluno[qtdAluno].dataNasc[l3] = '\0';
  }
  printf("Informe o CPF ");
  fgets(e_aluno[qtdAluno].cpf, 13, stdin);
  size_t l4 = strlen(e_aluno[qtdAluno].cpf) - 1;
  if (e_aluno[qtdAluno].cpf[l4] == '\n')
  {
    e_aluno[qtdAluno].cpf[l4] = '\0';
  }
  qtdAluno = qtdAluno + 1;
  aluno(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
}

void inc_prof(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  getchar();
  printf("\n");
  printf("Informe a matrícula ");
  fgets(e_professor[qtdProfessor].matricula, 20, stdin);
  size_t l1 = strlen(e_professor[qtdProfessor].matricula) - 1;
  if (e_professor[qtdProfessor].matricula[l1] == '\n')
  {
    e_professor[qtdProfessor].matricula[l1] = '\0';
  }
  printf("Informe o nome ");
  fgets(e_professor[qtdProfessor].nome, 50, stdin);
  size_t l2 = strlen(e_professor[qtdProfessor].nome) - 1;
  if (e_professor[qtdProfessor].nome[l2] == '\n')
  {
    e_professor[qtdProfessor].nome[l2] = '\0';
  }
  printf("Informe o sexo ");
  fgets(e_professor[qtdProfessor].sexo, 2, stdin);
  size_t l5 = strlen(e_professor[qtdProfessor].sexo) - 1;
  if (e_professor[qtdProfessor].sexo[l5] == '\n')
  {
    e_professor[qtdProfessor].sexo[l5] = '\0';
  }
  getchar();
  printf("Informe a data de nascimento ");
  fgets(e_professor[qtdProfessor].dataNasc, 12, stdin);
  size_t l3 = strlen(e_professor[qtdProfessor].dataNasc) - 1;
  if (e_professor[qtdProfessor].dataNasc[l3] == '\n')
  {
    e_professor[qtdProfessor].dataNasc[l3] = '\0';
  }
  printf("Informe o CPF ");
  fgets(e_professor[qtdProfessor].cpf, 13, stdin);
  size_t l4 = strlen(e_professor[qtdProfessor].cpf) - 1;
  if (e_professor[qtdProfessor].cpf[l4] == '\n')
  {
    e_professor[qtdProfessor].cpf[l4] = '\0';
  }
  qtdProfessor = qtdProfessor + 1;
  
  professor(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
}
void inc_disc(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  getchar();
  printf("\n");
  printf("Informe o nome ");
  fgets(e_disciplina[qtdDisciplina].nome, 50, stdin);
  size_t l2 = strlen(e_disciplina[qtdDisciplina].nome) - 1;
  if (e_disciplina[qtdDisciplina].nome[l2] == '\n')
  {
    e_disciplina[qtdDisciplina].nome[l2] = '\0';
  }
  printf("Informe o código ");
  fgets(e_disciplina[qtdDisciplina].codigo, 20, stdin);
  size_t l5 = strlen(e_disciplina[qtdDisciplina].codigo) - 1;
  if (e_disciplina[qtdDisciplina].codigo[l5] == '\n')
  {
    e_disciplina[qtdDisciplina].codigo[l5] = '\0';
  }
  printf("Informe o semestre ");
  fgets(e_disciplina[qtdDisciplina].semestre, 12, stdin);
  size_t l3 = strlen(e_disciplina[qtdDisciplina].semestre) - 1;
  if (e_disciplina[qtdDisciplina].semestre[l3] == '\n')
  {
    e_disciplina[qtdDisciplina].semestre[l3] = '\0';
  }
  printf("Informe o professor ");
  fgets(e_disciplina[qtdDisciplina].professor, 50, stdin);
  size_t l4 = strlen(e_disciplina[qtdDisciplina].professor) - 1;
  if (e_disciplina[qtdDisciplina].professor[l4] == '\n')
  {
    e_disciplina[qtdDisciplina].professor[l4] = '\0';
  }
  qtdDisciplina = qtdDisciplina + 1;
  
  disciplina(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
}

// EXCLUIR CADASTROS
void exc_alun(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  int matricula, cont = 0;
  if (qtdAluno == 0)
  {
    printf("\nNenhum aluno foi cadastrado.\n");
  }
  else
  {
    printf("\nDigite a matrícula do aluno a ser excluido: ");
    scanf("%d", &matricula);
    for (int i = 0; i < qtdAluno; i++) 
    {
      if (matricula == atoi(e_aluno[i].matricula)) 
      {
        for (int j = i; j < qtdAluno - 1; j++) 
        { 
          e_aluno[j] = e_aluno[j + 1];
        }
        qtdAluno = qtdAluno - 1;
        printf("\nAluno excluído com sucesso.\n");
        cont = cont + 1;
        break;
      }
    }
    if (cont == 0)
    {
      printf("\nMatrícula não encontrada.\n");
    }
  }
  aluno(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
}
void exc_prof(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  int matricula, cont = 0;
  if (qtdProfessor == 0)
  {
    printf("\nNenhum professor foi cadastrado.\n");
  }
  else
  {
    printf("\nDigite a matrícula do aluno a ser excluido: ");
    scanf("%d", &matricula);
    for (int i = 0; i < qtdProfessor; i++) 
    {
      if (matricula == atoi(e_professor[i].matricula)) 
      {
        for (int j = i; j < qtdProfessor - 1; j++) 
        { 
          e_professor[j] = e_professor[j + 1];
        }
        qtdProfessor = qtdProfessor - 1;
        printf("\nProfessor excluído com sucesso.\n");
        cont = cont + 1;
        break;
      }
    }
    if (cont == 0)
    {
      printf("\nMatrícula não encontrada.\n");
    }
  }
  professor(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
}
void exc_discip(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  int codigo, cont = 0;
  if (qtdDisciplina == 0)
  {
    printf("\nNenhuma disciplina foi cadastrada.\n");
  }
  else
  {
    printf("\nDigite o código da disciplina a ser excluido: ");
    scanf("%d", &codigo);
    for (int i = 0; i < qtdDisciplina; i++) 
    {
      if (codigo == atoi(e_disciplina[i].codigo)) 
      {
        for (int j = i; j < qtdDisciplina - 1; j++) 
        { 
          e_disciplina[j] = e_disciplina[j + 1];
        }
        qtdDisciplina = qtdDisciplina - 1;
        printf("\nDisciplina excluída com sucesso.\n");
        cont = cont + 1;
        break;
      }
    }
    if (cont == 0)
    {
      printf("\nCódigo não encontrado.\n");
    }
  }
  disciplina(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
}

// ATUALIZAR CADASTROS 
void atua_alun(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  int matricula, cont = 0;
  if (qtdAluno == 0)
  {
    printf("\nNenhum aluno foi cadastrado.\n");
  }
  else
  {
    printf("\nDigite a matrícula do aluno a ser atualizado: ");
    scanf("%d", &matricula);
    for (int i = 0; i < qtdAluno; i++) 
    {
      if (matricula == atoi(e_aluno[i].matricula)) 
      {
        getchar();
        printf("\n");
        printf("Informe o nome ");
        fgets(e_aluno[i].nome, 50, stdin);
        size_t l2 = strlen(e_aluno[i].nome) - 1;
        if (e_aluno[i].nome[l2] == '\n')
        {
          e_aluno[i].nome[l2] = '\0';
        }
        printf("Informe o sexo ");
        fgets(e_aluno[i].sexo, 2, stdin);
        size_t l5 = strlen(e_aluno[i].sexo) - 1;
        if (e_aluno[i].sexo[l5] == '\n')
        {
          e_aluno[i].sexo[l5] = '\0';
        }
        getchar();
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
        printf("\nAluno atualizado com sucesso.\n");
        cont = cont + 1;
        break;
      }
    }
    if (cont == 0)
    {
      printf("\nMatrícula não encontrada.\n");
    }
  }
  aluno(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
}

void atua_prof(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  int matricula, cont = 0;
  if (qtdProfessor == 0)
  {
    printf("\nNenhum professor foi cadastrado.\n");
  }
  else
  {
    printf("\nDigite a matrícula do professor a ser atualizado: ");
    scanf("%d", &matricula);
    for (int i = 0; i < qtdProfessor; i++) 
    {
      if (matricula == atoi(e_professor[i].matricula)) 
      {
        getchar();
        printf("\n");
        printf("Informe o nome ");
        fgets(e_professor[i].nome, 50, stdin);
        size_t l2 = strlen(e_professor[i].nome) - 1;
        if (e_professor[i].nome[l2] == '\n')
        {
          e_professor[i].nome[l2] = '\0';
        }
        printf("Informe o sexo ");
        fgets(e_professor[i].sexo, 2, stdin);
        size_t l5 = strlen(e_professor[i].sexo) - 1;
        if (e_professor[i].sexo[l5] == '\n')
        {
          e_professor[i].sexo[l5] = '\0';
        }
        getchar();
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
        printf("\nProfessor atualizado com sucesso.\n");
        cont = cont + 1;
        break;
      }
    }
    if (cont == 0)
    {
      printf("\nMatrícula não encontrada.\n");
    }
  }
  professor(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
}

void atua_discip(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  int codigo, cont = 0;
  if (qtdDisciplina == 0)
  {
    printf("\nNenhuma disciplina foi cadastrada.\n");
  }
  else
  {
    printf("\nDigite o código da disciplina a ser atualizado: ");
    scanf("%d", &codigo);
    for (int i = 0; i < qtdDisciplina; i++) 
    {
      if (codigo == atoi(e_disciplina[i].codigo)) 
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
        printf("\nDisciplina atualizada com sucesso.\n");
        cont = cont + 1;
        break;
      }
    }
    if (cont == 0)
    {
      printf("\nCódigo não encontrado.\n");
    }
  }
  disciplina(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
}

// ALUNOS EM DISCIPLINAS
void inse_alu_discip(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  int codigo, cont = 0;
  if (qtdDisciplina == 0)
  {
    printf("\nNenhuma disciplina foi cadastrada.\n");
  }
  else
  {
    printf("\nDigite o código da disciplina que deseja cadastrar o aluno: ");
    scanf("%d", &codigo);
    for (int i = 0; i < qtdDisciplina; i++) 
    {
      if (codigo == atoi(e_disciplina[i].codigo)) 
      {
        getchar();
        printf("\n");
        printf("Informe o nome do aluno a ser cadastrado ");
        fgets(e_disciplina[i].aluno[cont_alu_disc], 50, stdin);
        size_t l2 = strlen(e_disciplina[i].aluno[cont_alu_disc]) - 1;
        if (e_disciplina[i].aluno[cont_alu_disc][l2] == '\n')
        {
          e_disciplina[i].aluno[cont_alu_disc][l2] = '\0';
        }
        printf("\nAluno cadastrado com sucesso em disciplina.\n");
        cont_alu_disc = cont_alu_disc + 1;
        break;
      }
      else
      {
        cont = cont + 1;
      }
    }
    if (cont != 0)
    {
      printf("\nCódigo não encontrado.\n");
    }
  }
  disciplina(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
}

void exclu_alu_discip(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  int codigo, cont;
  char aluno_1[50];
  if (qtdDisciplina == 0)
  {
    printf("\nNenhuma disciplina foi cadastrada.\n");
  }
  else
  {
    printf("\nDigite o código da disciplina que deseja excluir o aluno: ");
    scanf("%d", &codigo);
    for (int i = 0; i < qtdDisciplina; i++) 
    {
      if (codigo == atoi(e_disciplina[i].codigo)) 
      {
        printf("\nInforme o nome do aluno que deseja excluir\n");
        fgets(aluno_1, 50, stdin);
        size_t l2 = strlen(aluno_1) - 1;
        if (aluno_1[l2] == '\n')
        {
          aluno_1[l2] = '\0';
        }
        
        for(int j = 0; j<cont_alu_disc; j++)
        {
          if (aluno_1 == e_disciplina[i].aluno[j])
          {
            for (int k = j; k < cont_alu_disc - 1; k++) 
            { 
              strcpy(e_disciplina[i].aluno[k], e_disciplina[i].aluno[k + 1]);
            }
          }
        }
        printf("\nAluno excluído de disciplina com sucesso.\n");
        break;
      }
      else
      {
        cont = cont + 1;
      }
    }
    if (cont != 0)
    {
      printf("\nCódigo não encontrado.\n");
    }
  }
  disciplina(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
}

// CHAMAR AS LISTAS
void relatorios(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  int opcao_relat;
  printf("\nInforme o relatório que deseja gerar:\n");
  printf("1 - Listar alunos\n2 - Listar professores\n3 - Listar disciplinas(dados das disciplinas sem os alunos)\n4 - Listar uma disciplina(dados da disciplina e os alunos matriculados\n5 - Listar alunos por sexo(F/M)\n6 - Listar alunos ordenados por nome\n7 - Listar alunos ordenados por data de nascimento\n8 - Listar professores por sexo(F/M)\n9 - Listar professores ordenados por nome\n10 - Listar professores ordenados por data de nascimento\n11 - Voltar\n");
  scanf("%d", &opcao_relat);
  if (opcao_relat == 1)
  {
    lista_aluno(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);   
  }
  else if(opcao_relat == 2)
  {
    lista_prof(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if (opcao_relat == 3)
  {
    lista_disciplina(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if(opcao_relat == 4)
  {
    lista_uma_disci(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if (opcao_relat == 5)
  {
    lista_aluno_sex(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if (opcao_relat == 6)
  {
    lista_aluno_nome(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if(opcao_relat == 7)
  {
    lista_aluno_nasci(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if (opcao_relat == 8)
  {
    lista_prof_sex(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if(opcao_relat == 9)
  {
    lista_prof_nome(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if (opcao_relat == 10)
  {
    lista_prof_nasc(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if (opcao_relat == 11)
  {
    alu_prof_disci(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else
  {
    printf("Opção inválida.\n");
    relatorios(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
}

// GERAÇÃO DAS LISTAS
void lista_prof_nasc(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  relatorios(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
}
void lista_prof_nome(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  relatorios(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
}
void lista_prof_sex(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  relatorios(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
}
void lista_aluno_nasci(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  relatorios(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
}
void lista_aluno_nome(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  relatorios(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
}
void lista_aluno_sex(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  printf("\nLista de alunos por sexo:\n");
  printf("\nSexo Feminino:\n");
  for(int i=0; i<qtdAluno; i++)
  {
    if(e_aluno[i].sexo == "F")
    {
      printf("%s\n", e_aluno[i].nome);
    }
  }
  printf("\nSexo Masculino:\n");
  for(int i=0; i<qtdAluno; i++)
  {
    if(e_aluno[i].sexo == "M")
    {
      printf("%s\n", e_aluno[i].nome);
    }
  }
  relatorios(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
}
void lista_uma_disci(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  relatorios(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
}
void lista_disciplina(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  printf("\nLista de disciplinas:\n");
  for(int i=0; i<qtdDisciplina; i++)
  {
    printf("%s\n", e_disciplina[i].nome);
  }
  relatorios(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
}
void lista_prof(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  printf("\nLista de Professores:\n");
  for(int i=0; i<qtdProfessor; i++)
  {
    printf("%s\n", e_professor[i].nome);
  }
  relatorios(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
}
void lista_aluno(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  printf("\nLista de alunos:%d\n", qtdAluno);
  for(int i=0; i<qtdAluno; i++)
  {
    printf("%s\n", e_aluno[i].nome);
  }
  relatorios(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
}

// FUNÇÃO QUE DA O MENU
void alu_prof_disci(estru_aluno e_aluno[], int qtdAluno, estru_professor e_professor[], int qtdProfessor, estru_disciplina e_disciplina[], int qtdDisciplina, int cont_alu_disc)
{
  int opcao;
  printf("\nDigite a opção que deseja realizar:\n");
  printf("1 - Adicionar/Modificar/Excluir - Aluno\n2 - Adicionar/Modificar/Excluir - Professor\n3 - Adicionar/Modificar/Excluir - Disciplina\n4 - Gerar Relatórios\n5 - Sair\n");
  scanf("%d", &opcao);
  
  if (opcao == 1)
  {
    aluno(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if(opcao == 2)
  {
    professor(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if (opcao == 3)
  {
    disciplina(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if(opcao == 4)
  {
    relatorios(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
  else if (opcao == 5)
  {
    return;
  }
  else
  {
    printf("Opção inválida.\n");
    alu_prof_disci(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  }
}

// FUNÇÃO MAIN
int main()
{
  estru_aluno e_aluno[1];
  int qtdAluno = 0;
  estru_professor e_professor[1];
  int qtdProfessor= 0;
  estru_disciplina e_disciplina[1];
  int qtdDisciplina = 0;
  int cont_alu_disc = 0;
  alu_prof_disci(e_aluno, qtdAluno, e_professor, qtdProfessor, e_disciplina, qtdDisciplina, cont_alu_disc);
  return 0;
}

