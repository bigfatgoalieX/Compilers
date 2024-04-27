%{
#include"stdio.h"
#include "syntax.tab.h"
#include "lex.yy.c"
int yyerror(char*msg){
    printf("Error type B at Line %d: %s near %s.\n",yylineno,msg,yytext);
}
// int yyerror(char*msg){
//     printf("syntax error\n");
// }
%}

%token INT FLOAT 
%token ID
%token SEMI COMMA
%token ASSIGNOP RELOP
%token PLUS MINUS STAR DIV
%token AND OR DOT NOT
%token TYPE
%token LP RP LB RB LC RC
%token STRUCT RETURN IF ELSE WHILE


%type Program ExtDefList ExtDef ExtDecList
%type Specifier StructSpecifier OptTag Tag
%type VarDec FunDec VarList ParamDec
%type CompSt StmtList Stmt
%type DefList Def DecList Dec
%type Exp Args


%%

/* High-level Definitions */
Program: ExtDefList {
    };

ExtDefList: ExtDef ExtDefList {
    };
    |/* empty */ 
    {

    };

ExtDef: Specifier ExtDecList SEMI{
 
    };
    | Specifier SEMI{

    };
    | Specifier FunDec CompSt{
 
    };
    /* error recovery */
    |error SEMI{
        
    };
    |Specifier error SEMI{
        
    };
    | error Specifier SEMI{
        
    };
    | error RP{
        
    };
    | error RC{
        
    };
    | error Specifier error CompSt{
        
    };
    
ExtDecList: VarDec{

    };
    | VarDec COMMA ExtDecList{

    };
    /* error recovery */
    |VarDec error ExtDefList{
        
    };


/* Specifiers */
Specifier: TYPE{
    };
    | StructSpecifier{
    };

StructSpecifier: STRUCT OptTag LC DefList RC{
    };
    | STRUCT Tag{
    };

OptTag: ID{
    };
    | /* empty */
    {
    };

Tag: ID{
    };


/* Declarators */
VarDec: ID{
    printf("first line :%d\n",(@1).first_line);
    };
    | VarDec LB INT RB{
    };
    /* error recovery */
    |VarDec LB error RB{
    };

FunDec:ID LP VarList RP{
    };
    | ID LP RP{

    };
    /* error recovery */
    |ID LP error RP{
    };
    |error LP VarList RP{
    };
    
VarList: ParamDec COMMA VarList{
    };
    | ParamDec{
    };
    
ParamDec: Specifier VarDec{
    };

/* Statements */
CompSt: LC DefList StmtList RC{

    };
    /* error recovery */
    | error RC{

    };

StmtList: Stmt StmtList{
    };
    |/* empty */ 
    {

    };

Stmt: Exp SEMI{
    };        
    | CompSt{
    }; 
    | RETURN Exp SEMI{
    };
    | IF LP Exp RP Stmt{
    };
    | IF LP Exp RP Stmt ELSE Stmt{
    };
    | WHILE LP Exp RP Stmt{
    };
    /* error recovery */
    | error SEMI {
        
    };
    | Exp error SEMI{
        
    };
    |RETURN Exp error{
        
    };
    |RETURN error SEMI{
        
    };
    | IF error ELSE Stmt{
        
    };
    | WHILE error RP{
        
    };
    | WHILE error RC{
        
    };

/* Local Definitions */
DefList: Def DefList{
    };
    |/* empty */
    {
    };

Def: Specifier DecList SEMI{
    };
    /* error recovery */
    | Specifier error SEMI{
        
    };
    | Specifier DecList error{
        
    };

DecList: Dec{
    };
    | Dec COMMA DecList{
    }

Dec:VarDec{
    };
    | VarDec ASSIGNOP Exp{
    };

/* Expressions */
Exp: Exp ASSIGNOP Exp{
    };
    | Exp AND Exp{
    };
    | Exp OR Exp{
    };
    | Exp RELOP Exp{
    };
    | Exp PLUS Exp{
    };
    | Exp MINUS Exp{
    };
    | Exp STAR Exp{
    };
    | Exp DIV Exp{
    };
    | LP Exp RP{
    };
    //不是minus
    | MINUS Exp{
    };
    | NOT Exp{
    };
    | ID LP Args RP{
    };
    | ID LP RP{
    };
    | Exp LB Exp RB{
    };
    | Exp DOT ID{
    };
    | ID{
    };
    | INT{
    };
    | FLOAT{
    };
    /* error recovery */
    | Exp ASSIGNOP error{
        
    };
    | Exp AND error{
        
    };
    | Exp OR error{
        
    };
    | Exp RELOP error{
        
    };
    | Exp PLUS error{
        
    };
    | Exp MINUS error{
        
    };
    | Exp STAR error{
        
    };
    | Exp DIV error{
        
    };
    | LP error RP{
        
    };
    | MINUS error{
        
    };
    | NOT error{
        
    };
    | ID LP error RP{
        
    };
    | ID LP error SEMI{
        
    };
    | Exp LB error RB{
        
    };
        
Args: Exp COMMA Args{
    };
    | Exp{
    };

%%

int main(int argc, char** argv)
{
    if (argc <= 1) return 1;
    FILE* f = fopen(argv[1], "r");
    if (!f)
    {
    perror(argv[1]);
    return 1;
    }
    yyrestart(f);
    yyparse();
    return 0;
}