%{
#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int yylex();
void yyerror(const char *msg);
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
%start abssyn
%type <vlista> abssyn
%type <vlista> archcfg
%type <vps> proceso
%%

abssyn : archcfg  { yylval.vlista = $1; }
       ;

archcfg : proceso archcfg { $$ = addLista($2, $1); }
| /*empty*/       { $$ = (plProcesosSuicidas_t) NULL; }
        ;

proceso : PROCESOSUI ID ABRELLAVE PATH SEPARATOR ID NUMERO CIERRALLAVE 
         {  $$ = createProcesoSuicida($2, $4, $6, $7); }
        ;
%%
