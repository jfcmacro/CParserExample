#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "parser.h"
#include "lexer.h"

void
usage(char *progname) {
  fprintf(stderr, "Usage %s <cfg file>", progname);
  exit(1);
}

int 
main(int argc, char *argv[]) {

  if (argc != 2) {
    usage(argv[0]);
  }

  FILE *inFile = fopen(argv[1], "r");
  if (!inFile) {
    usage(argv[0]);
  }
  yyin = inFile;

  if (!yyparse()) {
    fprintf(stdout, "¡Parser funcionó!\n");
  }
  else {
    fprintf(stderr, "¡Parser no funcionó!\n");
  }
  return 0;
}

void 
yyerror(const char *msg)
{
  fprintf(stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
}
