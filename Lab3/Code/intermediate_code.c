// generate intermediate code based on syntax analysis and semantic analysis
#include "intermediate_code.h"
void generate_InterCode(struct ASTNode* node){
    printf("debuginfo: reach generate_InterCode.\n");
    if(node == NULL){
        return;
    }
    Program_gen(node);
}
void Program_gen(struct ASTNode* node){
    printf("debuginfo: reach Program_gen.\n");
    if(node == NULL){
        return;
    }
    ExtDefList_gen(node->child);
}
void ExtDefList_gen(struct ASTNode* node){
    printf("debuginfo: reach ExtDefList_gen.\n");
    if(node == NULL){
        return;
    }
    ExtDef_gen(node->child);
    ExtDefList_gen(node->child->next);
}
void ExtDef_gen(struct ASTNode* node){
    printf("debuginfo: reach ExtDef_gen.\n");
    if(node == NULL){
        return;
    }
    if(strcmp(node->child->next->name, "ExtDecList") == 0){
        ExtDecList_gen(node->child->next);
    }
    else if(strcmp(node->child->next->name, "FunDec") == 0){
        FunDec_gen(node->child->next);
        CompSt_gen(node->child->next->next);
    }
}
void ExtDecList_gen(struct ASTNode* node){
    printf("debuginfo: reach ExtDecList_gen.\n");
    if(node == NULL){
        return;
    }
    VarDec_gen(node->child);
}
void FunDec_gen(struct ASTNode* node){
    printf("debuginfo: reach FunDec_gen.\n");
    if(node == NULL){
        return;
    }
    Operand* func = (Operand*)malloc(sizeof(Operand));
    func->kind = FUNCTION;
    func->u.func_name = node->child->text;
    InterCode* code = (InterCode*)malloc(sizeof(InterCode));
    code->kind = FUNCTION_INTERCODE;
    code->u.unary.result = func;
    insert_InterCode(code);
    if(strcmp(node->child->next->next->name, "VarList") == 0){
        VarList_gen(node->child->next->next);
    }
}
void VarList_gen(struct ASTNode* node){
    printf("debuginfo: reach VarList_gen.\n");
    if(node == NULL){
        return;
    }
    ParamDec_gen(node->child);
    if(node->child->next != NULL){
        VarList_gen(node->child->next->next);
    }
}
void ParamDec_gen(struct ASTNode* node){
    printf("debuginfo: reach ParamDec_gen.\n");
    if(node == NULL){
        return;
    }
    VarDec_gen(node->child->next);
}
void CompSt_gen(struct ASTNode* node){
    printf("debuginfo: reach CompSt_gen.\n");
    if(node == NULL){
        return;
    }
    DefList_gen(node->child->next);
    StmtList_gen(node->child->next->next);
}
void StmtList_gen(struct ASTNode* node){
    printf("debuginfo: reach StmtList_gen.\n");
    if(node == NULL){
        return;
    }
    Stmt_gen(node->child);
    StmtList_gen(node->child->next);
}
void Stmt_gen(struct ASTNode* node){
    printf("debuginfo: reach Stmt_gen.\n");
    if(node == NULL){
        return;
    }
    if(strcmp(node->child->name, "Exp") == 0){
        Exp_gen(node->child);
    }
    else if(strcmp(node->child->name, "CompSt") == 0){
        CompSt_gen(node->child);
    }
    else if(strcmp(node->child->name, "RETURN") == 0){
        Operand* t1 = Exp_gen(node->child->next);
        InterCode* code = (InterCode*)malloc(sizeof(InterCode));
        code->kind = RETURN_INTERCODE;
        code->u.unary.result = t1;
        insert_InterCode(code);
    }
    else if(strcmp(node->child->name, "IF") == 0){
        Operand* label1 = new_label();
        Operand* label2 = new_label();
        Cond_gen(node->child->next->next->next, label1, label2);
        InterCode* code1 = (InterCode*)malloc(sizeof(InterCode));
        code1->kind = LABEL_INTERCODE;
        code1->u.unary.result = label1;
        insert_InterCode(code1);
        Stmt_gen(node->child->next->next->next->next->next);
        InterCode* code2 = (InterCode*)malloc(sizeof(InterCode));
        code2->kind = LABEL_INTERCODE;
        code2->u.unary.result = label2;
        insert_InterCode(code2);
    }
    else if(strcmp(node->child->name, "WHILE") == 0){
        Operand* label1 = new_label();
        Operand* label2 = new_label();
        Operand* label3 = new_label();
        InterCode* code1 = (InterCode*)malloc(sizeof(InterCode));
        code1->kind = LABEL_INTERCODE;
        code1->u.unary.result = label1;
        insert_InterCode(code1);
        Cond_gen(node->child->next->next, label2, label3);
        InterCode* code2 = (InterCode*)malloc(sizeof(InterCode));
        code2->kind = LABEL_INTERCODE;
        code2->u.unary.result = label2;
        insert_InterCode(code2);
        Stmt_gen(node->child->next->next->next->next);
        InterCode* code = (InterCode*)malloc(sizeof(InterCode));
        code->kind = GOTO_INTERCODE;
        code->u.unary.result = label1;
        insert_InterCode(code);
        InterCode* code3 = (InterCode*)malloc(sizeof(InterCode));
        code3->kind = LABEL_INTERCODE;
        code3->u.unary.result = label3;
        insert_InterCode(code3);
    }
}
void DefList_gen(struct ASTNode* node){
    printf("debuginfo: reach DefList_gen.\n");
    if(node == NULL){
        return;
    }
    Def_gen(node->child);
    DefList_gen(node->child->next);
}
void Def_gen(struct ASTNode* node){
    printf("debuginfo: reach Def_gen.\n");
    if(node == NULL){
        return;
    }
    DecList_gen(node->child->next);
}
void DecList_gen(struct ASTNode* node){
    printf("debuginfo: reach DecList_gen.\n");
    if(node == NULL){
        return;
    }
    Dec_gen(node->child);
    if(node->child->next != NULL){
        DecList_gen(node->child->next->next);
    }
}
void Dec_gen(struct ASTNode* node){
    printf("debuginfo: reach Dec_gen.\n");
    if(node == NULL){
        return;
    }
    VarDec_gen(node->child);
}
