#ifndef EXPR_H
#define EXPR_H

enum operator { O_SUM, O_MUL };

union info {
  enum operator oper;
  int numero;
  char *id;
};

enum tagInfo { T_NUMBER, T_OPER, T_ID };

struct node {
  enum tagInfo tagInfo;
  union info info;
  struct node *leftChild, *rightChild;
};

typedef struct node Node;
typedef struct node* PNode;

PNode newNode();
char* newID(char*);
PNode newSum(PNode,PNode);
PNode newMul(PNode,PNode);
PNode newNumber(int);
PNode newIDN(char*);

int eval(PNode);
#endif
