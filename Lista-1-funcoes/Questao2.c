// 2) Crie um programa que tenha uma função subtrai e a função main. A função main deve ler três valores, enviar para a função subtrai. A função subtrai deve realizar a subtração dos três valores (primeiro menos o segundo menos o terceiro) e retornar o valor. A Função main deve imprimir o resultado da subtração.
#include <stdio.h>

int subtrai(v1, v2, v3)
{
  int subtra;
  subtra = v1-v2-v3;
  return subtra;
}

int main()
{
  int val_1, val_2, val_3, result;
  printf("Informe o primeiro valor: ");
  scanf("%d", &val_1);
  printf("Informe o segundo valor: ");
  scanf("%d", &val_2);
  printf("Informe o terceiro valor: ");
  scanf("%d", &val_3);

  result = subtrai(val_1, val_2, val_3);
  printf("O resultado da subtração de %d, %d e %d é %d", val_1, val_2, val_3, result);
}