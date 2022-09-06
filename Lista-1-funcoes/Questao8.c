// 8) Crie um programa que tenha uma função cadastrarCliente. Essa função deve ler os dados do cliente (nome, dataNascimento, cpf, sexo) e retornar os dados do cliente. A função main deve imprimir os dados do cliente
#include <stdio.h>
#include <string.h>

typedef struct
{
  char nome[50];
  char dataNasc[12];
  char cpf[13];
  char sexo;
}
InformacoesCli;

void CadCliente(InformacoesCli InfCli[1], int numcli)
{
  int i;
  
  for (i=0; i<numcli; i++)
  {
    printf("informe o nome ");
    fgets(InfCli[i].nome, 50, stdin);
    size_t ln = strlen(InfCli[i].nome) - 1;
    if (InfCli[i].nome[ln] == '\n')
    {
      InfCli[i].nome[ln] = '\0';
    }
    
    printf("informe a data de nascimento ");
    fgets(InfCli[i].dataNasc, 12, stdin);
    size_t lo = strlen(InfCli[i].dataNasc) - 1;
    if (InfCli[i].dataNasc[lo] == '\n')
    {
      InfCli[i].dataNasc[lo] = '\0';
    }
    
    printf("informe o CPF ");
    fgets(InfCli[i].cpf, 13, stdin);
    size_t lp = strlen(InfCli[i].cpf) - 1;
    if (InfCli[i].cpf[lp] == '\n')
    {
      InfCli[i].cpf[lp] = '\0';
    }
    
    printf("informe o sexo(F/M) ");
    scanf("%c", &InfCli[i].sexo);
  }
  return;
}

int main()
{
  InformacoesCli InformCli[1];
  int i, ncli=1;
  
  CadCliente(InformCli, ncli); 
  
  printf("Nome %s\nData de nascimento %s\nCPF %s\nSexo %c\n", InformCli[i].nome,  InformCli[i].dataNasc, InformCli[i].cpf, InformCli[i].sexo);
}