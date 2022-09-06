// Invertendo os valores das variaveis sem auxiliar
#include <stdio.h>
int main()
{
  int valor1, valor2;
  printf("Informe o valor1 ");
  scanf("%d", &valor1);
  printf("Informe o valor2 ");
  scanf("%d", &valor2);
  valor1 = valor1 + valor2;
  valor2 = valor1 - valor2;
  valor1 = valor1 - valor2;
  printf("O valor1 e %d e o valor2 e %d.", valor1, valor2);
}