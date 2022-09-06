// Informando se e de maior ou menor ate idade negativa
#include <stdio.h>
int main()
{
  int idade;
  printf("Informe a sua idade ");
  scanf("%d", &idade);
  while (idade >= 0)
  {
    if (idade < 18)
    {
    printf("Você é menor de idade.\n");
    }
    else
    {
      printf("Você é maior de idade.\n");
    } 
    printf("Informe a sua idade ");
    scanf("%d", &idade);
  }
  printf("Idade informada está negativa.");
}