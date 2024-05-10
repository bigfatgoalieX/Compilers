// include guard
#ifndef INTERCODE_UTILS
#define INTERCODE_UTILS

#include "semantic.h"
struct Operand{
    enum{
        VARIABLE_OPERAND, // variable v1, v2, v3, ...
        CONSTANT_OPERAND, // constant
        FUNCTION_OPERAND, // function   
        TEMPVAR_OPERAND,  // t1, t2, t3, ...
        LABEL_OPERAND     // label1, label2, label3, ...
    }kind;
    union{
        int var_no; // variable name
        int constant_value;  // constant value
        char* func_name; // function name
        int temp_no; // temporary variable number
        int label_no; // label number
    }u;
};
struct InterCode{
    enum{
        // Operand_num = 1
        FUNCTION_INTERCODE, // FUNCTION f :
        PARAM_INTERCODE,    // PARAM x
        RETURN_INTERCODE,   // RETURN x
        ARG_INTERCODE,      // ARG x
        LABEL_INTERCODE,    // LABEL x :
        GOTO_INTERCODE,     // GOTO x
        READ_INTERCODE,     // READ x
        WRITE_INTERCODE,    // WRITE x 

        // Operand_num = 2
        ASSIGN_INTERCODE,   // x := y
        DEC_INTERCODE,      // DEC x [size]
        CALL_INTERCODE,     // x := CALL f

        // Operand_num = 3
        ADD_INTERCODE,      // x := y + z
        SUB_INTERCODE,      // x := y - z
        MUL_INTERCODE,      // x := y * z
        DIV_INTERCODE,      // x := y / z

        // Operand_num = 4
        IFGOTO_INTERCODE    // IF x [relop] y GOTO z
    }kind;
    union{
        struct{struct Operand* result;}unary;
        struct{struct Operand* left, *right;}binary;
        struct{struct Operand* result, *op1, *op2;}ternary;
        struct{struct Operand* op1, *op2, *op3; char* relop;}quaternary;
    }u;
};

// structure to store generated intermediate code
struct InterCodeNode{
    struct InterCode* code;
    struct InterCodeNode* prev;
    struct InterCodeNode* next;
};

struct Operand* Operand_Init(int kind, ...);
struct InterCode* InterCode_Init(int kind, int operand_no, ...);
void InsertInterCodeNode(struct InterCode* code);
void fPrintInterCode(FILE* fp);









#endif