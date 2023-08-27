#ifndef PARAMS_H
#define PARAMS_H

typedef struct Params
{
  char* entrada;
  char* saida;
} Params;

extern Params tratar_parametros(int argc, char *argv[]);

#endif
