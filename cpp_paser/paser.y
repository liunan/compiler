%{
#include <stdio.h>
void yyerror(char *s);
extern int yylineno;
%}
%token TYPE IDENTIFIER CONST_VALUE
%left '*'
%%

yacc_output:
	program	{printf("yacc::accepted\n");}
;
program:
	stmt stmts {printf("yacc:program\n");}
;
stmts:
	program | /**/
;
stmt:	
	';' |	
	var_declare ';'|	
	error ';' |
	error '}'
	{printf("stmt received\n");}	
;
var_list:	
	var var_follows {printf("yacc:var_list\n");}
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
	TYPE var_list {printf("yacc:var_declare\n");}
;
%%
void yyerror(char *s) {
    fprintf(stderr, "***yacc error:line %d: %s***\n", yylineno, s);
}
int main(void) {
    yyparse();
    return 0;

}