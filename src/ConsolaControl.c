#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "expr.h"
#include "parserCfg.h"
#include "parserExprExec.h"

void
usage(char *progname) {
  fprintf(stderr, "Usage %s <cfg file> <expr file>\n", progname);
  exit(1);
}


int 
main(int argc, char *argv[]) {

  if (argc != 3) {
    usage(argv[0]);
  }

  FILE *inFile   = fopen(argv[1], "r");
  FILE *exprFile = fopen(argv[2], "r");

  if (!inFile || 
      !exprFile) {
    usage(argv[0]);
  }

  plProcesosSuicidas_t lProSui = NULL;

  if ((lProSui = execParserCfg(inFile))) {

    fprintf(stdout, "¡Parser archivo de configuración funcionó!\n");
    showLProcesosSuicidas(lProSui);
  }
  else {

    fprintf(stderr, "¡Parser archivo de configuración no funcionó!\n");
  }

  PNode pExpr = NULL;

  if ((pExpr = execParserExpr(exprFile))) {

    fprintf(stdout, "¡Parser expresion funcionó!\n");
    fprintf(stdout, "El valor de la expresion es: %d\n", eval(pExpr));
  }
  else {

    fprintf(stderr, "¡Parser expresion no funcionó!\n");
  }
  return 0;
}

