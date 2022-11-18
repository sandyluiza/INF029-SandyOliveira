// Ponteiros

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *vet, tam;
  printf("Informe o tamanho ");
  scanf("%d", &tam);

  vet = (int *) malloc (tam * sizeof (int));

  printf("\n");
  for (int i = 0; i<tam; i++)
  {
    printf("Informe o elemento do vetor ");
    scanf("%d", &vet[i]);
  }

  printf("\nElementos do vetor ");
  for (int i = 0; i<tam; i++)
  {
    printf("%d", vet[i]);
  }

  free(vet);

  return 0;
}