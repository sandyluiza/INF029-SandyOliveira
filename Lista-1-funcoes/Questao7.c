// 7) Crie um programa que tenha uma função ler3Palavras. Essa função deve ler três palavras do usuário e retornar as três palavras. A função main deve imprimir essas três palavras.
#include <stdio.h>
#include <string.h>

void funcao_ler(char vetor_1[3][100])
{
  int i;
  for (i=0;i<3;i++)
  {
    printf("Informe a palavra ");
    fgets(vetor_1[i], 100, stdin);
    
    size_t ln = strlen(vetor_1[i]) - 1;
    
    if (vetor_1[i][ln] == '\n')
    {
      vetor_1[i][ln] = '\0';
    }
  }
  return;
}

int main()
{
  char vetor[3][100], i;
  
  funcao_ler(vetor);
  
  for (i=0; i<3; i++)
  {
    printf("Palavra %s\n", vetor[i]);
  }
}