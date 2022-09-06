// Calculo do fatorial de um número
#include <stdio.h>
int main()
{
  int numero, fatorial, i;
  printf("Informe o número ");
  scanf("%d", &numero);
  fatorial = 1;
  for (i=1; i<=numero; i++)
  {
    fatorial = fatorial * i;  
  }
  printf("O fatorial do numero %d é %d.", numero, fatorial);
}

// Perguntar ao professor sobre o fatorial de numeros a partir de 35 que dá 0, como corrigir