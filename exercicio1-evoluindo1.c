// Evolução do exercicio1
#include <stdio.h>

int main()
{
  struct Informacoes_pessoas
  {  
    char nome[100];
    // Toda string é finalizada no compilador com um /0, por isso gasta 1 espaço a           mais do compilador
    int idade;
  };
  struct Informacoes_pessoas IP;

  
  int n, i;
  printf("informe o numero de idades que deseja determinar a media ");
  scanf("%d", &n);
  Informacoes_pessoas IP[n];

  for (i=0; i<n; i++)
  {
    printf("\nInforme o Nome[%d]: ",i);
    fgets(IP[i].nome, 100, stdin);  
    // a função fgets insere um \n no fim, por isso  
    getchar();
    printf("\nInforme a Idade[%d]: ",i);
    scanf("%d", &IP[i].idade);
    getchar();
  }


  
}