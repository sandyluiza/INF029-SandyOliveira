/*ler n idades, calcular a media e informar as idades acima da media*/
#include <stdio.h>
int main()
{
  int n, idade, i;
  float media;
  printf("informe o numero de idades que deseja determinar a media ");
  scanf("%d", &n);
  int idades[n];
  idade = 0;
  
  for (i=0; i<n; i++)
  {
    printf("informe a idade ");
    scanf("%d", &idades[i]);
    idade = idades[i] + idade;
  }
  
  media = idade/n;
  printf("a media e %f \n", media); 
  
  for (i=0; i<n; i++)
  {
    if (idades[i] > media)
    {
      printf("o numero %d e maior que a media \n", idades[i]);
    }
  }  
}