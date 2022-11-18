 // #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Sandy Luiza Martins de Oliveira
//  email: sandyluimo@gmail.com
//  Matrícula: 20212160013
//  Semestre: 02/2022

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "SandyOliveira20212160013.h" 
#include <stdlib.h>
#include <string.h>
#include <math.h>
int validacao_data();
int biss();

/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ 
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}


DataQuebrada quebraData(char data[])
{
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++)
  {
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2)
  { // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}
  else 
  {
		dq.valido = 0;
    return dq;
  }  

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++)
  {
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2)
  { // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}
  else 
  {
		dq.valido = 0;
    return dq;
  }

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++)
  {
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4)
  { // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}
  else 
  {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
  
  return dq;  
}

int validacao_data(DataQuebrada data)
{
  int cont=0, biss=0;
  
  // mes 30
  if (((data.iMes == 4)||(data.iMes == 6)||(data.iMes == 9)||(data.iMes == 11)) && ((data.iDia > 0) && (data.iDia < 31)))
  {
    cont = cont + 1;
  }
  // mes 31
  if (((data.iMes == 1)||(data.iMes == 3)||(data.iMes == 5)||(data.iMes == 7)||(data.iMes == 8)||(data.iMes == 10)||(data.iMes == 12)) && ((data.iDia > 0) && (data.iDia < 32)))
  {
    cont = cont + 1;
  }
  // ano biss
  if (data.iAno % 4 == 0)
  {
    biss = biss + 1;
  }
  else if ((data.iAno % 4 == 0) && (data.iAno % 100 == 0))
  {
    biss = 0;
  }
  else if ((data.iAno % 4 == 0) && (data.iAno % 100 == 0) && (data.iAno % 400 == 0))
  {
    biss = biss + 1;
  }
  if ((biss>0) && (data.iDia > 0) && (data.iDia < 30) && (data.iMes == 2))
  {
    cont = cont + 1;
  }
  else if ((biss == 0) && (data.iDia > 0) && (data.iDia < 29) && (data.iMes == 2))
  {
    cont = cont + 1;
  }
  return cont;
}


/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int datavalida;
  int validacao_data();

  DataQuebrada dataQuebrada = quebraData(data);
  
  if (dataQuebrada.valido == 0) 
  {
    return 0;
  }
  else
  {
    datavalida = validacao_data(dataQuebrada);
  }

  if (datavalida == 0)
  {
    return 0;
  }
  else
  {
    return 1;
  }  
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */

DiasMesesAnos q2(char datainicial[], char datafinal[])
{
  //calcule os dados e armazene nas três variáveis a seguir
  DiasMesesAnos dma;
  dma.qtdDias = 0;
  dma.qtdMeses = 0;
  dma.qtdAnos = 0;
  dma.retorno = 0;

  DataQuebrada dataQuebradai = quebraData(datainicial);
  DataQuebrada dataQuebradaf = quebraData(datafinal);
  DataQuebrada dataQuebradainicial = quebraData(datainicial);

  if (q1(datainicial) == 0)
  {
    dma.retorno = 2;
    return dma;
  }
  else if (q1(datafinal) == 0)
  {
    dma.retorno = 3;
    return dma;
  }
    
  // (datainicial > datafinal)
  else if (dataQuebradaf.iAno < dataQuebradai.iAno)
  {
    dma.retorno = 4;
    return dma;
  }
  else if ((dataQuebradaf.iAno == dataQuebradai.iAno) && (dataQuebradaf.iMes < dataQuebradai.iMes))
  {
    dma.retorno = 4;
    return dma;
  }
  else if ((dataQuebradaf.iAno == dataQuebradai.iAno) && (dataQuebradaf.iMes == dataQuebradai.iMes) && (dataQuebradaf.iDia < dataQuebradai.iDia))
  {
    dma.retorno = 4;
    return dma;
  }
    
  else 
  {
    while((dataQuebradaf.iDia != dataQuebradainicial.iDia) || (dataQuebradaf.iMes != dataQuebradainicial.iMes) || (dataQuebradaf.iAno != dataQuebradainicial.iAno))
    {
      // printf("anos %d\n", dma.qtdAnos);
      
      if (((dataQuebradaf.iDia >= dataQuebradainicial.iDia) && (dataQuebradaf.iMes >= dataQuebradainicial.iMes) && (dataQuebradaf.iAno > dataQuebradainicial.iAno)) || (dataQuebradaf.iAno > dataQuebradainicial.iAno + 1))
      {
        
        dataQuebradainicial.iAno = dataQuebradainicial.iAno + 1;
        dma.qtdAnos = dma.qtdAnos + 1;

        int cont = biss(dataQuebradainicial);
        if (cont > 0)
        {
          dma.qtdDias =  dma.qtdDias + 1;
        }
      }
      
      else if ((dataQuebradaf.iDia > dataQuebradainicial.iDia) && (dataQuebradaf.iMes > dataQuebradainicial.iMes))
      {
        
        dataQuebradainicial.iMes = dataQuebradainicial.iMes + 1;
        dma.qtdMeses = dma.qtdMeses + 1;
        if((dataQuebradainicial.iMes == 1)||(dataQuebradainicial.iMes == 3)||(dataQuebradainicial.iMes == 5)||(dataQuebradainicial.iMes == 7)||(dataQuebradainicial.iMes == 8)||(dataQuebradainicial.iMes == 10)||(dataQuebradainicial.iMes == 12))
        {
          dma.qtdDias =  dma.qtdDias + 1;
        }
        else if(dataQuebradainicial.iMes == 2)
        {
          dma.qtdDias =  dma.qtdDias - 2;
          int cont = biss(dataQuebradainicial);
          if (cont > 0)
          {
            dma.qtdDias =  dma.qtdDias + 1;
          }
        }
        if((dataQuebradaf.iMes == 1)||(dataQuebradaf.iMes == 3)||(dataQuebradaf.iMes == 5)||(dataQuebradaf.iMes == 7)||(dataQuebradaf.iMes == 8)||(dataQuebradaf.iMes == 10)||(dataQuebradaf.iMes == 12))
        {
          dma.qtdDias =  dma.qtdDias - 1;
        }
        dataQuebradainicial.iDia = dataQuebradainicial.iDia + 1;
        dma.qtdDias = dma.qtdDias + 1;
      }
        
      else if(dataQuebradaf.iDia > dataQuebradainicial.iDia)
      {
        dataQuebradainicial.iDia = dataQuebradainicial.iDia + 1;
        dma.qtdDias = dma.qtdDias + 1;
      }
          
      else if ((dataQuebradaf.iDia < dataQuebradainicial.iDia) && (dataQuebradaf.iMes < dataQuebradainicial.iMes) && (dataQuebradaf.iAno == dataQuebradainicial.iAno + 1))
      {
        dataQuebradainicial.iAno = dataQuebradaf.iAno;

        if (dataQuebradainicial.iMes < dataQuebradaf.iMes - 1)
        {
          dataQuebradainicial.iMes = dataQuebradainicial.iMes + 1;
          dma.qtdMeses = dma.qtdMeses + 1;
          if (dataQuebradainicial.iMes > 12)
          {
            dataQuebradainicial.iMes = 1;
          }
          else if((dataQuebradainicial.iMes == 1)||(dataQuebradainicial.iMes == 3)||(dataQuebradainicial.iMes == 5)||(dataQuebradainicial.iMes == 7)||(dataQuebradainicial.iMes == 8)||(dataQuebradainicial.iMes == 10)||(dataQuebradainicial.iMes == 12))
          {
            dma.qtdDias =  dma.qtdDias + 1;
          }
          else if(dataQuebradainicial.iMes == 2)
          {
            dma.qtdDias =  dma.qtdDias - 2;
            int cont = biss(dataQuebradainicial);
            if (cont > 0)
            {
              dma.qtdDias =  dma.qtdDias + 1;
            }
          }
        }
        if (dataQuebradainicial.iMes + 1 == dataQuebradaf.iMes)
        {
          dataQuebradainicial.iMes = dataQuebradaf.iMes;
          dataQuebradainicial.iDia  = dataQuebradainicial.iDia + 1;
          dma.qtdDias = dma.qtdDias + 1;
          if (dataQuebradainicial.iDia > 30)
          {
            dataQuebradainicial.iDia = 1;
          }
        }
      }
    }
    
    dma.retorno = 1;
    return dma;
  } 
}

int biss(DataQuebrada dataQuebradainicial)
{
  int biss = 0, cont = 0;
  if (dataQuebradainicial.iAno % 4 == 0)
  {
    biss = biss + 1;
  }
  else if ((dataQuebradainicial.iAno % 4 == 0) && (dataQuebradainicial.iAno % 100 == 0))
  {
    biss = 0;
  }
  else if ((dataQuebradainicial.iAno % 4 == 0) && (dataQuebradainicial.iAno % 100 == 0) && (dataQuebradainicial.iAno % 400 == 0))
  {
    biss = biss + 1;
  }
  if ((biss>0) && (dataQuebradainicial.iDia > 0) && (dataQuebradainicial.iDia < 30) && (dataQuebradainicial.iMes == 2))
  {
    cont = cont + 1;
  }
  else if ((biss == 0) && (dataQuebradainicial.iDia > 0) && (dataQuebradainicial.iDia < 29) && (dataQuebradainicial.iMes == 2))
  {
    cont = cont + 1;
  }
  return cont;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
  int qtdOcorrencias=0;

  if (isCaseSensitive == 1)
  {
    for(int i = 0; i < strlen(texto); i++)
    {
      if (c == texto[i])
      {
        qtdOcorrencias = qtdOcorrencias + 1;
      }
    }
  }
  else
  {
    c = tolower(c);
    for(int i = 0; i < strlen(texto); i++)
    {
      if (c == tolower(texto[i]))
      {
        qtdOcorrencias = qtdOcorrencias + 1;
      }
    }
  }
  return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
  int qtdOcorrencias = 0, o = 0, qtd_carac_espec = 0;
  int letra;
  for (int j=0; j < strlen(strTexto); j++)
  {
    int cont = 0;
    letra = strTexto[j];
    if (letra == -61)
    {
      qtd_carac_espec = qtd_carac_espec + 1;
    }
    
    if (strBusca[0] == strTexto[j])
    {
      for(int i=0; i <strlen(strBusca); i++)
      {
        if (strBusca[i] == strTexto[j+i])
        {
          cont = cont + 1;
        }
      }
    }
    if (cont == strlen(strBusca))
    {
      qtdOcorrencias = qtdOcorrencias + 1;
      posicoes[o] = j + 1 - qtd_carac_espec;
      o++;
      posicoes[o] = j + cont - qtd_carac_espec;
      o++;
    }
  }

  return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */
int q5(int num)
{
  char num1[50];
  int numesse, p = 1, numfim = 0;
  sprintf(num1, "%d", num);
  int tam = strlen(num1);

  for (int z = 0; z<tam; z++)
  {
    p = p*10;
  }
  
  while (num > 1)
  {
    numesse = num % 10;
    numfim = numfim + numesse*p;
    num = num/10;
    p = p/10;
  }
  num = numfim/10;
  return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */
int q6(int numerobase, int numerobusca)
{
  int qtdOcorrencias = 0, o = 0;
  char strTexto[100], strBusca[100];
  
  sprintf(strTexto, "%d", numerobase);
  sprintf(strBusca, "%d", numerobusca);
  
  for (int j=0; j < strlen(strTexto); j++)
  {
    int cont = 0;
    if (strBusca[0] == strTexto[j])
    {
      for(int i=0; i <strlen(strBusca); i++)
      {
        if (strBusca[i] == strTexto[j+i])
        {
          cont = cont + 1;
        }
      }
    }
    if (cont == strlen(strBusca))
    {
      qtdOcorrencias = qtdOcorrencias + 1;
    }
  }
  return qtdOcorrencias;
}