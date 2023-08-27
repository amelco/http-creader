#include "params.h"

#define NO_PARAM 1

char
checa_letra(char args[])
{
  if (args[0] == '-')
  {
    return args[1];
  }
  return '\0';
}

Params
tratar_parametros(int argc, char *argv[])
{
  Params params;
  params.entrada = "in.http";
  params.saida = "out.txt";
  
  if (argc == NO_PARAM)
  {
    return params;
  }

  for (int i=1; i<argc; i++)
  {
    char letra = checa_letra(argv[i]);
    i++;

    if (letra == '\0')
      break;
    else if (letra == 'f')
      params.entrada = argv[i];
    else if (letra == 'o')
      params.saida = argv[i];
  }

  return params;

}


