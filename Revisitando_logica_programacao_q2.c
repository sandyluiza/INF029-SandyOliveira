#include <stdio.h>
int main()
{
  int idade1, idade2, soma_id;
  printf("Informe a primeira idade ");
  scanf("%d", &idade1);
  printf("Informe a segunda idade ");
  scanf("%d", &idade2);
  soma_id = idade1 + idade2;
  printf("A soma das idades e %d", soma_id);
}