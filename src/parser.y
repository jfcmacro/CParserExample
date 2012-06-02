%{
#include <stdio.h>
%}
%token PROCESOSUI ID ABRELLAVE CIERRALLAVE PATH NUMERO SEPARATOR
%start archcfg
%%

archcfg : /* empty */ 
        | proceso archcfg {  }
        ;

proceso: PROCESOSUI ID ABRELLAVE PATH SEPARATOR ID NUMERO CIERRALLAVE { }
        ;
%%
