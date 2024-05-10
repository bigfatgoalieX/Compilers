// include guard
#ifndef INTERCODE_GEN
#define INTERCODE_GEN

#include "intercode_utils.h"
void generate_InterCode(struct ASTNode* node, FILE* fp);
void Program_gen(struct ASTNode* node);
void ExtDefList_gen(struct ASTNode* node);
void ExtDef_gen(struct ASTNode* node);
void FunDec_gen(struct ASTNode* node);
void CompSt_gen(struct ASTNode* node);
#endif