%{
    #include <stdio.h>
    #include <string.h>
    #include <iostream>
    #include "./app.hpp"
    extern int line_num;
    extern int column_num;
    using namespace std;
%}

%option noyywrap
%x comment

%%
"else"                {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                       return TOKEN_ELSECONDITION;}
"print"               {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                       return TOKEN_PRFUNC;}
"void"                {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_VOIDTYPE;}
"int"                 { yylval.strval=strdup(yytext);
                       column_num += yyleng;
                        return TOKEN_INTTYPE;}
"foreach"             { yylval.strval=strdup(yytext);
                       column_num += yyleng;
                        return TOKEN_LOOP;}
"return"              {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                       return TOKEN_RETURN;}
"if"                  {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                       return TOKEN_IFCONDITION;}
"+"                   {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                       return TOKEN_ARITHMATICOP2;}
"-"                   {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_ARITHMATICOP2;}
"/"                   {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_ARITHMATICOP1;}

"*"                   {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_ARITHMATICOP1;}
"&&"                  {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_LOGICOP;}
"||"                  {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_LOGICOP;}
"&"                   {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_BITWISEOP;}
"|"                   {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_BITWISEOP;}

"=="                  {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_RELATIONOP;}
"!="                  {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                       return TOKEN_RELATIONOP;}
">="                  {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_RELATIONOP;}
"<="                  {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_RELATIONOP;}

">"                   {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_RELATIONOP;}
"<"                   {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_RELATIONOP;}
"="                   {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_ASSIGNOP;}
"!"                   {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_LOGICOP_NOT;}
"^"                   {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_ARITHMATICOP;}
"("                   {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_LEFTPAREN;}
")"                   {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                       return TOKEN_RIGHTPAREN;}
"{"                   {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_LCB;}
"}"                   {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                       return TOKEN_RCB;}
";"                   {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_SEMICOLON;}
","                   {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_COMMA;}
".."                  {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_UNTIL;}
"["                   {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_LB;}
"]"                   {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                       return TOKEN_RB;}
\n                    {/*return TOKEN_WHITESPACE;*/++line_num; column_num=0;}
\t                    {/*return TOKEN_WHITESPACE;*/}
" "                   {/*return TOKEN_WHITESPACE;*/}
"*/"                  {printf("error in line %d : unopend comment section\n",line_num+1);exit(0);}
"double"              {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_DOUBLETYPE;}
"float"               {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_FLOATTYPE;}
"char"                {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_CHARTYPE;}
"string"              {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_STRINGTYPE;}
"main"                {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_ID;/*return TOKEN_MAINFUNC;*/}
"break"               {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_BREAKSTMT;}
"continue"            {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_CONTINUESTMT;}

-?[0-9]*              {long a = atol(yytext);
                       if(a > 2147483648 || a < -2147483649 || yyleng > 10)
                        {
                          printf("error in line %d : integer constant is out of range\n",line_num+1);
                          exit(0);
                        }
                        yylval.strval=strdup(yytext);
                       column_num += yyleng;
                        return TOKEN_INTCONST;
                      }
(')(.)(')             { yylval.strval=strdup(yytext);
                       column_num += yyleng;
                        return TOKEN_CHARCONST;}
"\"".*"\""             {yylval.strval=strdup(yytext);
                       column_num += yyleng;
                        return TOKEN_STRINGCONST;}
[a-zA-Z][a-zA-Z0-9_]* {if(yyleng>31)
                        {
                          printf("error in line %d : wrong id definition\n",line_num+1);
                          exit(0);
                        }
                        yylval.strval=strdup(yytext);
                       column_num += yyleng;
                        return TOKEN_ID;
                      }
[0-9_]+[a-zA-Z][a-zA-Z0-9_]* {printf("error in line %d : wrong id definition\n",line_num+1);
                              exit(0);}
((-?[0-9]+"."[0-9]+)|(-?[0-9]+"."[0-9]+"e"-?[0-9]+)) {
                      yylval.strval=strdup(yytext);
                       column_num += yyleng;
                      return TOKEN_FLOATCONST;}
"//".*\n              {/*return TOKEN_COMMENT;*/++line_num;column_num=0;}
"/*"                  BEGIN(comment);
<comment>[^*\n]*      ;
<comment>"*"+[^*/\n]* ;
<comment>\n           {++line_num;column_num=0;}
<comment>"*"+"/"      {/*return TOKEN_COMMENT;*/++line_num;BEGIN(INITIAL);}
<comment><<EOF>>      {printf("error in line %d : unclosed comment section\n",line_num-1);exit(0);}
%%
