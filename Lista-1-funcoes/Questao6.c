// 6) Crie um programa que tenha uma função ler3Letras. Essa função deve ler três letras do usuário e retornar as três letras. A função main deve imprimir essas três letras.
#include <stdio.h>

void funcao_ler(char vetor_1[1][3])
{
  int i;
  for (i=0;i<3;i++)
  {
    printf("Informe a letra ");
    scanf("%s", &vetor_1[i]);
    
    if (vetor_1[2][i] == '\n')
    {
      vetor_1[2][i] = '\0';
    }
    getchar();
  }
  return;
}

int main()
{
  char vetor[1][3] = {}, i;
  
  funcao_ler(vetor);
  
  for (i=0;i<3;i++)
  {
    printf("Letra %s\n", vetor[i]);
  }
}