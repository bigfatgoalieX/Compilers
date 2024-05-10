#include "intercode_gen.h"
int var_no = 0;
int temp_no = 0;
int label_no = 0;

#define DEBUG_MODE

void generate_InterCode(struct ASTNode* node, FILE* fp){
    #ifdef DEBUG_MODE
    printf("debuginfo: reach generate_InterCode.\n");
    #endif
    if(node == NULL){
        return;
    }
    Program_gen(node);
    fPrintInterCode(fp);
    return;
}
void Program_gen(struct ASTNode* node){
    // Program -> ExtDefList
    #ifdef DEBUG_MODE
    printf("debuginfo: reach Program_gen.\n");
    #endif
    if(node == NULL){
        return;
    }
    ExtDefList_gen(get_child(node, 0));
    return;
}
void ExtDefList_gen(struct ASTNode* node){
    // ExtDefList -> ExtDef ExtDefList | ε
    #ifdef DEBUG_MODE
    printf("debuginfo: reach ExtDefList_gen.\n");
    #endif
    if(node == NULL){
        return;
    }
    ExtDef_gen(get_child(node, 0));
    ExtDefList_gen(get_child(node, 1));
    return;
}
void ExtDef_gen(struct ASTNode* node){
    // ExtDef -> Specifier ExtDecList SEMI | Specifier SEMI | Specifier FunDec CompSt
    #ifdef DEBUG_MODE
    printf("debuginfo: reach ExtDef_gen.\n");
    #endif
    if(node == NULL){
        return;
    }
    struct ASTNode* child0 = get_child(node, 0);
    struct ASTNode* child1 = get_child(node, 1);
    struct ASTNode* child2 = get_child(node, 2);
    if(strcmp(child1->type_name, "ExtDecList") == 0){
        // ExtDef -> Specifier ExtDecList SEMI\
        // nothing to do
        return;
    }
    else if(strcmp(child1->type_name, "SEMI") == 0){
        // ExtDef -> Specifier SEMI
        return;
    }
    else if(strcmp(child1->type_name, "FunDec") == 0){
        // ExtDef -> Specifier FunDec CompSt
        FunDec_gen(child1);
        CompSt_gen(child2);
    }
    return;
}
void FunDec_gen(struct ASTNode* node){
    // FunDec -> ID LP VarList RP | ID LP RP
    #ifdef DEBUG_MODE
    printf("debuginfo: reach FunDec_gen.\n");
    #endif

    if(node == NULL){
        return;
    }
    // deal with FUNCTION_INTERCODE
    struct ASTNode* function_name = get_child(node, 0);
    STNode* my_function = findSymbol(function_name->data.stringval);

    if(my_function == NULL){
        printf("Undefined function!\n");
        return;
    }
    struct Operand* op = Operand_Init(FUNCTION_OPERAND, my_function->name);
    struct InterCode* intercode = InterCode_Init(FUNCTION_INTERCODE, 1, op);
    InsertInterCodeNode(intercode);

    // deal with PARAM_INTERCODE
    // attention: the param info is all in STNODE
    struct FieldList* param = my_function->type->u.function.param;
    while(param != NULL){
        var_no++;
        struct Operand* op = Operand_Init(VARIABLE_OPERAND, var_no);
        struct InterCode* intercode = InterCode_Init(PARAM_INTERCODE, 1, op);
        InsertInterCodeNode(intercode);
        param = param->tail;
    }
    return;
}
void CompSt_gen(struct ASTNode* node){
    // CompSt -> LC DefList StmtList RC
    #ifdef DEBUG_MODE
    printf("debuginfo: reach CompSt_gen.\n");
    #endif
    if(node == NULL){
        return;
    }
    // 注意语法树上可能根本没有DefList结点,也可能没有StmtList结点！！！
    // 故此处需要额外判断，一共是2*2 = 4种情况！！！
    struct ASTNode* tmp_child = get_child(node,1);
    if(strcmp(tmp_child -> type_name, "DefList") == 0){
        DefList_gen(get_child(node, 1));
        if(strcmp(get_child(node, 2) -> type_name, "StmtList") == 0){
            StmtList_gen(get_child(node, 2));
        }
        else{
            // do nothing
        }
    }
    else if(strcmp(tmp_child -> type_name, "StmtList") == 0){
        StmtList_gen(get_child(node, 1));
    }
    else{
        // do nothing
    }
    return;
}