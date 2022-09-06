// Determinar se um número é primo
#include <stdio.h>
int main()
{
  int numero, resto, div, i; 
  printf("Informe o número ");
  scanf("%d", &numero);
  div = 0;
  for (i=1; i<=numero; i++)
  {
    resto = numero%i;
    if (resto == 0)
    {
      div = div + 1;
    }
  }
  if (div == 2)
  {
    printf("O numero %d é primo.", numero);
  }
  else
  {
    printf("O numero %d não é primo.", numero);
  }
}