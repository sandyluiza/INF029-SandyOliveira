#include <stdio.h>

int fat(int num)
{
  result = 1
  if (num > 1)
  {
    result = result * num;
    num--;
    fat(num);
  }
  retorno result;
}



int main()
{
  int num;
  printf("Informe o número que deseja calcular o fatorial ");
  scanf("%d", &num);
  
  fat (num);

}