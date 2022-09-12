// Evolução do exercicio1
// Evoluir o programa anterior para ler também o nome das pessoas e imprimir o nome e a idade de todos que forem maior que a média.

// Toda string é finalizada no compilador com um /0, por isso gasta 1 espaço a           mais do compilador
// O fgets termina com um \n por isso que dá um enter no final, precisa corrigir o final da string de \n para \o para que não fique dando enter

#include <stdio.h>
#include <string.h>

typedef struct
{
  char nome[50];
  int idade;
}
Informacoespessoas;

int main()
{
  int n, i, soma_idades;
  float media;
  printf("informe o numero de pessoas que deseja determinar a media das idades ");
  scanf("%d", &n);
  soma_idades = 0;
  
  Informacoespessoas pessoas[n]; 
  
  for (i=0; i<n; i++)
  {
    // retirando o \n do final do fgets
    getchar();
    printf("informe o nome ");
    fgets(pessoas[i].nome, 50, stdin);
    size_t ln = strlen(pessoas[i].nome) - 1;
    if (pessoas[i].nome[ln] == '\n')
    {
      pessoas[i].nome[ln] = '\0';
    }
    
    printf("informe a idade ");
    scanf("%d", &pessoas[i].idade);
    soma_idades = pessoas[i].idade + soma_idades;
  }
  
  media = soma_idades/n;
  printf("a media e %f \n", media); 
  
  for (i=0; i<n; i++)
  {
    if (pessoas[i].idade > media)
    {
      printf("%s com idade %d tem a idade maior que a media \n", pessoas[i].nome, pessoas[i].idade);
    }
  }    
}