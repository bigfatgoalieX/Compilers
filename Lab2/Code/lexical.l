%option yylineno

%{
#include "stdio.h"
#include "syntax.tab.h"
#include "tree.h"
#include "semantic.h"

// extern Node *bison_create_node(NodeType type, char* type_name);
// extern enum ASTNodeType;

int yycolumn = 1;
#define YY_USER_ACTION \
    yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; \
    yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng;


%}



DIGIT [0-9] 
LETTER_ [_a-zA-Z]
WHITESPACE [ \t\r\n]+
INT [+-]?{DIGIT}+
FLOAT [+-]?{DIGIT}+\.?{DIGIT}+
ID {LETTER_}({LETTER_}|{DIGIT})*

%%
"\n" { yycolumn = 1;}
{WHITESPACE} {;}






";" {
    //init attribute for Terminals
    // printf("SEMI\n");
    yylval.node = flex_create_node(KEYWORD_PUNCTUATION,"SEMI",yylineno);
    strcpy(yylval.node -> data.stringval, yytext);
    return SEMI;
    }
"," { 
    //init attribute for Terminals
    // printf("COMMA\n"); 
    yylval.node = flex_create_node(KEYWORD_PUNCTUATION,"COMMA",yylineno);
    strcpy(yylval.node -> data.stringval, yytext);
    return COMMA;
    }
"=" { 
    //init attribute for Terminals
    // printf("ASSIGNOP\n"); 
    yylval.node = flex_create_node(KEYWORD_OPERATOR,"ASSIGNOP",yylineno);
    strcpy(yylval.node -> data.stringval, yytext);
    return ASSIGNOP; 
    }
>|<|>=|<=|==|!= { 
    //init attribute for Terminals
    // printf("RELOP\n"); 
    yylval.node = flex_create_node(KEYWORD_RELOP,"RELOP",yylineno);
    strcpy(yylval.node -> data.stringval, yytext);
    return RELOP; 
    }
"+" { 
    //init attribute for Terminals;
    // printf("PLUS\n");
    yylval.node = flex_create_node(KEYWORD_OPERATOR,"PLUS",yylineno);
    strcpy(yylval.node -> data.stringval, yytext); 
    return PLUS; 
    }
"-" { 
    //init attribute for Terminals
    // printf("MINUS\n"); 
    yylval.node = flex_create_node(KEYWORD_OPERATOR,"MINUS",yylineno);
    strcpy(yylval.node -> data.stringval, yytext); 
    return MINUS; 
    }
"*" { 
    //init attribute for Terminals
    // printf("STAR\n"); 
    yylval.node = flex_create_node(KEYWORD_OPERATOR,"STAR",yylineno);
    strcpy(yylval.node -> data.stringval, yytext); 
    return STAR; 
    }
"/" { 
    //init attribute for Terminals
    // printf("DIV\n");
    yylval.node = flex_create_node(KEYWORD_OPERATOR,"DIV",yylineno);
    strcpy(yylval.node -> data.stringval, yytext);  
    return DIV; 
    }
"&&" { 
    //init attribute for Terminals
    // printf("AND\n");
    yylval.node = flex_create_node(KEYWORD_OPERATOR,"AND",yylineno);
    strcpy(yylval.node -> data.stringval, yytext);  
    return AND; 
    }
"||" { 
    //init attribute for Terminals
    // printf("OR\n"); 
    yylval.node = flex_create_node(KEYWORD_OPERATOR,"OR",yylineno);
    strcpy(yylval.node -> data.stringval, yytext); 
    return OR; 
    }
"." { 
    //init attribute for Terminals
    // printf("DOT\n"); 
    yylval.node = flex_create_node(KEYWORD_PUNCTUATION,"DOT",yylineno);
    strcpy(yylval.node -> data.stringval, yytext);
    return DOT; 
    }
"!" { 
    //init attribute for Terminals
    // printf("NOT\n"); 
    yylval.node = flex_create_node(KEYWORD_OPERATOR,"NOT",yylineno);
    strcpy(yylval.node -> data.stringval, yytext);
    return NOT; 
    }
"int"|"float" { 
    //init attribute for Terminals
    // printf("TYPE\n"); 
    yylval.node = flex_create_node(KEYWORD_TYPE,"TYPE",yylineno);
    strcpy(yylval.node -> data.stringval, yytext);
    return TYPE; 
    }
"(" { 
    //init attribute for Terminals
    // printf("LP\n");
    yylval.node = flex_create_node(KEYWORD_BRACKET,"LP",yylineno);
    strcpy(yylval.node -> data.stringval, yytext); 
    return LP; 
    }
")" { 
    //init attribute for Terminals
    // printf("RP\n");
    yylval.node = flex_create_node(KEYWORD_BRACKET,"RP",yylineno);
    strcpy(yylval.node -> data.stringval, yytext); 
    return RP; 
    }
"[" { 
    //init attribute for Terminals
    // printf("LB\n");
    yylval.node = flex_create_node(KEYWORD_BRACKET,"LB",yylineno);
    strcpy(yylval.node -> data.stringval, yytext);  
    return LB; 
    }
"]" { 
    //init attribute for Terminals
    // printf("RB\n");
    yylval.node = flex_create_node(KEYWORD_BRACKET,"RB",yylineno);
    strcpy(yylval.node -> data.stringval, yytext);  
    return RB; 
    }
"{" { 
    //init attribute for Terminals
    // printf("LC\n");
    yylval.node = flex_create_node(KEYWORD_BRACKET,"LC",yylineno);
    strcpy(yylval.node -> data.stringval, yytext); 
    return LC; 
    }
"}" { 
    //init attribute for Terminals
    // printf("RC\n");
    yylval.node = flex_create_node(KEYWORD_BRACKET,"RC",yylineno);
    strcpy(yylval.node -> data.stringval, yytext); 
    return RC; 
    }
"struct" { 
    //init attribute for Terminals
    // printf("STRUCT\n"); 
    yylval.node = flex_create_node(KEYWORDS,"STRUCT",yylineno);
    strcpy(yylval.node -> data.stringval, yytext);
    return STRUCT; 
    }
"return" { 
    //init attribute for Terminals
    // printf("RETURN\n");
    yylval.node = flex_create_node(KEYWORDS,"RETURN",yylineno);
    strcpy(yylval.node -> data.stringval, yytext); 
    return RETURN; 
    }
"if" { 
    //init attribute for Terminals
    // printf("IF\n");
    yylval.node = flex_create_node(KEYWORDS,"IF",yylineno);
    strcpy(yylval.node -> data.stringval, yytext); 
    return IF; 
    }
"else" { 
    //init attribute for Terminals
    // printf("ELSE\n");
    yylval.node = flex_create_node(KEYWORDS,"ELSE",yylineno);
    strcpy(yylval.node -> data.stringval, yytext); 
    return ELSE; 
    }
"while" { 
    //init attribute for Terminals
    // printf("WHILE\n");
    yylval.node = flex_create_node(KEYWORDS,"WHILE",yylineno);
    strcpy(yylval.node -> data.stringval, yytext); 
    return WHILE; 
    }
{INT} {
    //init attribute for Terminals
    // printf("INT\n");
    yylval.node = flex_create_node(INTNUMBER,"INT",yylineno);
    yylval.node -> data.intval = atoi(yytext);
    return INT;
}
{FLOAT} {
    //init attribute for Terminals
    // printf("FLOAT\n");
    yylval.node = flex_create_node(FLOATNUMBER,"FLOAT",yylineno);
    yylval.node -> data.floatval = atoi(yytext);
    return FLOAT;
}
{ID} {
    //init attribute for Terminals
    // printf("ID\n");
    yylval.node = flex_create_node(ID_TYPE ,"ID",yylineno);
    strcpy(yylval.node -> data.stringval, yytext); 
    return ID;
}
. { 
    printf("Error type A at Line %d: Mysterious characters \"%s\"\n",
    yylineno, yytext);
}
%%
