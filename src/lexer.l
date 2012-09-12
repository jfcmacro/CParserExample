%{
#include "parser.h"
#include "data.h"
%}

%option noyywrap

%%
[\t ]* ;
::                                 { return SEPARATOR;   }
ProcesoSui                         { return PROCESOSUI;  }
[A-Za-z][A-Za-z0-9]*               { yylval.vtext = newCopyString(yytext); return ID; }
\{                                 { return ABRELLAVE;   }
\}                                 { return CIERRALLAVE; }
\/([A-Za-z0-9])+(\/[A-Za-z0-9]+)*  { yylval.vtext = newCopyString(yytext); return PATH; }
([1-9][0-9]|0)                     { yylval.vnumber = atoi(yytext); return NUMERO; }
<<EOF>>                            { yyterminate(); }
%%


