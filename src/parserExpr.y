%{
#include <stdio.h>
#include <stdlib.h>
#include "expr.h"

int exprlex();
void exprerror(const char *msg);
%}

%union {
  char *vtext;
  int  vnumber;
  struct node*  vnode;
}

%token <vtext>   ID
%token <vnumber> NUMERO
%start abssyn
%type <vnode> abssyn
%type <vnode> expresion
%type <vnode> termino
%type <vnode> factor

%%

abssyn : expresion ';' { exprlval.vnode = $1; }
       ;

expresion : expresion '+' termino { $$ = newSum($1,$3);  } 
          | termino { printf("exp -> termino\n"); $$ = $1; }
          ;
 
termino : expresion '*' factor { $$ = newMul($1,$3);}
        | factor { $$ = $1; }
        ;

factor : NUMERO            { $$ = newNumber($1); }
       | ID                { $$ = newIDN($1); }
       | '(' expresion ')' { $$ = $2; }
       ;
%%
