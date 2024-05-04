#include "semantic.h"


// Program -> ExtDefList
// ExtDefList -> ExtDef ExtDefList | ε
// ExtDef -> Specifier ExtDecList SEMI | Specifier SEMI | Specifier FunDec CompSt
// ExtDecList -> VarDec | VarDec COMMA ExtDecList

// Specifier -> TYPE | StructSpecifier
// StructSpecifier  -> STRUCT OptTag LC DefList RC | STRUCT Tag
// OptTag -> ID | ε 
// Tag -> ID

// VarDec -> ID | VarDec LB INT RB
// FunDec -> ID LP VarList RP | ID LP RP
// VarList -> ParamDec COMMA VarList | ParamDec
// ParamDec -> Specifier VarDec

// CompSt -> LC DefList StmtList RC
// StmtList -> Stmt StmtList | ε
// Stmt -> Exp SEMI | CompSt | RETURN Exp SEMI | IF LP Exp RP Stmt
// | IF LP Exp RP Stmt ELSE Stmt | WHILE Lp Exp RP Stmt

// DefList -> Def DefList | ε
// Def -> Specifier DecList SEMI
// DecList -> Dec | Dec COMMA DecList
// Dec -> VarDec | VarDec ASSIGNOP Exp

// Exp /* 包含二元运算符的表达式 */ 
// -> Exp ASSIGNOP Exp
// | Exp AND Exp
// | Exp OR Exp
// | Exp RELOP Exp
// | Exp PLUS Exp
// | Exp MINUS Exp
// | Exp STAR Exp
// | Exp DIV Exp
// /* 包含一元运算符的表达式 */ 
// | LP Exp RP
// | MINUS Exp
// | NOT Exp
// /* 不包含运算符但又比较特殊的表达式 */ 
// | ID LP Args RP
// | ID LP RP
// | Exp LB Exp RB
// | Exp DOT ID
// /* 最基本的表达式 */ 
// | ID
// | INT
// | FLOAT
// /* 实参列表 */
// Args -> Exp COMMA Args | Exp

void semantic_analysis(struct ASTNode* node){
    if(node == NULL){
        return;
    }
    Program_check(node);
}

void Program_check(struct ASTNode* node){
    // Program -> ExtDefList
    if(node == NULL){
        return;
    }
    ExtDefList_check(get_child(node, 0));
}

void ExtDefList_check(struct ASTNode* node){
    // ExtDefList -> ExtDef ExtDefList | ε
    if(node == NULL){
        return;
    }
    ExtDef_check(get_child(node, 0));
    ExtDefList_check(get_child(node, 1));
}

void ExtDef_check(struct ASTNode* node){
    // ExtDef -> Specifier ExtDecList SEMI | Specifier SEMI | Specifier FunDec CompSt
    if(node == NULL){
        return;
    }
    struct ASTNode* tmp_child = get_child(node, 0);

    if(strcmp(tmp_child->type_name, "Specifier") == 0){
        struct ASTNode* tmp_child2 = get_child(node, 1);
        if(strcmp(tmp_child2->type_name, "ExtDecList") == 0){
            ExtDecList_check(tmp_child2);
        }else if(strcmp(tmp_child2->type_name, "SEMI") == 0){
            // do nothing
        }else{
            FunDec_check(tmp_child2);
            CompSt_check(get_child(node, 2));
        }
    }
    else{
        printf("error: at ExtDef_check\n");
    }
}

void ExtDecList_check(struct ASTNode* node){
    // ExtDecList -> VarDec | VarDec COMMA ExtDecList
    if(node == NULL){
        return;
    }
    VarDec_check(get_child(node, 0));

    struct ASTNode* tmp_child = get_child(node, 1);
    if(strcmp(tmp_child->type_name, "COMMA") == 0){
        ExtDecList_check(get_child(node, 2));
    }
}

void Specifier_check(struct ASTNode* node){
    // Specifier -> TYPE | StructSpecifier
    if(node == NULL){
        return;
    }
    struct ASTNode* tmp_child = get_child(node, 0);
    if(strcmp(tmp_child->type_name, "TYPE") == 0){
        // do nothing
    }else{
        StructSpecifier_check(tmp_child);
    }
}

void StructSpecifier_check(struct ASTNode* node){
    // StructSpecifier  -> STRUCT OptTag LC DefList RC | STRUCT Tag
    if(node == NULL){
        return;
    }
    struct ASTNode* tmp_child = get_child(node, 0);
    if(strcmp(tmp_child->type_name, "STRUCT") == 0){
        struct ASTNode* tmp_child2 = get_child(node, 1);
        if(strcmp(tmp_child2->type_name, "OptTag") == 0){
            OptTag_check(tmp_child2);
            DefList_check(get_child(node, 3));
        }
        else{
            Tag_check(get_child(node, 1));
        }
    }
    else{
        printf("error: at StructSpecifier_check\n");
    }
}

void OptTag_check(struct ASTNode* node){
    // OptTag -> ID | ε 
    if(node == NULL){
        return;
    }
}

void Tag_check(struct ASTNode* node){
    // Tag -> ID
    if(node == NULL){
        return;
    }
}

void VarDec_check(struct ASTNode* node){
    // VarDec -> ID | VarDec LB INT RB
    if(node == NULL){
        return;
    }
    struct ASTNode* tmp_child = get_child(node, 0);
    if(strcmp(tmp_child->type_name, "ID") == 0){
        // deal with ID here
    }else{
        VarDec_check(get_child(node, 0));
        // deal with array here
    }
}

void FunDec_check(struct ASTNode* node){
    // FunDec -> ID LP VarList RP | ID LP RP
    if(node == NULL){
        return;
    }
    struct ASTNode* tmp_child = get_child(node, 0);
    if(strcmp(tmp_child->type_name, "ID") == 0){
        // deal with function here
        struct ASTNode* tmp_child2 = get_child(node, 2);
        if(strcmp(tmp_child2->type_name, "VarList") == 0){
            VarList_check(tmp_child2);
        }
    }else{
        printf("error: at FunDec_check\n");
    }
}

void VarList_check(struct ASTNode* node){
    // VarList -> ParamDec COMMA VarList | ParamDec
    if(node == NULL){
        return;
    }
    ParamDec_check(get_child(node, 0));
    struct ASTNode* tmp_child = get_child(node, 1);
    if(strcmp(tmp_child->type_name, "COMMA") == 0){
        VarList_check(get_child(node, 2));
    }
}

void ParamDec_check(struct ASTNode* node){
    // ParamDec -> Specifier VarDec
    if(node == NULL){
        return;
    }
    Specifier_check(get_child(node, 0));
    VarDec_check(get_child(node, 1));
}

void CompSt_check(struct ASTNode* node){
    // CompSt -> LC DefList StmtList RC
    if(node == NULL){
        return;
    }
    DefList_check(get_child(node, 1));
    StmtList_check(get_child(node, 2));
}

void StmtList_check(struct ASTNode* node){
    // StmtList -> Stmt StmtList | ε
    if(node == NULL){
        return;
    }
    Stmt_check(get_child(node, 0));
    StmtList_check(get_child(node, 1));
}

void Stmt_check(struct ASTNode* node){
    // Stmt -> Exp SEMI | CompSt | RETURN Exp SEMI | IF LP Exp RP Stmt
    // | IF LP Exp RP Stmt ELSE Stmt | WHILE Lp Exp RP Stmt
    if(node == NULL){
        return;
    }
    struct ASTNode* tmp_child = get_child(node, 0);
    if(strcmp(tmp_child->type_name, "Exp") == 0){
        // do nothing
    }else if(strcmp(tmp_child->type_name, "CompSt") == 0){
        CompSt_check(tmp_child);
    }else if(strcmp(tmp_child->type_name, "RETURN") == 0){
        // do nothing
    }else if(strcmp(tmp_child->type_name, "IF") == 0){
        // do nothing
    }else if(strcmp(tmp_child->type_name, "WHILE") == 0){
        // do nothing
    }else{
        printf("error: at Stmt_check\n");
    }
}

void DefList_check(struct ASTNode* node){
    // DefList -> Def DefList | ε
    if(node == NULL){
        return;
    }
    Def_check(get_child(node, 0));
    DefList_check(get_child(node, 1));
}

void Def_check(struct ASTNode* node){
    // Def -> Specifier DecList SEMI
    if(node == NULL){
        return;
    }
    Specifier_check(get_child(node, 0));
    DecList_check(get_child(node, 1));
}

void DecList_check(struct ASTNode* node){
    // DecList -> Dec | Dec COMMA DecList
    if(node == NULL){
        return;
    }
    Dec_check(get_child(node, 0));
    struct ASTNode* tmp_child = get_child(node, 1);
    if(strcmp(tmp_child->type_name, "COMMA") == 0){
        DecList_check(get_child(node, 2));
    }
}

void Dec_check(struct ASTNode* node){
    // Dec -> VarDec | VarDec ASSIGNOP Exp
    if(node == NULL){
        return;
    }
    struct ASTNode* tmp_child = get_child(node, 0);
    if(strcmp(tmp_child->type_name, "VarDec") == 0){
        VarDec_check(tmp_child);
    }else{
        // do nothing
    }
}

void Exp_check(struct ASTNode* node){
    // Exp -> Exp ASSIGNOP Exp
    // | Exp AND Exp
    // | Exp OR Exp
    // | Exp RELOP Exp
    // | Exp PLUS Exp
    // | Exp MINUS Exp
    // | Exp STAR Exp
    // | Exp DIV Exp
    // | LP Exp RP
    // | MINUS Exp
    // | NOT Exp
    // | ID LP Args RP
    // | ID LP RP
    // | Exp LB Exp RB
    // | Exp DOT ID
    // | ID
    // | INT
    // | FLOAT
    // Args -> Exp COMMA Args | Exp
    if(node == NULL){
        return;
    }
    struct ASTNode* tmp_child = get_child(node, 0);
    if(strcmp(tmp_child->type_name, "Exp") == 0){
        // do nothing
    }else if(strcmp(tmp_child->type_name, "LP") == 0){
        // do nothing
    }else if(strcmp(tmp_child->type_name, "MINUS") == 0){
        // do nothing
    }else if(strcmp(tmp_child->type_name, "NOT") == 0){
        // do nothing
    }else if(strcmp(tmp_child->type_name, "ID") == 0){
        // do nothing
    }else if(strcmp(tmp_child->type_name, "INT") == 0){
        // do nothing
    }else if(strcmp(tmp_child->type_name, "FLOAT") == 0){
        // do nothing
    }else{
        printf("error: at Exp_check\n");
    }
}



