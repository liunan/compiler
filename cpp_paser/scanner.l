%{
#include <stdio.h>
#include "y.tab.h"
int isKeyword(char* szInput);
%}
digit [0-9]
CONST_INT {digit}*
CONST_FLOAT {digit}*.{digit}+
nonedigitchar [a-zA-z_]
identifier {nonedigitchar}+({nonedigitchar}|{digit})*
preprocessor #{identifier}
%%
{identifier} {	
	int keyword = 0;
	if(keyword = isKeyword(yytext))
	{
		printf("\tlex:keyword [%s]\n",yytext);
		return keyword;
	}
	printf("\tlex:identifier [%s]\n",yytext);
	return IDENTIFIER;
}
{CONST_INT} {printf("\tlex:digits [%s]\n",yytext); }
{CONST_FLOAT} {printf("\tlex:CONST_FLOAT [%s]\n",yytext);}
{preprocessor} {printf("\tlex:preprocessor symol [%s]\n",yytext);}
[-()<>=+*/;{}.:] {
printf("\tlex:operator %c caught\n",*yytext);
	return *yytext;
}
[\r\n] ;
"->" {printf("lex:pointer op\n");}
. ;//{printf("lex:discard input [%s]\n",yytext);}
%%


int isKeyword(char* szInput)
{
	int iRet = 0;
	if(strcmp(szInput,"int")==0)
		iRet = INTEGER;
	else if(strcmp(szInput,"bool") ==0)
		iRet = BOOLEAN;
	else if(strcmp(szInput,"void") ==0)
		iRet = VOID;
	return iRet;
}

/*
int main()
{
	yylex();
	return 0;
}
*/

int yywrap(void)
{
	return 1;
}