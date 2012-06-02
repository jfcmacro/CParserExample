.phony: all clean

all: ConsolaControl

CFLAGS=-Wall
LDFLAGS=

SRC=parser.c lexer.c data.c ConsolaControl.c
OBJECTS=$(SRC:.c=.o)

parser.c parser.h: parser.y Tokens.h
	bison -W -o parser.c --defines=parser.h parser.y

lexer.c lexer.h: lexer.l parser.h
	flex --outfile=$@ --header-file=lexer.h $<

ConsolaControl: $(OBJECTS) 
	gcc $(LDFLAGS) -o $@ $(OBJECTS)


clean:
	rm -f *.o parser.c parser.h lexer.h lexer.c *.c~ *.l~ *.y~ Makefile~ *.h~ *~ ConsolaControl