#include "parser.h"
#include "lexer.h"
#include "data.h"

extern int yyparse();

plProcesosSuicidas_t
execParserCfg(FILE* inFile) {
  yyin = inFile;

  if (!yyparse()) {
    return yylval.vlista;
  }

  return NULL;
}

void 
yyerror(const char *msg) {
  fprintf(stderr, "%s at %d in '%s'\n", msg, yylineno, yytext);
}

