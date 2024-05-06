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

struct FieldList* DefList_check(struct ASTNode* node);
struct FieldList* Def_check(struct ASTNode* node);
struct FieldList* DecList_check(struct ASTNode* node, struct Type* type);
struct FieldList* Dec_check(struct ASTNode* node, struct Type* type);

void Exp_check(struct ASTNode* node);
void Args_check(struct ASTNode* node);
