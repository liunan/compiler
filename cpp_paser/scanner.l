%{
#include <stdio.h>
void yyerror(char*);
%}
digit [0-9]
CONST_INT {digit}*
CONST_FLOAT {digit}*.{digit}+
nonedigitchar [a-zA-z_]
identifier {nonedigitchar}+({nonedigitchar}|{digit})*
preprocessor #{identifier}
%%
{identifier} {printf("identifier [%s] caught\n",yytext);}
{CONST_INT} {printf("digits [%s] caught\n",yytext);}
{CONST_FLOAT} {printf("CONST_FLOAT [%s] caught\n",yytext);}
{preprocessor} {printf("preprocessor symol [%s] caught\n",yytext);}
[-()<>=+*/;{}.:] {printf("operator %c caught\n",*yytext);}
[\r\n] ;
"->" {printf("pointer op\n");}
. ;//{printf("discard input [%s]\n",yytext);}
%%

int main()
{
	yylex();
	return 0;
}

int yywrap(void)
{
	return 1;
}