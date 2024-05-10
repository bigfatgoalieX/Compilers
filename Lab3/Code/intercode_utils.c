// generate intermediate code based on syntax analysis and semantic analysis
#include "intercode_utils.h"
// global list head
struct InterCodeNode* headnode = NULL;

// 创建一个操作数
struct Operand* Operand_Init(int kind, ...){
    va_list args;
    va_start(args, 1);

    struct Operand* op_created = (struct Operand*)malloc(sizeof(struct Operand));
    op_created -> kind = kind;
    switch(kind){
        case VARIABLE_OPERAND:{
            op_created -> u.var_no = va_arg(args, int);
            break;
        }
        case CONSTANT_OPERAND:
        case FUNCTION_OPERAND:{
            op_created -> u.func_name = va_arg(args, char*);
            break;
        }
        case TEMPVAR_OPERAND:
        case LABEL_OPERAND:
        default:
            break;
    }
    va_end(args);

    return op_created;
}
// 创建一个中间代码
struct InterCode* InterCode_Init(int kind, int operand_no, ...){
    va_list args;
    va_start(args, operand_no);

    struct InterCode* code_created = (struct InterCode*)malloc(sizeof(struct InterCode));
    code_created -> kind = kind;
    switch(kind){
        case FUNCTION_INTERCODE:
        case PARAM_INTERCODE:
        case RETURN_INTERCODE:
        case ARG_INTERCODE:
        case LABEL_INTERCODE:
        case GOTO_INTERCODE:
        case READ_INTERCODE:
        case WRITE_INTERCODE:{
            code_created -> u.unary.result = va_arg(args, struct Operand*);
            break;
        }
        case ASSIGN_INTERCODE:
        case DEC_INTERCODE:
        case CALL_INTERCODE:{
            code_created -> u.binary.left = va_arg(args, struct Operand*);
            code_created -> u.binary.right = va_arg(args, struct Operand*);
            break;
        }
        case ADD_INTERCODE:
        case SUB_INTERCODE:
        case MUL_INTERCODE:
        case DIV_INTERCODE:{
            code_created -> u.ternary.result = va_arg(args, struct Operand*);
            code_created -> u.ternary.op1 = va_arg(args, struct Operand*);
            code_created -> u.ternary.op2 = va_arg(args, struct Operand*);
            break;
        }
        case IFGOTO_INTERCODE:{
            code_created -> u.quaternary.op1 = va_arg(args, struct Operand*);
            code_created -> u.quaternary.op2 = va_arg(args, struct Operand*);
            code_created -> u.quaternary.op3 = va_arg(args, struct Operand*);
            code_created -> u.quaternary.relop = va_arg(args, char*);
            break;
        }
        default:
            break;
    }
    va_end(args);

    return code_created;
}
// 插入一个中间代码节点到全局链表中
void InsertInterCodeNode(struct InterCode* code){
    struct InterCodeNode* newnode = (struct InterCodeNode*)malloc(sizeof(struct InterCodeNode));
    newnode -> code = code;
    newnode -> prev = NULL;
    newnode -> next = NULL;
    if(headnode == NULL){
        headnode = newnode;
    }
    else{
        struct InterCodeNode* p = headnode;
        while(p -> next != NULL){
            p = p -> next;
        }
        p -> next = newnode;
        newnode -> prev = p;
    }
}


// 遍历链表，把中间代码打印到一个文件里
void fPrintInterCode(FILE* fp){
    if(fp == NULL){
        printf("Error: cannot open file intercode.txt\n");
        return;
    }
    struct InterCodeNode* p = headnode;
    while(p != NULL){
        struct InterCode* code = p -> code;
        switch(code -> kind){
            case FUNCTION_INTERCODE:{
                fprintf(fp, "FUNCTION %s :\n", code -> u.unary.result -> u.func_name);
                break;
            }
            case PARAM_INTERCODE:{
                fprintf(fp, "PARAM v%d\n", code -> u.unary.result -> u.var_no);
                break;
            }
            case RETURN_INTERCODE:{
                fprintf(fp, "RETURN %d\n", code -> u.unary.result -> u.var_no);
                break;
            }
            case ARG_INTERCODE:{
                fprintf(fp, "ARG %d\n", code -> u.unary.result -> u.var_no);
                break;
            }
            case LABEL_INTERCODE:{
                fprintf(fp, "LABEL %d :\n", code -> u.unary.result -> u.var_no);
                break;
            }
            case GOTO_INTERCODE:{
                fprintf(fp, "GOTO %d\n", code -> u.unary.result -> u.var_no);
                break;
            }
            case READ_INTERCODE:{
                fprintf(fp, "READ %d\n", code -> u.unary.result -> u.var_no);
                break;
            }
            case WRITE_INTERCODE:{
                fprintf(fp, "WRITE %d\n", code -> u.unary.result -> u.var_no);
                break;
            }
            case ASSIGN_INTERCODE:{
                fprintf(fp, "%d := %d\n", code -> u.binary.left -> u.var_no, code -> u.binary.right -> u.var_no);
                break;
            }
            case DEC_INTERCODE:{
                fprintf(fp, "DEC %d [%d]\n", code -> u.binary.left -> u.var_no, code -> u.binary.right -> u.var_no);
                break;
            }
            case CALL_INTERCODE:{
                fprintf(fp, "%d := CALL %s\n", code -> u.binary.left -> u.var_no, code -> u.binary.right -> u.func_name);
                break;
            }
            case ADD_INTERCODE:{
                fprintf(fp, "%d := %d + %d\n", code -> u.ternary.result -> u.var_no, code -> u.ternary.op1 -> u.var_no, code -> u.ternary.op2);
                break;
            }
            case SUB_INTERCODE:{
                fprintf(fp, "%d := %d - %d\n", code -> u.ternary.result -> u.var_no, code -> u.ternary.op1 -> u.var_no, code -> u.ternary.op2);
                break;
            }
            case MUL_INTERCODE:{
                fprintf(fp, "%d := %d * %d\n", code -> u.ternary.result -> u.var_no, code -> u.ternary.op1 -> u.var_no, code -> u.ternary.op2);
                break;
            }
            case DIV_INTERCODE:{
                fprintf(fp, "%d := %d / %d\n", code -> u.ternary.result -> u.var_no, code -> u.ternary.op1 -> u.var_no, code -> u.ternary.op2);
                break;
            }
            case IFGOTO_INTERCODE:{
                fprintf(fp, "IF %d %s %d GOTO %d\n", code -> u.quaternary.op1 -> u.var_no, code -> u.quaternary.relop, code -> u.quaternary.op2 -> u.var_no, code -> u.quaternary.op3 -> u.var_no);
                break;
            }
            default:
                break;
        }
        p = p -> next;
    }
    return;
}
