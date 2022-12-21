#include <stdio.h>
#include <string.h>

int main()
{
  int jogada = 0;
  char posicao[3], caractere, linhaA[13], linhaB[13], linhaC[13], linha[13], jogadas_realizadas[10][10];

  printf("\n   1  2  3 \n");
  strcpy(linhaA, "A   |  |  ");
  printf("%s\n", linhaA);
  strcpy(linha,"  --|--|--");
  printf("%s\n", linha);
  strcpy(linhaB, "B   |  |  ");
  printf("%s\n", linhaB);
  printf("%s\n", linha);
  strcpy(linhaC, "C   |  |  ");
  printf("%s\n", linhaC);

  while(jogada < 9)
  {
    if (jogada%2 == 0)
    {
      printf("\n\nJogador 1, informe sua jogada: ");
      caractere = 'X';
    }
    else if (jogada%2 != 0)
    {
      printf("\n\nJogador 2, informe sua jogada: ");
      caractere = 'O';
    }
    
    fgets(posicao, 3, stdin);
    size_t l1 = strlen(posicao) - 1;
    if (posicao[l1] == '\n')
    {
      posicao[l1] = '\0';
    }

    // TERMINAR QUANDO JÁ INSERIU A POSICAO UMA VEZ E O GANHARDOR
    // for (int m = 0; m < 9; m++)
    // {
    //   if (posicao == jogadas_realizadas[m])
    //   {
    //     printf("\nPosição já informada anteriormente.\n");
    //     jogada--;
    //     break;
    //   }
    // }
    
    // strcpy(jogadas_realizadas[jogada], posicao);
    
    if(posicao[0] == 'A')
    {
      if (posicao[1] == '1')
      {
        printf("\n");
        printf("   1  2  3 \n");
        linhaA[3] = caractere;
        printf("%s\n", linhaA);
        printf("%s\n", linha);
        printf("%s\n", linhaB);
        printf("%s\n", linha);
        printf("%s\n", linhaC);             
        printf("\n");
      }
      else if (posicao[1] == '2')
      {
        printf("\n");
        printf("   1  2  3 \n");
        linhaA[6] = caractere;
        printf("%s\n", linhaA);
        printf("%s\n", linha);
        printf("%s\n", linhaB);
        printf("%s\n", linha);
        printf("%s\n", linhaC);
        printf("\n");
      }
      else if (posicao[1] == '3')
      {
        printf("\n");
        printf("   1  2  3 \n");
        linhaA[9] = caractere;
        printf("%s\n", linhaA);
        printf("%s\n", linha);
        printf("%s\n", linhaB);
        printf("%s\n", linha);
        printf("%s\n", linhaC);
        printf("\n");
      }
      else
      {
        printf("\nPosição Inválida.\nDigite novamente.\n");
        jogada--;
      }
    }
    
    else if(posicao[0] == 'B')
    {
      if (posicao[1] == '1')
      {
        printf("\n");
        printf("   1  2  3 \n");
        linhaB[3] = caractere;
        printf("%s\n", linhaA);
        printf("%s\n", linha);
        printf("%s\n", linhaB);
        printf("%s\n", linha);
        printf("%s\n", linhaC);
        printf("\n");
      }
      else if (posicao[1] == '2')
      {
        printf("\n");
        printf("   1  2  3 \n");
        linhaB[6] = caractere;
        printf("%s\n", linhaA);
        printf("%s\n", linha);
        printf("%s\n", linhaB);
        printf("%s\n", linha);
        printf("%s\n", linhaC);
        printf("\n");
      }
      else if (posicao[1] == '3')
      {
        printf("\n");
        printf("   1  2  3 \n");
        linhaB[9] = caractere;
        printf("%s\n", linhaA);
        printf("%s\n", linha);
        printf("%s\n", linhaB);
        printf("%s\n", linha);
        printf("%s\n", linhaC);
        printf("\n");
      }
      else
      {
        printf("\nPosição Inválida.\nDigite novamente.\n");
        jogada--;
      }
    }

    else if(posicao[0] == 'C')
    {
      if (posicao[1] == '1')
      {
        printf("\n");
        printf("   1  2  3 \n");
        linhaC[3] = caractere;
        printf("%s\n", linhaA);
        printf("%s\n", linha);
        printf("%s\n", linhaB);
        printf("%s\n", linha);
        printf("%s\n", linhaC);
        printf("\n");
      }
      else if (posicao[1] == '2')
      {
        printf("\n");
        printf("   1  2  3 \n");
        linhaC[6] = caractere;
        printf("%s\n", linhaA);
        printf("%s\n", linha);
        printf("%s\n", linhaB);
        printf("%s\n", linha);
        printf("%s\n", linhaC);
        printf("\n");
      }
      else if (posicao[1] == '3')
      {
        printf("\n");
        printf("   1  2  3 \n");
        linhaC[9] = caractere;
        printf("%s\n", linhaA);
        printf("%s\n", linha);
        printf("%s\n", linhaB);
        printf("%s\n", linha);
        printf("%s\n", linhaC);
        printf("\n");
      }
      else
      {
        printf("\nPosição Inválida.\nDigite novamente.\n");
        jogada--;
      }
    }

    else
    {
      printf("\nPosição Inválida.\nDigite novamente.\n");
      jogada--;
    }
      
    jogada++;
    getchar();
  }
}