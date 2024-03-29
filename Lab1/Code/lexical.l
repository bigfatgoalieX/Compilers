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
    yylval = atoi(yytext);
    // printf("SEMI\n");
    return SEMI;
    }
"," { 
    yylval = atoi(yytext);
    // printf("COMMA\n"); 
    return COMMA;
    }
"=" { 
    yylval = atoi(yytext);
    // printf("ASSIGNOP\n"); 
    return ASSIGNOP; 
    }
>|<|>=|<=|==|!= { 
    yylval = atoi(yytext);
    // printf("RELOP\n"); 
    return RELOP; 
    }
"+" { 
    yylval = atoi(yytext);
    // printf("PLUS\n"); 
    return PLUS; 
    }
"-" { 
    yylval = atoi(yytext);
    // printf("MINUS\n"); 
    return MINUS; 
    }
"*" { 
    yylval = atoi(yytext);
    // printf("STAR\n"); 
    return STAR; 
    }
"/" { 
    yylval = atoi(yytext);
    // printf("DIV\n"); 
    return DIV; 
    }
"&&" { 
    yylval = atoi(yytext);
    // printf("AND\n"); 
    return AND; 
    }
"||" { 
    yylval = atoi(yytext);
    // printf("OR\n"); 
    return OR; 
    }
"." { 
    yylval = atoi(yytext);
    // printf("DOT\n"); 
    return DOT; 
    }
"!" { 
    yylval = atoi(yytext);
    // printf("NOT\n"); 
    return NOT; 
    }
"int"|"float" { 
    yylval = atoi(yytext);
    // printf("TYPE\n"); 
    return TYPE; 
    }
"(" { 
    yylval = atoi(yytext);
    // printf("LP\n"); 
    return LP; 
    }
")" { 
    yylval = atoi(yytext);
    // printf("RP\n"); 
    return RP; 
    }
"[" { 
    yylval = atoi(yytext);
    // printf("LB\n"); 
    return LB; 
    }
"]" { 
    yylval = atoi(yytext);
    // printf("RB\n"); 
    return RB; 
    }
"{" { 
    yylval = atoi(yytext);
    // printf("LC\n"); 
    return LC; 
    }
"}" { 
    yylval = atoi(yytext);
    // printf("RC\n"); 
    return RC; 
    }
"struct" { 
    yylval = atoi(yytext);
    // printf("STRUCT\n"); 
    return STRUCT; 
    }
"return" { 
    yylval = atoi(yytext);
    // printf("RETURN\n"); 
    return RETURN; 
    }
"if" { 
    yylval = atoi(yytext);
    // printf("IF\n"); 
    return IF; 
    }
"else" { 
    yylval = atoi(yytext);
    // printf("ELSE\n"); 
    return ELSE; 
    }
"while" { 
    yylval = atoi(yytext);
    // printf("WHILE\n"); 
    return WHILE; 
    }
{INT} {
    yylval = atoi(yytext);
    // printf("INT\n");
    return INT;
}
{FLOAT} {
    yylval = atoi(yytext);
    // printf("FLOAT\n");
    return FLOAT;
}
{ID} {
    yylval = atoi(yytext);
    // printf("ID\n");
    return ID;
}
. { 
    printf("Error type A at Line %d: Mysterious characters \"%s\"\n",
    yylineno, yytext);
    }
%%
