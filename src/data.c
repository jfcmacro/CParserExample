#include <stdlib.h>
#include <string.h>
#include "data.h"

static char*
newCopyString(char n[]){
  char *p;
  int longitud;

  longitud = strlen(n);
  p = (char *) malloc(longitud + 1);
  strcpy(p,n);
  return p;
}

pprocesoSuicida_t
createProcesoSuicida(char id[], char ruta[], char nombreArchivo[],
                     int contador) {
  pprocesoSuicida_t ps;
  int longitud;
  ps = (pprocesoSuicida_t) malloc(sizeof(procesoSuicida_t));
  ps->id = newCopyString(id);
  ps->ruta = newCopyString(ruta);
  ps->nombreArchivo = newCopyString(nombreArchivo);
  ps->contadorActual = ps->contadorInicial = contador;

  return ps;
}
