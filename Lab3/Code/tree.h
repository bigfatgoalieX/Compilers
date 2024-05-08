// include guard
#ifndef TREE_H
#define TREE_H

#include "stdio.h"
#include "string.h"
#include "stdarg.h"
#include "stdlib.h"



typedef enum ASTNodeType{
    PROGRAM,
    EXTDEFLIST,
    EXTDEF,
    EXTDECLIST,
    SPECIFIER,
    STRUCTSPECIFIER,
    OPTTAG,
    TAG,
    VARDEC,
    FUNDEC,
    VARLIST,
    PARAMDEC,
    COMPST,
    STMTLIST,
    STMT,
    DEFLIST,
    DEF,
    DECLIST,
    DEC,
    EXP,
    ARGS,
    // above are types for nodes that are not leaves   aka non-terminals
    // below are types for the leaves    aka terminals            
    KEYWORD_PUNCTUATION, // ";", ",", "."
    KEYWORD_OPERATOR,    // "=", "+", "-", "*", "/", "||", "&&", "!"
    KEYWORD_RELOP,       // ">|<|>=|<=|==|!="
    KEYWORD_TYPE,         // "int", "float"
    KEYWORD_BRACKET,      // "()" "{}" "[]"
    KEYWORDS,            // "struct" "return" "if" "else" "while"
    INTNUMBER,           // like 2
    FLOATNUMBER,         // like 1.2
    ID_TYPE              // like "captain"
}NodeType;

typedef struct ASTNode
{
    NodeType type; //节点类型
    char type_name[32]; //类型名称

    struct ASTNode *first_child; //第一个子结点
    struct ASTNode *next_sib; //兄弟结点

    union{
        int intval;
        float floatval;
        char stringval[32];
    }data; //真实值存储于此，因为yylval要用来存一个ASTNODE结构体指针

    int lineno; //在源代码中的行号
}Node;

Node *bison_create_node(NodeType type, char* type_name);

void addchild(Node* father, int children_cnt, ...);

Node *flex_create_node(NodeType type, char* type_name, int line);

void preorder_traversal_AST(Node* root);

Node* get_child(Node* father, int n);
#endif