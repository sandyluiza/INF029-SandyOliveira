// Ler 10 num e informar qual é primo e somar os primos
#include <stdio.h>
int main()
{
  // Declarando variaveis
  int numeros[10], i, j, div, resto, numero, soma_numeros_primos;

  // Guardando as variaveis de entrada
  for (i=0; i<10; i++)
  {
    printf("Informe o número ");
    scanf("%d", &numeros[i]);
  }

  // Determinando se os numeros são primos e somando
  soma_numeros_primos = 0;
  for (i=0; i<10; i++)
  {
    // printf("%d", numeros[i]);
    div = 0;
    numero = numeros[i];
    for (j=1; j<=numero; j++)
    {
      resto = numero%j;
      if (resto == 0)
      {
        div = div + 1;
      }
    }
    if (div == 2)
    {
      printf("O numero %d é primo.\n", numero);
      soma_numeros_primos = soma_numeros_primos + numero;
    }
    else
    {
      printf("O numero %d não é primo.\n", numero);
    }
  }
  printf("A soma dos números primos é %d.", soma_numeros_primos);
}