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
// int somar(int a, int b);
// int main(void) // o void é quando uma função não tem que retornar nada.
// {
//   int x, y, soma;
//   printf("Informe o primeiro valor ");
//   scanf("%d", &x);
//   printf("Informe o segundo valor ");
//   scanf("%d", &y);

//   soma = somar(x, y);
  
//   printf("O valor da soma e %d", soma);
  
// }

// int somar(int a, int b)
// {
//   int resultado;
//   resultado = a + b;
//   return resultado;
// }

// Uma variável global pega o último valor. Se tiver uma função mexendo embaixo na variavel global o valor é alterado. Por isso é melhor não usar uma variável global, pois se tiver algo vinculado com mesmo nome, pode interferir no código.

// AULA 14/09 PROJETO ESCOLA
#include <stdio.h>
#include "Anotacoes_aula.h"

int imprimemenu();

int imprimemenu()
{
  int opcao;
  printf("Digite a opção\n");
  printf("0 - Sair\n");
  printf("1 - Aluno\n");
  printf("2 - Professor\n");
  printf("3 - Disciplina\n");
  scanf("%d", &opcao);
  return opcao;
}

int main(void)
{
  int opcao = 1;
  
  while(opcao != 0)
  {
    opcao = imprimemenu();
    switch (opcao)
    {
      case 1:
      {
        printf("Opção de Aluno \n");
        mainaluno();
        aluno aluno;
        break;
      }
      case 2:
      {
        printf("Opção de professor \n");
        break;
      }
      case 3:
      {
        printf("Opção de Disciplina \n");
        break;
      }
      default:
      {
        printf("Opção inválida.\n");
      }
    }

  }
  return 0;
}

// Cadastrar o voltar, aí coloca case e opção = o menu anterior

// listar aluno
// printf(Lista de aluno
// for....
// printf("Matricula: %d - Idade: %d\n", lista[i].matricula, lista[i].idade));
// tem que ter a opção de voltar e depois entrar de novo e ficar gravado
// se é int tem que ter return
// se é void não tem return