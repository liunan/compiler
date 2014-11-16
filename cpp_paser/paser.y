%{
#include <stdio.h>
void yyerror(char *s);
extern int yylineno;
%}
%token INTEGER VOID BOOLEAN IDENTIFIER
%left '*'
%%
stmt:	
	';' |
	function |
	var_declare |
	/*NULL*/ |
	stmt |
	error ';' |
	error '}'
	{printf("stmt received\n");}	
;

function:
type_value '(' param_list ')' ';' {printf("yac:function captured\n");};
return_type:
INTEGER | VOID | BOOLEAN | /*NULL*/ {printf("yacc:type caught\n");}
;
param_list:
	param_list ',' type_value | 
;
type_value:return_type IDENTIFIER | /*NULL*/ {printf("type_value_pair caught\n");}
;
var_declare:
	type_value {printf("yacc:var_declare\n");}
;
%%
void yyerror(char *s) {
    fprintf(stderr, "line %d: %s\n", yylineno, s);
}
int main(void) {
    yyparse();
    return 0;

}