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
            struct type* type = Specifier_check(tmp_child);
            ExtDecList_check(tmp_child2,type);
        }
        else if(strcmp(tmp_child2->type_name, "SEMI") == 0){
            // add the struct into the typetable
            if(Specifier_check(tmp_child) -> kind == STRUCTURE){
                insertType(Specifier_check(tmp_child) -> u.structure -> name, Specifier_check(tmp_child));
            }
            else{
                //do nothing
            }
        }
        else{
            struct type* type = Specifier_check(tmp_child);
            FunDec_check(tmp_child2,type);
            CompSt_check(get_child(node, 2));
        }
    }
    else{
        printf("error: at ExtDef_check\n");
    }
}

void ExtDecList_check(struct ASTNode* node, struct Type* type){
    // ExtDecList -> VarDec | VarDec COMMA ExtDecList
    if(node == NULL){
        return;
    }
    VarDec_check(get_child(node, 0),type);

    struct ASTNode* tmp_child = get_child(node, 1);
    if(strcmp(tmp_child->type_name, "COMMA") == 0){
        ExtDecList_check(get_child(node, 2),type);
    }
}

struct Type* Specifier_check(struct ASTNode* node){
    // Specifier -> TYPE | StructSpecifier
    if(node == NULL){
        return NULL;
    }

    struct ASTNode* tmp_child = get_child(node, 0);

    struct Type* type = (struct Type*)malloc(sizeof(struct Type));

    if(strcmp(tmp_child->type_name, "TYPE") == 0){
        type->kind = BASIC;
        if(strcmp(tmp_child->data.stringval, "int") == 0){
            type->u.basic = 0;
        }else{
            type->u.basic = 1;
        }
    }else{
        type = StructSpecifier_check(tmp_child);
    }

    return type;
}

struct Type* StructSpecifier_check(struct ASTNode* node){
    // StructSpecifier  -> STRUCT OptTag LC DefList RC | STRUCT Tag
    if(node == NULL){
        return NULL;
    }
    struct ASTNode* tmp_child = get_child(node, 0);

    struct Type* type = (struct Type*)malloc(sizeof(struct Type));
    struct FieldList* structure = (struct FieldList*)malloc(sizeof(struct FieldList));

    if(strcmp(tmp_child->type_name, "STRUCT") == 0){
        type -> kind = STRUCTURE;
        struct ASTNode* tmp_child2 = get_child(node, 1);
        if(strcmp(tmp_child2->type_name, "OptTag") == 0){
            // also need to insert the symbol into the symboltable
            structure -> name = OptTag_check(tmp_child2);
            // 由于我们设置DefList_check返回类型是FieldList*,所以type的两个域要分别填写
            structure -> type->kind = STRUCTURE;
            structure -> type->u.structure = DefList_check(get_child(node, 3));
            structure -> tail = NULL;
            type -> u.structure = structure;
        }
        else{
            // find the symbol in the symboltable
            STNode* stnode = findType(Tag_check(get_child(node, 1)));
            if(stnode != NULL){
                type = stnode -> type;
            }
        }
    }
    else{
        printf("error: at StructSpecifier_check\n");
    }

    return type;
}

char* OptTag_check(struct ASTNode* node){
    // OptTag -> ID | ε 
    if(node == NULL){
        return NULL;
    }

    char* name = (char*)malloc(sizeof(char)*32);
    if(get_child(node, 0) == NULL){
        printf("there is an anonymous struct\n");
        return NULL;
    }
    name = get_child(node, 0) -> data.stringval;
    return name;
}

char* Tag_check(struct ASTNode* node){
    // Tag -> ID
    if(node == NULL){
        return NULL;
    }

    char* name = (char*)malloc(sizeof(char)*32);
    name = get_child(node, 0)->data.stringval;
    return name;
}

void VarDec_check(struct ASTNode* node, struct Type* type){
    // VarDec -> ID | VarDec LB INT RB
    if(node == NULL){
        return;
    }
    struct ASTNode* tmp_child = get_child(node, 0);
    if(strcmp(tmp_child->type_name, "ID") == 0){
        // deal with ID here
        insertSymbol(tmp_child->data.stringval, type);
    }
    else{
        // deal with array here
        insertSymbol(VarDec_name_check(tmp_child), VarDec_type_check(tmp_child, type));
    }
}

char* VarDec_name_check(struct ASTNode* node){
    // VarDec -> ID | VarDec LB INT RB
    if(node == NULL){
        return NULL;
    }
    struct ASTNode* tmp_child = get_child(node, 0);
    if(strcmp(tmp_child->type_name, "ID") == 0){
        return tmp_child->data.stringval;
    }
    else{
        return VarDec_name_check(get_child(node, 0));
    }
}

struct Type* VarDec_type_check(struct ASTNode* node, struct Type* type){
    // VarDec -> ID | VarDec LB INT RB
    if(node == NULL){
        return NULL;
    }

    struct ASTNode* tmp_child = get_child(node, 0);
    if(strcmp(tmp_child->type_name, "ID") == 0){
        // deal with ID here
        return type;
    }else{
        // deal with array here
        struct Type* type = (struct Type*)malloc(sizeof(struct Type));
        type -> kind = ARRAY;
        type -> u.array.elem = VarDec_type_check(tmp_child, type);
        type -> u.array.size = get_child(node, 2)->data.intval;
    }
}

void FunDec_check(struct ASTNode* node, struct Type* ret_type){
    // FunDec -> ID LP VarList RP | ID LP RP
    if(node == NULL){
        return;
    }
    struct ASTNode* tmp_child = get_child(node, 0);

    if(strcmp(tmp_child->type_name, "ID") == 0){
        // deal with function here
        struct ASTNode* tmp_child2 = get_child(node, 2);

        if(strcmp(tmp_child2->type_name, "VarList") == 0){
            struct Type* type = (struct Type*)malloc(sizeof(struct Type));
            type -> kind = FUNCTION;
            type -> u.function.ret = ret_type;
            type -> u.function.param = VarList_check(tmp_child2);
            insertSymbol(tmp_child->data.stringval, type);
        }
        else{
            struct Type* type = (struct Type*)malloc(sizeof(struct Type));
            type -> kind = FUNCTION;
            type -> u.function.ret = ret_type;
            type -> u.function.param = NULL;
            insertSymbol(tmp_child->data.stringval, type);
        }
    }
    else{
        printf("error: at FunDec_check\n");
    }
}

struct FieldList* VarList_check(struct ASTNode* node){
    // VarList -> ParamDec COMMA VarList | ParamDec
    if(node == NULL){
        return;
    }
    
    struct ASTNode* tmp_child = get_child(node, 1);
    
    struct FieldList* tmp = (struct FieldList*)malloc(sizeof(struct FieldList));
    if(strcmp(tmp_child->type_name, "COMMA") == 0){
        tmp -> name = ParamDec_check(get_child(node, 0)) -> name;
        tmp -> type = ParamDec_check(get_child(node, 0)) -> type;
        tmp -> tail = VarList_check(get_child(node, 2));
    }
    else{
        tmp = ParamDec_check(get_child(node, 0));
    }

    return tmp;
}

struct FieldList* ParamDec_check(struct ASTNode* node){
    // ParamDec -> Specifier VarDec
    if(node == NULL){
        return;
    }
    struct FieldList* tmp = (struct FieldList*)malloc(sizeof(struct FieldList));
    struct Type* type = Specifier_check(get_child(node, 0));

    tmp -> name = VarDec_name_check(get_child(node, 1));
    tmp -> type = VarDec_type_check(get_child(node, 1),type);
    tmp -> tail = NULL;

    return tmp;
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

struct FieldList* DefList_check(struct ASTNode* node){
    // DefList -> Def DefList | ε
    if(node == NULL){
        return NULL;
    }
    if(get_child(node, 0) == NULL){
        printf("DefList is empty\n");
        return NULL;
    }
    
    struct FieldList* structure = (struct FieldList*)malloc(sizeof(struct FieldList));
    struct FieldList* tmp = Def_check(get_child(node, 0));
    structure -> name = tmp -> name;
    structure -> type = tmp -> type;
    structure -> tail = DefList_check(get_child(node, 1));

    return structure;
}

struct FieldList* Def_check(struct ASTNode* node){
    // Def -> Specifier DecList SEMI
    if(node == NULL){
        return NULL;
    }
    // struct FieldList* structure = (struct FieldList*)malloc(sizeof(struct FieldList));
    struct Type* type = Specifier_check(get_child(node, 0));
    struct FieldList* tmp = DecList_check(get_child(node, 1), type);
    // structure -> name = tmp -> name;
    // structure -> type = type;
    // structure -> tail = tmp;

    return tmp;
}

struct FieldList* DecList_check(struct ASTNode* node, struct Type* type){
    // DecList -> Dec | Dec COMMA DecList
    if(node == NULL){
        return NULL;
    }

    struct FieldList* structure = (struct FieldList*)malloc(sizeof(struct FieldList));
    struct FieldList* tmp = Dec_check(get_child(node, 0), type);
    structure -> name = tmp -> name;
    structure -> type = tmp -> type;
    // if-else here is actually unnecessary
    if(strcmp(get_child(node, 1)->type_name, "COMMA") == 0){
        structure -> tail = DecList_check(get_child(node, 2), type);
    }
    else{
        structure -> tail = NULL;
    }

    return structure;
}

struct FieldList* Dec_check(struct ASTNode* node, struct Type* type){
    // Dec -> VarDec | VarDec ASSIGNOP Exp
    if(node == NULL){
        return NULL;
    }
    struct FieldList* structure = (struct FieldList*)malloc(sizeof(struct FieldList));
    // fetch name and type separately from VarDec
    structure -> name = VarDec_name_check(get_child(node, 0));
    structure -> type = VarDec_type_check(get_child(node, 0),type);
    structure -> tail = NULL;

    return structure;
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

void Args_check(struct ASTNode* node){
    // Args -> Exp COMMA Args | Exp
    if(node == NULL){
        return;
    }
    Exp_check(get_child(node, 0));
    struct ASTNode* tmp_child = get_child(node, 1);
    if(strcmp(tmp_child->type_name, "COMMA") == 0){
        Args_check(get_child(node, 2));
    }
}


