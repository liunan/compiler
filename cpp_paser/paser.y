%{
#include <stdio.h>
void yyerror(char *s);
extern int yylineno;
%}
%token INTEGER VOID BOOLEAN OPENPA CLOSEPA COMMA IDENTIFIER SEMICOLON
%left '*'
%%
stmt:	
	function |
	var_declare |
	SEMICOLON |
	error SEMICOLON |
	error '}'
	{printf("stmt received\n");}
	;
function:
type_value OPENPA param_list CLOSEPA SEMICOLON {printf("function captured\n");};
return_type:
INTEGER | VOID | BOOLEAN | /*NULL*/ {printf("type caught\n");}
;
param_list:
	param_list COMMA type_value | 
;
type_value:return_type IDENTIFIER | /*NULL*/ {printf("type_value_pair caught\n");}
;
var_declare:
	type_value {printf("yacc var_declare\n");}
;
%%
void yyerror(char *s) {
    fprintf(stderr, "line %d: %s\n", yylineno, s);
}
int main(void) {
    yyparse();
    return 0;

}