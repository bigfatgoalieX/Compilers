#include "tree.h"
#include "symboltable.h"

void semantic_analysis(struct ASTNode* node);
void Program_check(struct ASTNode* node);
void ExtDefList_check(struct ASTNode* node);
void ExtDef_check(struct ASTNode* node);
void ExtDecList_check(struct ASTNode* node);
struct Type* Specifier_check(struct ASTNode* node);
struct Type* StructSpecifier_check(struct ASTNode* node);
char* OptTag_check(struct ASTNode* node);
char* Tag_check(struct ASTNode* node);
void VarDec_check(struct ASTNode* node);
void FunDec_check(struct ASTNode* node);
void VarList_check(struct ASTNode* node);
void ParamDec_check(struct ASTNode* node);
void CompSt_check(struct ASTNode* node);
void StmtList_check(struct ASTNode* node);
void Stmt_check(struct ASTNode* node);
void DefList_check(struct ASTNode* node);
void Def_check(struct ASTNode* node);
void DecList_check(struct ASTNode* node);
void Dec_check(struct ASTNode* node);
void Exp_check(struct ASTNode* node);
void Args_check(struct ASTNode* node);
