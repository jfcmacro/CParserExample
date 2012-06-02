%{
#include "parser.h"
%}

%option noyywrap

%%

[\t ] ;
::                                 { return SEPARATOR;   }
ProcesoSui                         { return PROCESOSUI;  }
[A-Za-z][A-Za-z0-9]*               { return ID;          }
\{                                 { return ABRELLAVE;   }
\}                                 { return CIERRALLAVE; }
\/([A-Za-z0-9])+(\/[A-Za-z0-9]+)*  { return PATH;     }
([1-9][0-9]|0)                     { return NUMERO;      }
<<EOF>>                            { yyterminate(); }
%%


