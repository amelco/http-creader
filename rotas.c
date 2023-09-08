#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rotas.h"
#include "types.h"

char*
trim(char* s, int len)
{
  if (!s)
    return NULL;
  if (!*s)
    return s;
  
  for (int i=0; i<len; i++)
  {
    if (s[i] == ' ')
    {
      i--;
      s = s + 1;
    }
    else
      break;
  }

  for (int i=len-1; i>=0; i--)
  {
    if (s[i] == ' ')
      s[i] = '\0';
    else
      break;
  }

  return s;

}

FILE*
abre_arquivo(char* arquivo)
{
  FILE *file;
  file = fopen(arquivo, "r");
  if (file == NULL)
  {
    fprintf(stderr, "Error: file does not exist.\n");
    exit(EXIT_FAILURE);
  }
  return file;
}

typedef struct Variavel
{
  char nome[255];
  int tam;
  char valor[255];
  int tam_valor;
} Variavel;

Variavel variaveis[255] = {0};
int qtd_var = 0;

Variavel
identifica_variavel(char* linha, int tam)
{
  Variavel var;

  for (int i=1; i<tam; i++)
  {
    if (linha[i] == '=')
    {
      var.nome[i-1] = '\0';
      strcpy(variaveis[qtd_var].nome, var.nome);
      qtd_var++;
      return var;
    }
    var.nome[i-1] = linha[i];
  }
  return var;
}


void
parse_file(char* arquivo, Rota *rotas)
{
  // printf("Abrir arquivo.\nLer variaveis\nLer rotas, substituir variaveis, criar Rota e preencher lista de Rotas\n");
  
  FILE *file = abre_arquivo(arquivo);

  char* line = NULL;
  size_t len = 0;
  size_t read;
  printf("\nConteudo do arquivo:\n");
  while ((read = getline(&line, &len, file)) != -1)
  {
    char* trimmed = trim(line, len);
    printf("%s", trimmed);

    if (trimmed[0] == '@')
    {
      identifica_variavel(trimmed, len);
      printf("nome: %s\nvalor: %s", variaveis[0].nome, variaveis[0].valor);
    }

  }


  rotas[0].url = "teste 1 PATCH";
  rotas[0].tipo = PATCH;
  rotas[1].url = "teste 2 PUT";
  rotas[1].tipo = PUT;
}

void
imprime_rotas(Rota *rotas)
{
  for (int i=0; rotas[i].url != 0; i++)
  {
    printf("rota %d: %s | tipo: %d\n", i, rotas[i].url, rotas[i].tipo);
  }
}

