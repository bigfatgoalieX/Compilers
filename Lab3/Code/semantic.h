//include "tree.h"
#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "tree.h"
#include "symboltable.h"

void semantic_analysis(struct ASTNode* node);
void Program_check(struct ASTNode* node);
void ExtDefList_check(struct ASTNode* node);
void ExtDef_check(struct ASTNode* node);
void ExtDecList_check(struct ASTNode* node, struct Type* type);

struct Type* Specifier_check(struct ASTNode* node);
struct Type* StructSpecifier_check(struct ASTNode* node);
char* OptTag_check(struct ASTNode* node);
char* Tag_check(struct ASTNode* node);

void VarDec_check(struct ASTNode* node, struct Type* type);
char* VarDec_name_check(struct ASTNode* node);
struct Type* VarDec_type_check(struct ASTNode* node, struct Type* type);

void FunDec_check(struct ASTNode* node, struct Type* ret_type);
struct FieldList* VarList_check(struct ASTNode* node);
struct FieldList* ParamDec_check(struct ASTNode* node);

void CompSt_check(struct ASTNode* node);
void StmtList_check(struct ASTNode* node);
void Stmt_check(struct ASTNode* node);

// for usual:一般情况下，比如函数里面的DefList并不需要返回值，只需要加入符号表即可
void DefList_check_easy(struct ASTNode* node);
void Def_check_easy(struct ASTNode* node);
void DecList_check_easy(struct ASTNode* node, struct Type* type);
void Dec_check_easy(struct ASTNode* node, struct Type* type);

// for struct: 结构体类型内部的DefList是要返回指针从而将不同的域连接起来的
struct FieldList* DefList_check(struct ASTNode* node);
struct FieldList* Def_check(struct ASTNode* node);
struct FieldList* DecList_check(struct ASTNode* node, struct Type* type);
struct FieldList* Dec_check(struct ASTNode* node, struct Type* type);

void Exp_check(struct ASTNode* node);
void Args_check(struct ASTNode* node);

#endif