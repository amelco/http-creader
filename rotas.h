#ifndef ROTAS_H
#define ROTAS_H

typedef enum Tipo
{
  GET,
  POST,
  PATCH,
  PUT
} Tipo;

typedef struct Rota
{
  Tipo tipo;
  char* url;
} Rota;

extern void parse_file(char* arquivo, Rota *rotas);

extern void imprime_rotas(Rota *rotas);

#endif
