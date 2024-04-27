%option yylineno

%{
#include"stdio.h"
#include "syntax.tab.h"


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
    return SEMI;
    }
"," { 
    //init attribute for Terminals
    // printf("COMMA\n"); 
    return COMMA;
    }
"=" { 
    //init attribute for Terminals
    // printf("ASSIGNOP\n"); 
    return ASSIGNOP; 
    }
>|<|>=|<=|==|!= { 
    //init attribute for Terminals
    // printf("RELOP\n"); 
    return RELOP; 
    }
"+" { 
    //init attribute for Terminals;
    // printf("PLUS\n"); 
    return PLUS; 
    }
"-" { 
    //init attribute for Terminals
    // printf("MINUS\n"); 
    return MINUS; 
    }
"*" { 
    //init attribute for Terminals
    // printf("STAR\n"); 
    return STAR; 
    }
"/" { 
    //init attribute for Terminals
    // printf("DIV\n"); 
    return DIV; 
    }
"&&" { 
    //init attribute for Terminals
    // printf("AND\n"); 
    return AND; 
    }
"||" { 
    //init attribute for Terminals
    // printf("OR\n"); 
    return OR; 
    }
"." { 
    //init attribute for Terminals
    // printf("DOT\n"); 
    return DOT; 
    }
"!" { 
    //init attribute for Terminals
    // printf("NOT\n"); 
    return NOT; 
    }
"int"|"float" { 
    //init attribute for Terminals
    // printf("TYPE\n"); 
    return TYPE; 
    }
"(" { 
    //init attribute for Terminals
    // printf("LP\n"); 
    return LP; 
    }
")" { 
    //init attribute for Terminals
    // printf("RP\n"); 
    return RP; 
    }
"[" { 
    //init attribute for Terminals
    // printf("LB\n"); 
    return LB; 
    }
"]" { 
    //init attribute for Terminals
    // printf("RB\n"); 
    return RB; 
    }
"{" { 
    //init attribute for Terminals
    // printf("LC\n"); 
    return LC; 
    }
"}" { 
    //init attribute for Terminals
    // printf("RC\n"); 
    return RC; 
    }
"struct" { 
    //init attribute for Terminals
    // printf("STRUCT\n"); 
    return STRUCT; 
    }
"return" { 
    //init attribute for Terminals
    // printf("RETURN\n"); 
    return RETURN; 
    }
"if" { 
    //init attribute for Terminals
    // printf("IF\n"); 
    return IF; 
    }
"else" { 
    //init attribute for Terminals
    // printf("ELSE\n"); 
    return ELSE; 
    }
"while" { 
    //init attribute for Terminals
    // printf("WHILE\n"); 
    return WHILE; 
    }
{INT} {
    //init attribute for Terminals
    // printf("INT\n");
    return INT;
}
{FLOAT} {
    //init attribute for Terminals
    // printf("FLOAT\n");
    return FLOAT;
}
{ID} {
    //init attribute for Terminals
    // printf("ID\n");
    return ID;
}
. { 
    printf("Error type A at Line %d: Mysterious characters \"%s\"\n",
    yylineno, yytext);
    }
%%
