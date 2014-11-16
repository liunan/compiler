%{
#include <stdio.h>
#include "y.tab.h"
int isType(char* szInput);
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
	if(keyword = isType(yytext))
	{
		printf("\tlex:keyword [%s]\n",yytext);
		return keyword;
	}
	printf("\tlex:identifier [%s]\n",yytext);
	return IDENTIFIER;
}
{CONST_INT} {printf("\tlex:CONST_INT [%s]\n",yytext);
	return CONST_VALUE;}
{CONST_FLOAT} {printf("\tlex:CONST_FLOAT [%s]\n",yytext);return CONST_VALUE;}
{preprocessor} {printf("\tlex:preprocessor symol [%s]\n",yytext);}
[-()<>=+*/;{}.,:] {
printf("\tlex:operator %c caught\n",*yytext);
	return *yytext;
}
[\r\n] ;
"->" {printf("lex:pointer op\n");}
. ;//{printf("lex:discard input [%s]\n",yytext);}
%%


int isType(char* szInput)
{
	int iRet = 0;
	if(strcmp(szInput,"int")==0)
		iRet = TYPE;
	else if(strcmp(szInput,"bool") ==0)
		iRet = TYPE;
	else if(strcmp(szInput,"void") ==0)
		iRet = TYPE;
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