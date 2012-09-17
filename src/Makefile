.phony: all clean

all: ConsolaControl

CFLAGS=-Wall
LDFLAGS=

SRC=parser.c lexer.c parserExpr.c lexerExpr.c data.c expr.c ConsolaControl.c \
    execParserExpr.c execParserCfg.c
OBJECTS=$(SRC:.c=.o)

parser.c parser.h: parser.y Tokens.h
	bison --verbose --warnings --output=parser.c \
	--defines=parser.h parser.y

parserExpr.c parserExpr.h: parserExpr.y
	bison --verbose --warnings --name-prefix=expr --output=parserExpr.c \
	--defines=parserExpr.h parserExpr.y

lexer.c lexer.h: lexer.l
	flex --outfile=$@ --header-file=lexer.h $<

lexerExpr.c lexerExpr.h: lexerExpr.l
	flex --outfile=$@ --prefix=expr --header-file=lexerExpr.h $<

ConsolaControl: $(OBJECTS)
	gcc $(LDFLAGS) -o $@ $(OBJECTS)

clean:
	rm -f *.o parser.c parser.h lexer.h lexer.c *.c~ *.l~ *.y~ Makefile~ \
	parserExpr.c parserExpr.h lexerExpr.h lexerExpr.c *.h~ *~ \
	ConsolaControl execParserExpr.o execParserCfg.o