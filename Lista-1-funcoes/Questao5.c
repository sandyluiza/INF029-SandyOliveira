// 5) Crie um programa que tenha uma função ler4Numeros. Essa função deve ler quatro números do usuário e retornar os quatro números. A função main deve imprimir esses quatro números. Utilize struct para fazer o retorno.
#include <stdio.h>

typedef struct
{
  int Primeiro_n;
  int Segundo_n;
  int Terceiro_n;
  int Quarto_n;
}
  Estrutura;

void ler_num(Estrutura estrut[1])
{  
  int i;
  
  for (i=0;i<1;i++)
  {
    printf("Informe o número ");
    scanf("%d", &estrut[i].Primeiro_n);
    printf("Informe o número ");
    scanf("%d", &estrut[i].Segundo_n);
    printf("Informe o número ");
    scanf("%d", &estrut[i].Terceiro_n);
    printf("Informe o número ");
    scanf("%d", &estrut[i].Quarto_n);
  }
  return;
}

int main()
{
  Estrutura estru[1];
  int i;
  
  ler_num(estru);
  
  for (i=0;i<1;i++)
  {
    printf("Número %d\nNúmero %d\nNúmero %d\nNúmero %d\n", estru[i].Primeiro_n, estru[i].Segundo_n, estru[i].Terceiro_n, estru[i].Quarto_n);
  }
}