%option yylineno

DIGIT [0-9] 
LETTER_ [_a-zA-Z]
WHITESPACE [ \t\r\n]+
INT [+-]?{DIGIT}+
FLOAT [+-]?{DIGIT}+\.?{DIGIT}+
ID {LETTER_}({LETTER_}|{DIGIT})*

%%

{WHITESPACE} {;}
";" {
    printf("SEMI\n");
    // return SEMI;
    }
"," { 
    printf("COMMA\n"); 
    // return COMMA;
    }
"=" { 
    printf("ASSIGNOP\n"); 
    // return ASSIGNOP; 
    }
>|<|>=|<=|==|!= { 
    printf("RELOP\n"); 
    // return RELOP; 
    }
"+" { 
    printf("PLUS\n"); 
    // return PLUS; 
    }
"-" { 
    printf("MINUS\n"); 
    // return MINUS; 
    }
"*" { 
    printf("STAR\n"); 
    // return STAR; 
    }
"/" { 
    printf("DIV\n"); 
    // return DIV; 
    }
"&&" { 
    printf("AND\n"); 
    // return AND; 
    }
"||" { 
    printf("OR\n"); 
    // return OR; 
    }
"." { 
    printf("DOT\n"); 
    // return DOT; 
    }
"!" { 
    printf("NOT\n"); 
    // return NOT; 
    }
"int"|"float" { 
    printf("TYPE\n"); 
    // return TYPE; 
    }
"(" { 
    printf("LP\n"); 
    // return LP; 
    }
")" { 
    printf("RP\n"); 
    // return RP; 
    }
"[" { 
    printf("LB\n"); 
    // return LB; 
    }
"]" { 
    printf("RB\n"); 
    // return RB; 
    }
"{" { 
    printf("LC\n"); 
    // return LC; 
    }
"}" { 
    printf("RC\n"); 
    // return RC; 
    }
"struct" { 
    printf("STRUCT\n"); 
    // return STRUCT; 
    }
"return" { 
    printf("RETURN\n"); 
    // return RETURN; 
    }
"if" { 
    printf("IF\n"); 
    // return IF; 
    }
"else" { 
    printf("ELSE\n"); 
    // return ELSE; 
    }
"while" { 
    printf("WHILE\n"); 
    // return WHILE; 
    }
{INT} {
    printf("INT\n");
    // return INT;
}
{FLOAT} {
    printf("FLOAT\n");
    // return FLOAT;
}
{ID} {
    printf("ID\n");
    // return ID;
}
. { 
    printf("Error type A at Line %d: Mysterious characters \'%s\'\n",
    yylineno, yytext);
    }
%%
