// 9) Evolua o programa que tem a função cadastrarCliente, para fazer as validações dos dados. Cada validação deve ser feita em uma função diferente, conforme lista abaixo. A função cadastrarCliente deve chamar cada uma dessas funções. A função main deve imprimir se o cadastro foi realizado com sucesso ou se houve erro, informando onde foi o erro:
// • função validarNome: recebe o nome digitado, e valida se nome tem até 20 caracteres;
// • função validarSexo: recebe o sexo digitado, e valida é um sexo válido (opções: m e M para
// masculino; f e F para feminino, o e O para outro).
// • função validarCPF: recebe o cpf digitado, e valida é um cpf válido;
// • função validarNacimento: recebe o data digitada, e valida é uma data válida.
#include <stdio.h>
#include <string.h>

void validarNome()
{
  char nome[50];
  size_t ln=21;

  while (ln>20)
  {
    printf("\ninforme o nome ");
    fgets(nome, 50, stdin);
    ln = strlen(nome) - 1;
    if (nome[ln] == '\n')
    {
      nome[ln] = '\0';
    }
    if (ln>20)
    {
      printf("O nome possui mais que 20 caracteres.");
    }
  }
  printf("Nome tem até 20 caracteres.");
}

void validarSexo()
{
  char sexo = "J", F, f, M, m, O, o;
  
  while (sexo != F & sexo != f & sexo != M & sexo != m & sexo != o & sexo != O)
  {
    printf("\ninforme o sexo(F/M/O) ");
    scanf("%c", &sexo);
    printf("\nOpção não é uma válida.");
  }
  printf("É uma opção válida.");
}

void cadastrarCliente()
{
  validarNome();
  validarSexo();
}

int main(void)
{
  cadastrarCliente();
}




// typedef struct
// {
//   char nome[50];
//   char dataNasc[12];
//   char cpf[13];
//   char sexo;
// }
// InformacoesCli;

// void CadCliente(InformacoesCli InfCli[1], int numcli)
// {
//   int i;
  
//   
    
//     printf("informe a data de nascimento ");
//     fgets(InfCli[i].dataNasc, 12, stdin);
//     size_t lo = strlen(InfCli[i].dataNasc) - 1;
//     if (InfCli[i].dataNasc[lo] == '\n')
//     {
//       InfCli[i].dataNasc[lo] = '\0';
//     }
    
//     printf("informe o CPF ");
//     fgets(InfCli[i].cpf, 13, stdin);
//     size_t lp = strlen(InfCli[i].cpf) - 1;
//     if (InfCli[i].cpf[lp] == '\n')
//     {
//       InfCli[i].cpf[lp] = '\0';
//     }
    
//     printf("informe o sexo(F/M) ");
//     scanf("%c", &InfCli[i].sexo);
//   }
//   return;
// }

// int main()
// {
//   InformacoesCli InformCli[1];
//   int i, ncli=1;
  
//   CadCliente(InformCli, ncli); 
  
//   printf("Nome %s\nData de nascimento %s\nCPF %s\nSexo %c\n", InformCli[i].nome,  InformCli[i].dataNasc, InformCli[i].cpf, InformCli[i].sexo);
// }