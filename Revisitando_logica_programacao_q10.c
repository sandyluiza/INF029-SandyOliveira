// Faça um programa que leia os dados de nome, idade, sexo e cpf de 5 pessoas. Ao final imprima tudo. Utilize vetor e struct.
#include <stdio.h>

typedef struct
{
  char Nome[100];
  int Idade;
  char Sexo;
  char CPF[11];
}
Informacoespessoas;

int main()
{
  Informacoespessoas pessoas[5];

  int i;
  
  for (i=0; i<5; i=i+1)
  {
    printf("\n Nome[%d]: ",i);
    fgets(pessoas[i].Nome, 100, stdin); 
    
    printf("Idade[%d]: ",i);
    scanf("%d", &pessoas[i].Idade);

    getchar();
    
    printf("Sexo[%d]: ",i);
    scanf("%c", &pessoas[i].Sexo);

     getchar();
    
    printf("CPF[%d]: ",i);
    fgets(pessoas[i].CPF, 100, stdin);
  }
  
  for (i=0; i<5; i++)
  {
  printf("Nome: %s", pessoas[i].Nome);
  printf("Idade: %d \n", pessoas[i].Idade);
  printf("Sexo: %c \n", pessoas[i].Sexo);
  printf("CPF: %s", pessoas[i].CPF);
  }
  
}