// Ler a idade e informar se é de maior ou menor
#include <stdio.h>
int main()
{
  int idade;
  printf("Informe a sua idade ");
  scanf("%d", &idade);
  if (idade < 18)
  {
  printf("Você é menor de idade");
  }
  else
  {
    printf("Você é maior de idade");
  }
}