#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

int *vetorPrincipal[TAM];
int tam_vetor[TAM];
int vetor_preenchido[TAM];
int vetorAux[TAM];

// Dessa forma fica mais elegante
// typedef struct ele {
//   int quantidade;
//   int tamanho;
//   int *aux;
//} Elemento;
// Elemento vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
  int retorno = 0, i;
  posicao = posicao - 1;
  vetor_preenchido[posicao] = 0;
  
  // a posicao pode já existir estrutura auxiliar
  if (vetorPrincipal[posicao] != NULL)
  {
    retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    return retorno;
  }

  // se posição é um valor válido {entre 1 e 10}
  else if ((posicao>9)||(posicao<0))
  {  
    retorno = POSICAO_INVALIDA;
    return retorno;
  }

  // o tamanho ser muito grande
  else if (tamanho > TAM)
  {
    retorno = SEM_ESPACO_DE_MEMORIA;
    return retorno;
  }

  // o tamanho nao pode ser menor que 1
  else if (tamanho < 1)
  {
    retorno = TAMANHO_INVALIDO;
    return retorno;
  }
  
  // deu tudo certo, crie
  else 
  {
    int estrutura_aux[tamanho];
   
    vetorPrincipal[posicao] = estrutura_aux;
    
    tam_vetor[posicao] = tamanho;

    retorno = SUCESSO;
    return retorno;
  }
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
  int retorno = 0, i;
  int existeEstruturaAuxiliar = 0;
  int temEspaco = 0;
  int posicao_invalida = 0;
  posicao = posicao - 1;
  int contador=0;

  // printf("posicao %d\n", posicao);
  if ((posicao>9)||(posicao<0))
  {
    retorno = POSICAO_INVALIDA;
    return retorno;
  }
      
  else
  {
    // existe a estrutura auxiliar
    if (vetorPrincipal[posicao] != NULL)
    {
      for(i = vetor_preenchido[posicao]; i < tam_vetor[posicao]; i++)
      {
        if (vetor_preenchido[posicao] < tam_vetor[posicao])
        {
          *(vetorPrincipal[posicao]+i) = valor;
          // printf("valor vetor pree %d\n", *(vetorPrincipal[posicao]+i));
          vetor_preenchido[posicao]++;
          retorno = SUCESSO;
          contador++;
          return retorno;
        }
      }
      if (contador == 0)
      {
        retorno = SEM_ESPACO;
        return retorno;
      }
    }
      
    // não existe estrutura auxiliar
    else
    {
      retorno = SEM_ESTRUTURA_AUXILIAR;
      return retorno;
    }
  }  

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
  int retorno = 0, i;
  int existeEstruturaAuxiliar = 0;
  int temEspaco = 0;
  int posicao_invalida = 0;
  posicao = posicao - 1;
  
  if ((posicao>9)||(posicao<0))
  {
    retorno = POSICAO_INVALIDA;
    return retorno;
  }
      
  else
  {
    // tem estrutura auxiliar 
    // excluir da estrutura auxiliar com sucesso
    if (vetorPrincipal[posicao] != NULL)
    {
      if (vetor_preenchido[posicao] == 0)
      {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
        return retorno;
      }

      else
      {
        // vetorPrincipal[posicao]+vetor_preenchido[posicao] = NULL;
        vetor_preenchido[posicao]--;
        retorno = SUCESSO;
        return retorno;
      }
      
    }
      
    // não existe estrutura auxiliar
    else
    {
      retorno = SEM_ESTRUTURA_AUXILIAR;
      return retorno;
    }
  }


}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    okESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    okSEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe na estrutura auxiliar
    okPOSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
  int retorno = 0;
  int posicao_invalida = 0;
  posicao = posicao - 1;
  int i, contador_de_posicoes=0, contador_achou_num=0;

  
  if ((posicao>9)||(posicao<0))
  {
    retorno = POSICAO_INVALIDA;
    return retorno;
  }
      
  else
  {
    // esse
    if (vetorPrincipal[posicao] != NULL)
    {
      if (vetor_preenchido[posicao] == 0)
      {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
        return retorno;
      }
        
      // fazer esse    
      else
      {
        for (i=0; i < vetor_preenchido[posicao]; i++)
        {
          if (*(vetorPrincipal[posicao]+i) == valor)
          {
            contador_achou_num++;
            while (contador_de_posicoes < vetor_preenchido[posicao])
            {
              *(vetorPrincipal[posicao]+i) = *(vetorPrincipal[posicao]+i+1);
              contador_de_posicoes++;
            }
            vetor_preenchido[posicao]--;
          } 
        }
        
        if(contador_achou_num > 0)
        {
          retorno = SUCESSO;
          return retorno;
        }
        
        else
        {
          retorno = NUMERO_INEXISTENTE;
          return retorno;
        }
      }
    }
      
    else
    {
      retorno = SEM_ESTRUTURA_AUXILIAR;
      return retorno;
    }
  }  
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  int retorno = 0;
  int posicao_invalida = 0;
  posicao = posicao - 1;
  int i;
  int existeEstruturaAuxiliar = 0;
  int temEspaco = 0;
  

  if ((posicao>9)||(posicao<0))
  {
    retorno = POSICAO_INVALIDA;
    return retorno;
  }
      
  else
  {
    if (vetorPrincipal[posicao] != NULL)
    {
      if (vetor_preenchido[posicao] == 0)
      {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
        return retorno;
      }
        
      else
      {
        for (i=0; i < vetor_preenchido[posicao]; i++)
        {
          vetorAux[i] = *(vetorPrincipal[posicao]+i);
        }
        retorno = SUCESSO;
        return retorno;
      }
    }
      
    else
    {
      retorno = SEM_ESTRUTURA_AUXILIAR;
      return retorno;
    }
  }  
}


/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  int retorno = 0;
  int posicao_invalida = 0;
  posicao = posicao - 1;
  int i;
  int existeEstruturaAuxiliar = 0;
  int temEspaco = 0;

  if ((posicao>9)||(posicao<0))
  {
    retorno = POSICAO_INVALIDA;
    return retorno;
  }
      
  else
  {
    if (vetorPrincipal[posicao] != NULL)
    {
      if (vetor_preenchido[posicao] == 0)
      {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
        return retorno;
      }
        
      else
      {
        for (i=0; i < vetor_preenchido[posicao]; i++)
        {
          vetorAux[i] = *(vetorPrincipal[posicao]+i);
        }
      }
      
      for (int i=0; i<vetor_preenchido[posicao]; i++)
      {
        for (int j=0; j<vetor_preenchido[posicao]; j++)
        {
          if (vetorAux[i]<vetorAux[j])
          {
            int aux = vetorAux[j];
            vetorAux[j] = vetorAux[i];
            vetorAux[i] = aux;
          }  
        }
      }
      retorno = SUCESSO;
      return retorno;
    }
      
    else
    {
      retorno = SEM_ESTRUTURA_AUXILIAR;
      return retorno;
    }
  }  
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
  int contador=0, quantidade = 0;
  int retorno =0, j=0;
  
  // printf("vetor principal %d\n", *(vetorPrincipal[4]+0));
  for (int i=0; i<TAM; i++)
  {
    if (&vetor_preenchido[i] != NULL)
    {
      quantidade = vetor_preenchido[i] + quantidade;
      // printf("vetor preenchido %d\n", quantidade);
    }
  }
  
  for (int i=0; i<TAM; i++)
  {
    if ((vetor_preenchido[i] == 0) || (vetorPrincipal[i] == NULL))
    {
      contador++;
    }
        
    else
    {
      for (int g=0; g<vetor_preenchido[i]; g++)
      {
        vetorAux[j] = *(vetorPrincipal[i]+g);
        j++;
          // printf("valor vet aux %d\n",vetorAux[j]);
      }
    }
  }

  if (contador == TAM)
  {
    retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    return retorno;
  }
    
  else 
  {
    retorno = SUCESSO;
    return retorno;
  } 
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
  int contador=0, contador1=0, quantidade = 0;
  int retorno =0, j=0;

  for (int i=0; i<TAM; i++)
  {
    // if (vetor_preenchido[i] != NULL)
    // {
      quantidade = vetor_preenchido[i] + quantidade;
      // printf("quantidade %d\n", quantidade);
    // }
  }
  
  for (int i=0; i<TAM; i++)
  {
    if ((vetor_preenchido[i] == 0) || (vetorPrincipal[i] == NULL))
    {
      contador++;
    }
        
    else
    {
      for (int g=0; g<vetor_preenchido[i]; g++)
      {
        vetorAux[j] = *(vetorPrincipal[i]+g);
        j++;
          // printf("valor vet aux %d\n",vetorAux[j]);
      }
    }
  }

  if (contador == TAM)
  {
    retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    return retorno;
  }
    
  else 
  { 
    for (int i=0; i<quantidade; i++)
    {
      for (int j=0; j<quantidade; j++)
      {
        if (vetorAux[i]<vetorAux[j])
        {
          int aux = vetorAux[j];
          vetorAux[j] = vetorAux[i];
          vetorAux[i] = aux;
        }  
      }
    }
    retorno = SUCESSO;
    return retorno;
  }
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    okSEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    okPOSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    okNOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    okSEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
  int retorno = 0, i, tamanho_final;
  posicao = posicao - 1;
  // printf("posicao %d\n", posicao);
  
  tamanho_final = tam_vetor[posicao] + novoTamanho;
  
  if ((posicao > 9)||(posicao < 0))
  { 
    // printf("entrou posi inv\n");
    retorno = POSICAO_INVALIDA;
    return retorno;
  }

  else if (tamanho_final > TAM)
  {
    // printf("entrou sem espa\n");
    retorno = SEM_ESPACO_DE_MEMORIA;
    return retorno;
  }

  else if (tamanho_final <= 0)
  {
    // printf("entrou tam inv\n");
    retorno = NOVO_TAMANHO_INVALIDO;
    return retorno;
  }
  
  else if (vetorPrincipal[posicao] == NULL)
  {
    // printf("entrou sem estru aux\n");
    retorno = SEM_ESTRUTURA_AUXILIAR;
    return retorno;
  }
  
  // deu tudo certo, aumente
  else 
  {
    vetorPrincipal[posicao] = (int *)realloc(vetorPrincipal[posicao], novoTamanho*sizeof(int));
    // printf("entrou aumentou estru\n");
    // printf("vet preen %d\n", vetor_preenchido[posicao]);
    // printf("tam vet pos %d\n", tam_vetor[posicao]);
    tam_vetor[posicao] = tamanho_final;
    // printf("tam vet pos %d\n", tam_vetor[posicao]);

    if(vetor_preenchido[posicao] > tam_vetor[posicao])
    {
      vetor_preenchido[posicao] = tam_vetor[posicao];
      // printf("vet preen %d\n", vetor_preenchido[posicao]);
    }
    retorno = SUCESSO;
    return retorno;
  }
}


/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
  int retorno = 0;
  
  if ((posicao > 9)||(posicao < 0))
  { 
    // printf("entrou posi inv\n");
    retorno = POSICAO_INVALIDA;
    return retorno;
  }
  
  if (vetorPrincipal[posicao] != NULL)
  {
    // printf("entrou em dif null\n");
    if (vetor_preenchido[posicao] == 0)
    {
      retorno = ESTRUTURA_AUXILIAR_VAZIA;
      return retorno;
    }
    else
    {
      // printf("quant ele preen %d\n", vetor_preenchido[posicao]);
      retorno = vetor_preenchido[posicao];
      return retorno;
    }
  }
    
  else if(vetorPrincipal[posicao] == NULL)
  {
    // printf("entrou sem estru aux\n");
    retorno = SEM_ESTRUTURA_AUXILIAR;
    return retorno;
  }
  
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
  free(vetorPrincipal[TAM]);
}