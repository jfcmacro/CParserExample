#include "parserExpr.h"
#include "lexerExpr.h"
#include "expr.h"

extern int exprparse();

PNode
execParserExpr(FILE* inFile) {

  exprin = inFile;

  if (!exprparse()) {
    return exprlval.vnode; 
  }

  return NULL;
}

void
exprerror(const char *msg) {
  fprintf(stderr, "%s at %d  in '%s'\n", msg, exprlineno, exprtext);
}

