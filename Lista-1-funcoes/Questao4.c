// 4) Crie um programa que tenha uma função ler3Numeros. Essa função deve ler três números do usuário e retornar os três números. A função main deve imprimir esses três números. Utilize vetor para fazer o retorno.
#include <stdio.h>

void funcao_ler(int vetor_1[3])
{
  int i;
  for (i=0;i<3;i++)
  {
    printf("Informe o número ");
    scanf("%d", &vetor_1[i]);
  }
  return;
}

int main()
{
  int vetor[3] = {}, i;
  
  funcao_ler(vetor);
  
  for (i=0;i<3;i++)
  {
    printf("Número %d\n", vetor[i]);
  }
}