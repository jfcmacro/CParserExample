#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "data.h"

char*
newCopyString(char n[]){
  char *p;
  int longitud;

  longitud = strlen(n);
  p = (char *) malloc(longitud + 1);
  strcpy(p,n);
  return p;
}

void
deleteStructProcesoSuicida(pprocesoSuicida_t ps) {
  free(ps->id);
  free(ps->ruta);
  free(ps->nombreArchivo);
  free(ps);
  return;
}

pprocesoSuicida_t
createProcesoSuicida(char id[], char ruta[], char nombreArchivo[],
                     int contador) {
  pprocesoSuicida_t ps;

  ps = (pprocesoSuicida_t) malloc(sizeof(procesoSuicida_t));
  ps->id = id ;
  ps->ruta = ruta;
  ps->nombreArchivo = nombreArchivo;
  ps->contadorActual = ps->contadorInicial = contador;

  return ps;
}

plProcesosSuicidas_t
newLProcesosSuicidas() {
  return (plProcesosSuicidas_t) malloc(sizeof(lProcesosSuicidas_t));
}

plProcesosSuicidas_t
addLista(plProcesosSuicidas_t head, pprocesoSuicida_t ps) {
  plProcesosSuicidas_t nHead = newLProcesosSuicidas();
  nHead->ps = ps;
  nHead->next = head;
  return nHead;
}

void
showLProcesosSuicidas(plProcesosSuicidas_t list) {
  while (list) {
    pprocesoSuicida_t ps = list->ps;
    fprintf(stdout, 
	    "id: %s ruta: %s nombre archivo: %s actual: %d inicial: %d\n", 
	    ps->id, ps->ruta, ps->nombreArchivo,
	    ps->contadorActual, ps->contadorInicial);
    list = list->next;
  }
}

