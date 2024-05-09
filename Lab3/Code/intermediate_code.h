// include guard
#ifndef INTERMEDIATE_CODE
#define INTERMEDIATE_CODE

#include "semantic.h"
struct Operand{
    enum{
        VARIABLE_OPERAND, // variable
        CONSTANT_OPERAND, // constant
        FUNCTION_OPERAND, // function   
        ADDRESS_OPERAND,  // &variable
        TEMPVAR_OPERAND,  // t1, t2, t3, ...
        LABEL_OPERAND     // label1, label2, label3, ...
    }kind;
    union{
        char* var_name; // variable name
        int constant_value;  // constant value
        char* func_name; // function name
        struct Operand* addr; // address ???
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
        struct{struct Operand* left, right;}binary;
        struct{struct Operand* result, op1, op2;}ternary;
        struct{struct Operand* op1, op2, op3; char* relop;}quaternary;
    }u;
};

// structure to store generated intermediate code
struct InterCodeNode{
    struct InterCode* code;
    struct InterCodeNode* prev;
    struct InterCodeNode* next;
};

// function to generate intermediate code based on syntax analysis and semantic analysis
void generate_InterCode(struct ASTNode* root);








#endif