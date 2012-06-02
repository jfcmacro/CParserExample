#ifndef _DATA_H
#define _DATA_H



struct ProcesosSuicidas {
  char *id;
  char *ruta;
  char *nombreArchivo;
  int  contadorActual; 
  int  contadorInicial;
};

typedef struct ProcesosSuicidas procesoSuicida_t;
typedef struct ProcesosSuicidas* pprocesoSuicida_t;

#endif
