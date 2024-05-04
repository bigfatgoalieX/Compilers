#include "symboltable.h"

#define HASHSIZE 0x3fff

// global hashtable
STNode* symbolTable[HASHSIZE] = {NULL};
