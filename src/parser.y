%{
#include <stdio.h>
#include <stdlib.h>
#include "data.h"
%}

%union {
  char *vtext;
  int  vnumber;
  struct LProcesosSuicidas* vlista;
  struct ProcesoSuicida*  vps;
}

%token PROCESOSUI ABRELLAVE CIERRALLAVE SEPARATOR
%token <vtext>   ID PATH
%token <vnumber> NUMERO
%start archcfg
%type <vlista> archcfg
%type <vps> proceso
%%

archcfg : /* empty */     { $$ = (plProcesosSuicidas_t) NULL; }
| proceso archcfg { $$ = addLista($2, $1); }
        ;

proceso: PROCESOSUI ID ABRELLAVE PATH SEPARATOR ID NUMERO CIERRALLAVE 
{ printf("%s\n", $6); $$ = createProcesoSuicida($2, $4, $6, $7); }
        ;
%%
