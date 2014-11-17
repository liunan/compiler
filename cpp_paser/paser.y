%{
#include <stdio.h>
void yyerror(char *s);
extern int yylineno;
%}
%token TYPE IDENTIFIER CONST_VALUE
%left '*'
%%


stmts:
	stmts stmt {printf("yacc:stmts stmt\n");} |
	/*NULL*/
;
stmt:	
	';' |
	var_declare ';'|	
	func_declare ';' |
	error ';' |
	error '}'
	{printf("stmt received\n");}	
;

var_follows:
	// {printf("yacc:var_follows\n");}|
	',' var var_follows {printf("yacc:var_follows var\n");}|
	/*NULL*/
;
var:
	IDENTIFIER assignment {printf("yacc:var\n");}
;
assignment:
	'=' CONST_VALUE {printf("yacc:assignment\n");} |
	/**/
;
var_declare:
	type_value_pair var_follows {printf("yacc:var_declare\n");}
;
type_value_pair:
	type var
;
type_decorator:
	/*NULL*/|
	'*' |
	'&'
;	
type:
	TYPE type_decorator
;
param:
	type param_var param_list{printf("yacc:param\n");} |
	/**/
	
;
param_var:
	var |
	/**/{printf("yacc:param_var empty\n");}
;
param_list:
	',' param {printf("yacc:param_list\n");} |	
	/**/
;
func_declare:
	type IDENTIFIER '(' param ')'	{printf("yacc:func_declare\n");}
;
%%
void yyerror(char *s) {
    fprintf(stderr, "***yacc error:line %d: %s***\n", yylineno, s);
}
int main(void) {
    yyparse();
    return 0;

}