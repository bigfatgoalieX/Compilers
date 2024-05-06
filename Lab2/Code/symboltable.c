#include "symboltable.h"

#define HASHSIZE 0x3fff

// global hashtable
STNode* symbolTable[HASHSIZE] = {NULL};
STNode* typeTable[HASHSIZE] = {NULL};

// find a symbol in the symbol table
STNode* findSymbol(char* name){
    unsigned int hashval = hash_pjw(name);
    STNode* p = symbolTable[hashval];
    while(p != NULL){
        if(strcmp(p->name, name) == 0){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

STNode* findType(char* name){
    unsigned int hashval = hash_pjw(name);
    STNode* p = typeTable[hashval];
    while(p != NULL){
        if(strcmp(p->name, name) == 0){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// insert a symbol into the symbol table
void insertSymbol(char* name, struct Type* type){
    unsigned int hashval = hash_pjw(name);
    STNode* p = symbolTable[hashval];
    STNode* new_node = (STNode*)malloc(sizeof(STNode));
    new_node->name = name;
    new_node->type = type;
    new_node->next = p;
    symbolTable[hashval] = new_node;
}

void insertType(char* name, struct Type* type){
    unsigned int hashval = hash_pjw(name);
    STNode* p = typeTable[hashval];
    STNode* new_node = (STNode*)malloc(sizeof(STNode));
    new_node->name = name;
    new_node->type = type;
    new_node->next = p;
    typeTable[hashval] = new_node;
}


void printSymbolTable(){
    for(int i = 0; i < HASHSIZE; i++){
        STNode* p = symbolTable[i];
        while(p != NULL){
            printf("name: %s, type: %d\n", p->name, p->type->kind);
            p = p->next;
        }
    }
}
// hash function
unsigned int hash_pjw(char* name)
{
    unsigned int val = 0, i;
    for (; *name; ++name)
    {
    val = (val << 2) + *name;
    if (i = val & ~0x3fff) val = (val ^ (i >> 12)) & 0x3fff;
    }
    return val;
} 