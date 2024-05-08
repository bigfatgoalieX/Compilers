# C--文法解析

### High-level Definitions

```css
Program -> ExtDefList
ExtDefList -> ExtDef ExtDefList | ε
ExtDef -> Specifier ExtDecList SEMI | Specifier SEMI | Specifier FunDec CompSt
ExtDecList -> VarDec | VarDec COMMA ExtDecList
```

```c
int;
// 这样的语法在C语言中也是被允许的
```

### Specifiers

```css
Specifier -> TYPE | StructSpecifier
StructSpecifier  -> STRUCT OptTag LC DefList RC | STRUCT Tag
OptTag -> ID | ε 
/* Opt is short for optional */
Tag -> ID
```

```c
struct{int a;int b;} x;
// 这样定义是被允许的
struct complex{int c;int d;};
struct complex y;
// 虽然我们更习惯于这样定义
```

### Declarators

```css
VarDec -> ID | VarDec LB INT RB
FunDec -> ID LP VarList RP | ID LP RP
VarList -> ParamDec COMMA VarList | ParamDec
ParamDec -> Specifier VarDec
```

```c
foo(int x, float y[10])
// 这是C--中一个完整的函数头
```

### Statements

```css
CompSt -> LC DefList StmtList RC
/* CompSt表示一个由一对花括号括起来的语句块。该语句块内部先是一系列的变量定义
DefList，然后是一系列的语句StmtList。可以发现，对CompSt这样的定义，是不允许在程
序的任意位置定义变量的，必须在每一个语句块的开头才可以定义。*/
StmtList -> Stmt StmtList | ε
Stmt -> Exp SEMI | CompSt | RETURN Exp SEMI | IF LP Exp RP Stmt
| IF LP Exp RP Stmt ELSE Stmt | WHILE Lp Exp RP Stmt
```

### Local Definitions

```css
DefList -> Def DefList | ε
Def -> Specifier DecList SEMI
DecList -> Dec | Dec COMMA DecList
Dec -> VarDec | VarDec ASSIGNOP Exp
```

### Expressions

```css
Exp /* 包含二元运算符的表达式 */ 
-> Exp ASSIGNOP Exp
| Exp AND Exp
| Exp OR Exp
| Exp RELOP Exp
| Exp PLUS Exp
| Exp MINUS Exp
| Exp STAR Exp
| Exp DIV Exp
/* 包含一元运算符的表达式 */ 
| LP Exp RP
| MINUS Exp
| NOT Exp
/* 不包含运算符但又比较特殊的表达式 */ 
| ID LP Args RP
| ID LP RP
| Exp LB Exp RB
| Exp DOT ID
/* 最基本的表达式 */ 
| ID
| INT
| FLOAT
/* 实参列表 */
Args -> Exp COMMA Args | Exp
```

