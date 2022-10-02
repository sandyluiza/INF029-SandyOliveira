// 9) Evolua o programa que tem a função cadastrarCliente, para fazer as validações dos dados. Cada validação deve ser feita em uma função diferente, conforme lista abaixo. A função cadastrarCliente deve chamar cada uma dessas funções. A função main deve imprimir se o cadastro foi realizado com sucesso ou se houve erro, informando onde foi o erro:
// • função validarNome: recebe o nome digitado, e valida se nome tem até 20 caracteres;
// • função validarSexo: recebe o sexo digitado, e valida é um sexo válido (opções: m e M para
// masculino; f e F para feminino, o e O para outro).
// • função validarCPF: recebe o cpf digitado, e valida é um cpf válido;
// • função validarNacimento: recebe o data digitada, e valida é uma data válida.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  char nome[50];
  char dataNasc[12];
  char cpf[13];
  char sexo;
}
InformacoesCli;

int valida_sexo(char c);
int valida_nome();
int valida_dataNasc();
int valida_cpf();

int CadCliente(InformacoesCli InfCli[1], int numcli)
{
  int i;
  int cont = 0;
  
  for (i=0; i<numcli; i++)
  {
    printf("informe o nome ");
    fgets(InfCli[i].nome, 50, stdin);
    size_t ln = strlen(InfCli[i].nome) - 1;
    if (InfCli[i].nome[ln] == '\n')
    {
      InfCli[i].nome[ln] = '\0';
    }
    valida_nome(InfCli[i].nome);
    cont = valida_nome(InfCli[i].nome, cont) + cont;
    
    printf("informe a data de nascimento ");
    fgets(InfCli[i].dataNasc, 12, stdin);
    size_t lo = strlen(InfCli[i].dataNasc) - 1;
    if (InfCli[i].dataNasc[lo] == '\n')
    {
      InfCli[i].dataNasc[lo] = '\0';
    }
    valida_dataNasc(InfCli[i].dataNasc);
    cont = cont + valida_dataNasc(InfCli[i].dataNasc);
    
    printf("informe o CPF ");
    fgets(InfCli[i].cpf, 13, stdin);
    size_t lp = strlen(InfCli[i].cpf) - 1;
    if (InfCli[i].cpf[lp] == '\n')
    {
      InfCli[i].cpf[lp] = '\0';
    }
    valida_cpf(InfCli[i].cpf);
    cont = cont + valida_cpf(InfCli[i].cpf);
    
    printf("informe o sexo(F/M/O) ");
    scanf("%c", &InfCli[i].sexo);
    valida_sexo(InfCli[i].sexo);
    cont = cont + valida_sexo(InfCli[i].sexo);
    
    return cont;
  }
}

int valida_sexo(char c)
{
  int cont;
  if (c != 'O' && c != 'F' && c != 'M' && c != 'o' && c != 'f' && c != 'm')
  {
    printf("Sexo inválido.");
    cont = 0;
  }
  else
  {
    cont = 1;
  }
  return cont;
}
int valida_nome(char nome[20])
{
  int cont;
  int cont_nome = strlen(nome);
  if (cont_nome>20)
  {
    printf("Nome possui mais que 20 caracteres.\n");
    cont = 0;
  }
  else
  {
    cont = 1;
  }
  return cont;
}

int valida_dataNasc(char dataNasc[12])
{
  char sdia[3], smes[3], sano[12];
  int i, j, k, dia, mes, ano, cont;
  for(i=0; dataNasc[i] != '/' && i<2; i++)
  {
    sdia[i] = dataNasc[i];   
  }
  sdia[i] = '\0';
  dia = atoi(sdia); 
  // printf("%d", dia);

  for(j=0; dataNasc[j] != '/' && j<2; j++)
  {
    smes[j] = dataNasc[j+3]; 
  }
  smes[j] = '\0';
  mes = atoi(smes);

  for(k=0; k<8; k++)
  {
    sano[k] = dataNasc[k+6];
  }
  sano[k] = '\0';
  ano = atoi(sano);

  if(dia > 31 || mes > 12)
  {
    printf("Data inválida.\n");
    cont = 0;
  }
  else
  {
    cont = 1;
  }
  return cont;  
}

int valida_cpf(char c[13])
{
  int cont_cpf = strlen(c);
  int cont;
  if (cont_cpf != 11)
  {
    printf("CPF não é válido.\n");
    cont = 0;
  }
  else
  {
    cont = 1;
  }
  return cont;
}

int main()
{
  InformacoesCli InformCli[1];
  int ncli=1, cont = 0, i;
  
  cont = CadCliente(InformCli, ncli);
  // printf("%d", cont);
  if (cont == 4)
  {
    printf("\nCadastro foi realizado com sucesso");
  }
  else
  {
    printf("\nHouve erro durante o cadastro");
  }
  for (i=0; i<ncli; i++)
  {
    printf("\n%s\n%s\n%s\n%c\n", InformCli[i].nome, InformCli[i].dataNasc, InformCli[i].cpf, InformCli[i].sexo);
  }
}

