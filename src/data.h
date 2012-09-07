#ifndef _DATA_H
#define _DATA_H

struct ProcesoSuicida {
  char *id;
  char *ruta;
  char *nombreArchivo;
  int  contadorActual;
  int  contadorInicial;
};

typedef struct ProcesoSuicida   procesoSuicida_t;
typedef struct ProcesoSuicida*  pprocesoSuicida_t;
typedef struct LProcesosSuicidas  lProcesosSuicidas_t;
typedef struct LProcesosSuicidas* plProcesosSuicidas_t;

struct LProcesosSuicidas {
  pprocesoSuicida_t  ps;
  plProcesosSuicidas_t next;
};

void deleteStructProcesoSuicida(pprocesoSuicida_t ps);
pprocesoSuicida_t createProcesoSuicida(char id[], char ruta[],
				       char nombreArchivo[],
				       int contador);
plProcesosSuicidas_t newLProcesosSuicidas();
plProcesosSuicidas_t addLista(plProcesosSuicidas_t head,
			      pprocesoSuicida_t ps);
#endif
