#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "tree.h"

#ifndef SEM_H
#define SEM_H


// typedef struct Type_* Type;
// typedef struct FieldList_* FieldList;
typedef struct Type_Sys
{
    enum{ 
    BASIC,
    ARRAY,
    STRUCTURE 
    }kind;
    // 根据kind的值去选择取union中的哪一个值
    union
    {
        // 基本类型 0 for int , 1 for float
        int basic;
        // 数组类型信息包括元素类型与数组大小构成
        struct {
            struct Type_Sys* elem; 
            int size; 
        } array;
        // 结构体类型信息是一个链表
        struct FieldList_* structure;
    } u;
}T;


typedef struct FieldList_
{
    char* name; // 域的名字
    struct Type_Sys* type; // 域的类型
    struct FieldList_* tail; // 下一个域
}F;

// Node of the list
typedef struct SymbolNode {
    char* name; // 标识符的名称
    T type; // 标识符的类型
    // 其他相关信息，如作用域等
    struct SymbolNode* next; // 指向下一个条目的指针
}ListNode;

void insertSymbol(char* name, T type, ListNode** tail);
ListNode* findSymbol(char* name, ListNode* head);
void ASTtraversal(struct ASTNode* root, ListNode* head, ListNode** ptail);
void fill_symboltable(struct ASTNode* astnode, ListNode** ptail);
void check_symboltable(struct ASTNode* astnode, ListNode* head);
void print_error(int error_type, int line);



#endif