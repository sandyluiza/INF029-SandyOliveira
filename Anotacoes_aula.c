// FAZER UMA FUNÇÃO

// #include <stdio.h>
// void pontinhos();
// // Deve-se colocar as funções feitas embaixo abaixo do include para que, se for chamado dentro do main, acima de onde a estrutura está escrita, não dê erro.

// // Estrutura da função
// void pontinhos()
// {
//   int i;
//   for (i=1; i<20; i++)
//     {
//       printf("*");
//     }
//   printf("\n");
// }

// // Chamando a função no int main
// int main()
// {
//   pontinhos();
//   pontinhos();
//   pontinhos();
// }

// OUTRA FORMA DE FAZER FUNÇÃO
int somar(int a, int b);
int main(void) // o void é quando uma função não tem que retornar nada.
{
  int x, y, soma;
  printf("Informe o primeiro valor ");
  scanf("%d", &x);
  printf("Informe o segundo valor ");
  scanf("%d", &y);

  soma = somar(x, y);
  
  printf("O valor da soma e %d", soma);
  
}

int somar(int a, int b)
{
  int resultado;
  resultado = a + b;
  return resultado;
}

// Uma variável global pega o último valor. Se tiver uma função mexendo embaixo na variavel global o valor é alterado. Por isso é melhor não usar uma variável global, pois se tiver algo vinculado com mesmo nome, pode interferir no código.