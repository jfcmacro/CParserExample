#include <stdlib.h>
#include <string.h>

#include "expr.h"

char*
newID(char* oldID) {
  char* ret;
  char* pos;
  pos = ret = malloc(strlen(oldID) + 1);
  if (ret) {
    while ((*pos++ = *oldID++)) {
    }
  }
  return ret;
}

PNode
newNode() {
  PNode ret = (PNode) malloc(sizeof(Node));
  ret->leftChild = ret->rightChild = NULL;
  return ret;
}

PNode
newIDN(char* id) {
  PNode ret;

  ret = newNode();
  ret->tagInfo = T_ID;
  ret->info.id = id;
  return ret;
}

PNode
newNumber(int value) {
  PNode ret;

  ret = newNode();
  ret->tagInfo = T_NUMBER;
  ret->info.numero = value;
  return ret;
}

PNode
newSum(PNode left, PNode right) {
  PNode ret;
  ret = newNode();
  ret->tagInfo = T_OPER;
  ret->info.oper = O_SUM;
  ret->leftChild = left;
  ret->rightChild = right;

  return ret;
}

PNode
newMul(PNode left, PNode right) {
  PNode ret;
  ret = newNode();
  ret->tagInfo = T_OPER;
  ret->info.oper = O_MUL;
  ret->leftChild = left;
  ret->rightChild = right;

  return ret;
}

int
eval(PNode root) {
  switch(root->tagInfo) {
  case T_OPER:
    switch(root->info.oper) {
    case O_SUM:
      return eval(root->leftChild) + eval(root->rightChild);
      break;

    case O_MUL:
      return eval(root->leftChild) * eval(root->rightChild);
      break;
    }
    break;

  case T_NUMBER:
    return root->info.numero;
    break;

  case T_ID:
    return 0; // Context not yet defined
    break;
  }
  return 0;
}
