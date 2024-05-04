#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "tree.h"

struct Type{
    enum {BASIC, ARRAY, STRUCTURE, FUNCTION } kind;
    union{
        int basic; // 0 for int, 1 for float
        struct {struct Type* elem; int size;} array; // array type and size
        struct FieldList* structure; // structure type
        struct {struct Type* ret; struct FieldList* param;} function; // function type
    } u;
};

struct FieldList{
    char* name;
    struct Type* type;
    struct FieldList* tail;
};

typedef struct SymbolTableNode{
    char* name;
    struct Type* type;
    struct SymbolTableNode* next;
}STNode;

#endif