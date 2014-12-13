%{
#include <stdio.h>
void yyerror(char *s);
extern int yylineno;
%}
%token TYPE IDENTIFIER CONST_VALUE ENUM CLASS STRUCT UNION VISIBLE_MODIFIER
%left '*'
%%

class_specifier:
	CLASS IDENTIFIER '{' class_contents '}'
;

class_contents:
	class_content ';' 
;
class_content:	
	VISIBLE_MODIFIER ':' |
	/**/
;
%%
void yyerror(char *s) {
    fprintf(stderr, "***yacc error:line %d: %s***\n", yylineno, s);
}
int main(void) {
    yyparse();
    return 0;

}