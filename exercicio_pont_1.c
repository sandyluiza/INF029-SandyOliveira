// Ponteiros
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//   int *vet, tam;
//   printf("Informe o tamanho ");
//   scanf("%d", &tam);

//   vet = (int *) malloc (tam * sizeof (int));

//   printf("\n");
//   for (int i = 0; i<tam; i++)
//   {
//     printf("Informe o elemento do vetor ");
//     scanf("%d", &vet[i]);
//   }

//   printf("\nElementos do vetor ");
//   for (int i = 0; i<tam; i++)
//   {
//     printf("%d", vet[i]);
//   }

//   free(vet);

//   return 0;
// }

// #include <stdio.h>

// int main()
// {
//   int *vetor_ponteiro[5];
//   int x;
//   x = 10;

//   printf("%d\n", x);

//   printf("%p\n", &x);

//   vetor_ponteiro[0] = &x;

//   printf("%p\n", vetor_ponteiro[0]);

  

//   return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main()
// {
//   int *valor1, valor2 = 50;
//   char *letra1, letra2[2] = "ga", letra3[2] = "mi", *letra4;

//   valor1 = &valor2;
//   // printf("%p\n", valor1);
//   // printf("%d\n", *valor1);
//   // printf("%p\n", &valor2);

//   letra1 = &letra2[0];
//   // printf("%p\n", letra1);
//   // printf("valor do ponteiro %c\n", *letra1);
//   // printf("%p\n", &letra2);

//   // int tamanho_string = strlen(letra1);
//   // printf("%d\n", tamanho_string);

//   letra4 = &letra3[0];
//   letra2[2] = *letra4;

//   printf("letra2 posicao 2 %c\n", letra2[2]);
  
  
//   return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main()
// {
//   int *vetor_ponteiros[3];
//   // casa1[3] = "pi", casa2[3] = "hu";
//   int casa3[2] = {1, 2};
  
//   // vetor_ponteiros[0] = &casa1[0];
//   // vetor_ponteiros[1] = &casa2[0];
//   vetor_ponteiros[2] = &casa3[0];

//   // printf("%c\n", *vetor_ponteiros[0]);
//   // printf("%c\n", *(vetor_ponteiros[0]+1));
//   // printf("%c\n", *vetor_ponteiros[1]);
//   // printf("%c\n", *(vetor_ponteiros[1]+1));

//   for (int i=0; i<2; i++)
//   {
//     printf("%d\n", *(vetor_ponteiros[2] + i));
//   }

//   // int tam = sizeof(vetor_ponteiros[0]);
//   // printf("\n%d\n", tam);
  
//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#define tam 4

int main()
{
  // int v[tam];
  // // completar um vetor com ponteiro
  // for (int i=0; i<tam; i++)
  // {
  //   printf("Informe o número ");
  //   scanf("%d", v+i);
  // }

  // printf("Segundo num %d\n", *(v+1));

  int v[tam];
  
}
