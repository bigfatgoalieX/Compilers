%{

#include "stdio.h"
#include "syntax.tab.h"
#include "lex.yy.c"
#include "tree.h"
#include "semantic.h"
#include "intercode_gen.h"

// extern struct ASTNode;
Node *root; //the root of the AST
int err_cnt = 0;

int yyerror(char*msg){
    printf("Error type B at Line %d: %s near %s.\n",yylineno,msg,yytext);
}
// int yyerror(char*msg){
//     printf("syntax error\n");
// }


%}


%locations

%union {
    int intval;
    float floatval;
    char stringval[32];
    struct ASTNode *node; 
}

%token <node> INT FLOAT 
%token <node> ID
%token <node> SEMI COMMA
%token <node> ASSIGNOP RELOP
%token <node> PLUS MINUS STAR DIV
%token <node> AND OR DOT NOT
%token <node> TYPE
%token <node> LP RP LB RB LC RC
%token <node> STRUCT RETURN IF ELSE WHILE


%type <node> Program ExtDefList ExtDef ExtDecList
%type <node> Specifier StructSpecifier OptTag Tag
%type <node> VarDec FunDec VarList ParamDec
%type <node> CompSt StmtList Stmt
%type <node> DefList Def DecList Dec
%type <node> Exp Args

%start Program

%right ASSIGNOP

%left OR

%left AND

%left RELOP

%left PLUS MINUS

%left STAR DIV

%right NOT

%left DOT LB RB LP RP

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

/* High-level Definitions */
Program: ExtDefList {
    $$ = bison_create_node(PROGRAM,"Program");
    root = $$;
    addchild($$,1,$1);
    };

ExtDefList: ExtDef ExtDefList {
    $$ = bison_create_node(EXTDEFLIST,"Extdeflist");
    addchild($$,2,$1,$2);
    };
    |/* empty */ 
    {
        $$=NULL;
    };

ExtDef: Specifier ExtDecList SEMI{
    $$ = bison_create_node(EXTDEF,"Extdef");
    addchild($$,3,$1,$2,$3);
    };
    | Specifier SEMI{
        $$ = bison_create_node(EXTDEF,"Extdef");
        addchild($$,2,$1,$2);
    };
    | Specifier FunDec CompSt{
        $$ = bison_create_node(EXTDEF,"Extdef");
        addchild($$,3,$1,$2,$3);
    };
    /* error recovery */
    |error SEMI{
        err_cnt++;
    };
    |Specifier error SEMI{
        err_cnt++;
    };
    | error Specifier SEMI{
        err_cnt++;
    };
    | error RP{
        err_cnt++;
    };
    | error RC{
        err_cnt++;
    };
    | error Specifier error CompSt{
        err_cnt++;
    };
    
ExtDecList: VarDec{
    $$ = bison_create_node(EXTDECLIST,"Extdeclist");
    addchild($$,1,$1);
    };
    | VarDec COMMA ExtDecList{
        $$ = bison_create_node(EXTDECLIST,"Extdeclist");
        addchild($$,3,$1,$2,$3);
    };
    /* error recovery */
    |VarDec error ExtDefList{
        err_cnt++;
    };


/* Specifiers */
Specifier: TYPE{
    $$ = bison_create_node(SPECIFIER,"Specifier");
    addchild($$,1,$1);
    };
    | StructSpecifier{
        $$ = bison_create_node(SPECIFIER,"Specifier");
        addchild($$,1,$1);
    };

StructSpecifier: STRUCT OptTag LC DefList RC{
    $$ = bison_create_node(STRUCTSPECIFIER,"StructSpecifier");
    addchild($$,5,$1,$2,$3,$4,$5);
    };
    | STRUCT Tag{
        $$ = bison_create_node(STRUCTSPECIFIER,"StructSpecifier");
        addchild($$,2,$1,$2);
    };

OptTag: ID{
        $$ = bison_create_node(OPTTAG,"OptTag");
        addchild($$,1,$1);
    };
    | /* empty */
    {
        $$=NULL;
    };

Tag: ID{
        $$ = bison_create_node(TAG,"Tag");
        addchild($$,1,$1);
    };


/* Declarators */
VarDec: ID{
    $$ = bison_create_node(VARDEC,"VarDec");
    addchild($$,1,$1);
    };
    | VarDec LB INT RB{
        $$ = bison_create_node(VARDEC,"VarDec");
        addchild($$,4,$1,$2,$3,$4);
    };
    /* error recovery */
    |VarDec LB error RB{
        err_cnt++;
    };

FunDec:ID LP VarList RP{
    $$ = bison_create_node(FUNDEC,"FunDec");
    addchild($$,4,$1,$2,$3,$4);
    };
    | ID LP RP{
        $$ = bison_create_node(FUNDEC,"FunDec");
        addchild($$,3,$1,$2,$3);
    };
    /* error recovery */
    |ID LP error RP{
        err_cnt++;
    };
    |error LP VarList RP{
        err_cnt++;
    };
    
VarList: ParamDec COMMA VarList{
    $$ = bison_create_node(VARLIST,"VarList");
    addchild($$,3,$1,$2,$3);
    };
    | ParamDec{
        $$ = bison_create_node(VARLIST,"VarList");
        addchild($$,1,$1);
    };
    
ParamDec: Specifier VarDec{
    $$ = bison_create_node(PARAMDEC,"ParamDec");
    addchild($$,2,$1,$2);
    };

/* Statements */
CompSt: LC DefList StmtList RC{
    $$ = bison_create_node(COMPST,"CompSt");
    addchild($$,4,$1,$2,$3,$4);
    };
    /* error recovery */
    | error RC{
        err_cnt++;
    };

StmtList: Stmt StmtList{
    $$ = bison_create_node(STMTLIST,"StmtList");
    addchild($$,2,$1,$2);
    };
    |/* empty */ 
    {
        $$=NULL;
    };

Stmt: Exp SEMI{
    $$ = bison_create_node(STMT,"Stmt");
    addchild($$,2,$1,$2);
    };        
    | CompSt{
        $$ = bison_create_node(STMT,"Stmt");
        addchild($$,1,$1);
    }; 
    | RETURN Exp SEMI{
        $$ = bison_create_node(STMT,"Stmt");
        addchild($$,3,$1,$2,$3);
    };
    | IF LP Exp RP Stmt{
        $$ = bison_create_node(STMT,"Stmt");
        addchild($$,5,$1,$2,$3,$4,$5);
    };
    | IF LP Exp RP Stmt ELSE Stmt{
        $$ = bison_create_node(STMT,"Stmt");
        addchild($$,7,$1,$2,$3,$4,$5,$6,$7);
    };
    | WHILE LP Exp RP Stmt{
        $$ = bison_create_node(STMT,"Stmt");
        addchild($$,5,$1,$2,$3,$4,$5);
    };
    /* error recovery */
    | error SEMI {
        err_cnt++;
    };
    | Exp error SEMI{
        err_cnt++;
    };
    |RETURN Exp error{
        err_cnt++;
    };
    |RETURN error SEMI{
        err_cnt++;
    };
    | IF error ELSE Stmt{
        err_cnt++;
    };
    | WHILE error RP{
        err_cnt++;
    };
    | WHILE error RC{
        err_cnt++;
    };

/* Local Definitions */
DefList: Def DefList{
    $$ = bison_create_node(DEFLIST,"DefList");
    addchild($$,2,$1,$2);
    };
    |/* empty */
    {
        $$=NULL;
    };

Def: Specifier DecList SEMI{
    $$ = bison_create_node(DEF,"Def");
    addchild($$,3,$1,$2,$3);    
    };
    /* error recovery */
    | Specifier error SEMI{
        err_cnt++;
    };
    | Specifier DecList error{
        err_cnt++;
    };

DecList: Dec{
    $$ = bison_create_node(DECLIST,"DecList");
    addchild($$,1,$1);
    };
    | Dec COMMA DecList{
        $$ = bison_create_node(DECLIST,"DecList");
        addchild($$,3,$1,$2,$3);
    }

Dec:VarDec{
    $$ = bison_create_node(DEC,"Dec");
    addchild($$,1,$1);
    };
    | VarDec ASSIGNOP Exp{
        $$ = bison_create_node(DEC,"Dec");
        addchild($$,3,$1,$2,$3);
    };

/* Expressions */
Exp: Exp ASSIGNOP Exp{
    $$ = bison_create_node(EXP,"Exp");
    addchild($$,3,$1,$2,$3);
    };
    | Exp AND Exp{
        $$ = bison_create_node(EXP,"Exp");
        addchild($$,3,$1,$2,$3);
    };
    | Exp OR Exp{
        $$ = bison_create_node(EXP,"Exp");
        addchild($$,3,$1,$2,$3);
    };
    | Exp RELOP Exp{
        $$ = bison_create_node(EXP,"Exp");
        addchild($$,3,$1,$2,$3);
    };
    | Exp PLUS Exp{
        $$ = bison_create_node(EXP,"Exp");
        addchild($$,3,$1,$2,$3);
    };
    | Exp MINUS Exp{
        $$ = bison_create_node(EXP,"Exp");
        addchild($$,3,$1,$2,$3);
    };
    | Exp STAR Exp{
        $$ = bison_create_node(EXP,"Exp");
        addchild($$,3,$1,$2,$3);
    };
    | Exp DIV Exp{
        $$ = bison_create_node(EXP,"Exp");
        addchild($$,3,$1,$2,$3);
    };
    | LP Exp RP{
        $$ = bison_create_node(EXP,"Exp");
        addchild($$,3,$1,$2,$3);
    };
    //不是minus
    | MINUS Exp{
        $$ = bison_create_node(EXP,"Exp");
        addchild($$,2,$1,$2);
    };
    | NOT Exp{
        $$ = bison_create_node(EXP,"Exp");
        addchild($$,2,$1,$2);
    };
    | ID LP Args RP{
        $$ = bison_create_node(EXP,"Exp");
        addchild($$,4,$1,$2,$3,$4);
    };
    | ID LP RP{
        $$ = bison_create_node(EXP,"Exp");
        addchild($$,3,$1,$2,$3);
    };
    | Exp LB Exp RB{
        $$ = bison_create_node(EXP,"Exp");
        addchild($$,4,$1,$2,$3,$4);
    };
    | Exp DOT ID{
        $$ = bison_create_node(EXP,"Exp");
        addchild($$,3,$1,$2,$3);
    };
    | ID{
        $$ = bison_create_node(EXP,"Exp");
        addchild($$,1,$1);
    };
    | INT{
        $$ = bison_create_node(EXP,"Exp");
        addchild($$,1,$1);
    };
    | FLOAT{
        $$ = bison_create_node(EXP,"Exp");
        addchild($$,1,$1);
    };
    /* error recovery */
    | Exp ASSIGNOP error{
        err_cnt++;
    };
    | Exp AND error{
        err_cnt++;
    };
    | Exp OR error{
        err_cnt++;
    };
    | Exp RELOP error{
        err_cnt++;
    };
    | Exp PLUS error{
        err_cnt++;
    };
    | Exp MINUS error{
        err_cnt++;
    };
    | Exp STAR error{
        err_cnt++;
    };
    | Exp DIV error{
        err_cnt++;
    };
    | LP error RP{
        err_cnt++;
    };
    | MINUS error{
        err_cnt++;
    };
    | NOT error{
        err_cnt++;
    };
    | ID LP error RP{
        err_cnt++;
    };
    | ID LP error SEMI{
        err_cnt++;
    };
    | Exp LB error RB{
        err_cnt++;
    };
        
Args: Exp COMMA Args{
    $$ = bison_create_node(ARGS,"Args");
    addchild($$,3,$1,$2,$3);
    };
    | Exp{
        $$ = bison_create_node(ARGS,"Args");
        addchild($$,1,$1);
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

    FILE* f2 = fopen(argv[2], "w");
    if (!f2)
    {
    perror(argv[2]);
    return 1;
    }

    yyrestart(f);
    yyparse();
    if(err_cnt == 0){
        // printf("Syntax is correct\n");
        // preorder_traversal_AST(root);
        semantic_analysis(root);
        // printf("debuginfo: semantic analysis finished\n");
        // printSymbolTable();
        // printTypeTable();
        generate_InterCode(root,f2);
    }
    return 0;
}