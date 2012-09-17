%{
#include "parserExpr.h"
#include "expr.h"
%}

%option noyywrap

%%
([1-9]([0-9]*)|0)       { exprlval.vnumber = atoi(exprtext);
                          printf("numero: %s\n", exprtext);
                          return NUMERO; }
[A-Za-z]([A-Za-z0-9]*)  { exprlval.vtext = newID(exprtext); 
                          return ID; 
                        }
[ \t]                   {           }
\n                      { return 0; }
<<EOF>>                 { yyterminate(); }
.                       return exprtext[0];
%%


