// 3) Faça um programa que tenha uma função que recebe um número inteiro e retorna o fatorial deste número. Esta função deve ainda verificar se é possível calcular o fatorial, se não for, ela deve de alguma forma retornar para a main que deu algum erro. A função main deve solicitar o valor do usuário e imprimir o fatorial dele, ou se não é possível calcular o fatorial.
#include <stdio.h>

int funcao(int n);

int main(void)
{
  int num; 
  double fat;
  printf("Informe o número ");
  scanf("%d", &num);
  
  fat = funcao(num);
  
  if (fat == 0)
  {
    printf("Não é possível calcular o fatorial.");
  }
  else
  {
    printf("O fatorial do numero %d é %lf", num, fat);
  }
}

int funcao(int n)
{
  int i;
  double fatorial=1;

  if (n < 0)
  {
    fatorial = 0;
  }
  
  if (n == 0)
  {
    fatorial = 1;
  }
    
  else
  {
    for (i=1; i<n+1; i++)
    {
      fatorial = fatorial*i; 
    }
  }
  return fatorial;
}