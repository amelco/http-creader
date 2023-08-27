#include <stdio.h>
#include <stdlib.h>
#include "params.h"
#include "rotas.h"

#define NUM_MAX_ROTAS 256

int main(int argc, char *argv[])
{
  Params params = tratar_parametros(argc, argv);
  printf("entrada: %s\nsaida: %s\n", params.entrada, params.saida);

  Rota rotas[NUM_MAX_ROTAS] = {0};
  parse_file(params.entrada, rotas);
  imprime_rotas(rotas);

  return 0;
}

