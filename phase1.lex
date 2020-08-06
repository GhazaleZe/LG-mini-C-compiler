%{
//Zehtab
#include <stdio.h>
#include <string.h>
  int line_number=1;// which line
  char current_symbole[1024]; //what is being visited now
  char error_occurrence[1024];//this line has error
  char num_to_string[100]; //digit to string for yyout
  long long int for_error;//out of range error
%}

%option noyywrap

%%
"void"              { strcpy(current_symbole,"TOKEN_VOIDTYPE void\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
"int"               { strcpy(current_symbole,"TOKEN_INTTYPE int\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
"foreach"           { strcpy(current_symbole,"TOKEN_LOOP foreach\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
"return"            { strcpy(current_symbole,"TOKEN_RETURN return\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
"if"                { strcpy(current_symbole,"TOKEN_IF if\n");
                      fprintf(yyout,"%s",current_symbole);
                    }

[+*/-]              { strcpy(current_symbole,"TOKEN_ARITHMATICOP ");
                      strcat(current_symbole,yytext);
                      strcat(current_symbole,"\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
"&&"                { strcpy(current_symbole,"TOKEN_LOGICOP &&\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
"&"                 { strcpy(current_symbole,"TOKEN_BITWISEOP &\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
"|"                 { strcpy(current_symbole,"TOKEN_BITWISEOP |\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
"<="                { strcpy(current_symbole,"TOKEN_RELATIONOP <=\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
"<"                 { strcpy(current_symbole,"TOKEN_RELATIONOP <\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
">"                 { strcpy(current_symbole,"TOKEN_RELATIONOP >\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
">="                { strcpy(current_symbole,"TOKEN_RELATIONOP >=\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
"=="                { strcpy(current_symbole,"TOKEN_RELATIONOP ==\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
"!="                { strcpy(current_symbole,"TOKEN_RELATIONOP !=\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
"="                 { strcpy(current_symbole,"TOKEN_ASSIGNOP =\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
"^"                 { strcpy(current_symbole,"TOKEN_ARITHMATICOP ^\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
"!"                  { strcpy(current_symbole,"TOKEN_LOGICOP !\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
"("                  { strcpy(current_symbole,"TOKEN_LEFTPAREN \(\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
")"                  { strcpy(current_symbole,"TOKEN_RIGHTPAREN )\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
"{"                  { strcpy(current_symbole,"TOKEN_LCB {\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
"}"                  { strcpy(current_symbole,"TOKEN_RCB }\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
";"                  { strcpy(current_symbole,"TOKEN_SEMICOLON ;\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
","                  { strcpy(current_symbole,"TOKEN_COMMA ,\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
".."                 { strcpy(current_symbole,"TOKEN_UNTIL ..\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
"["                  { strcpy(current_symbole,"TOKEN_LB [\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
"]"                  { strcpy(current_symbole,"TOKEN_RB ]\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
\n                  {
                      line_number=line_number+1;
                      strcpy(current_symbole,"TOKEN_WHITESPACE \\n\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
\t                  { strcpy(current_symbole,"TOKEN_WHITESPACE \\t\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
" "                 { strcpy(current_symbole,"TOKEN_WHITESPACE [space]\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
\/\/.*              { strcpy(current_symbole,"TOKEN_COMMENT ");
                      strcat(current_symbole,yytext);
                      strcat(current_symbole,"\n");
                      fprintf(yyout,"%s",current_symbole);
                    }
"/*"((\*+[^/])|([^*]))*"*/"    { strcpy(current_symbole,"TOKEN_COMMENT ");
                                 strcat(current_symbole,yytext);
                                 strcat(current_symbole,"\n");
                                 fprintf(yyout,"%s",current_symbole);
                               }
"/*"((\*+[^/])|([^*]))*        {
                                  strcpy(error_occurrence,"error in line ");
                                  sprintf(num_to_string, "%d", line_number);
                                  strcat(error_occurrence,num_to_string);
                                  strcat(error_occurrence," : unclosed comment section\n");
                                  fprintf(yyout,"%s",error_occurrence);
                                }
"*/"                            {
                                  strcpy(error_occurrence,"error in line ");
                                  sprintf(num_to_string, "%d", line_number);
                                  strcat(error_occurrence,num_to_string);
                                  strcat(error_occurrence," : unopend comment section\n");
                                  fprintf(yyout,"%s",error_occurrence);
                                }
"double"                        { strcpy(current_symbole,"TOKEN_DOUBLETYPE double\n");
                                  fprintf(yyout,"%s",current_symbole);
                                }
"float"                         { strcpy(current_symbole,"TOKEN_FLOATTYPE float\n");
                                  fprintf(yyout,"%s",current_symbole);
                                }
"char"                          { strcpy(current_symbole,"TOKEN_CHARTYPE char\n");
                                  fprintf(yyout,"%s",current_symbole);
                                }
"string"                        { strcpy(current_symbole,"TOKEN_STRINGTYPE string\n");
                                  fprintf(yyout,"%s",current_symbole);
                                }
"main"                          { strcpy(current_symbole,"TOKEN_MAINFUNC main\n");
                                  fprintf(yyout,"%s",current_symbole);
                                }
"break"                         { strcpy(current_symbole,"TOKEN_BREAKSTMT break\n");
                                  fprintf(yyout,"%s",current_symbole);
                                }
"continue"                      { strcpy(current_symbole,"TOKEN_CONTINUESTMT continue\n");
                                  fprintf(yyout,"%s",current_symbole);
                                }
-{0,1}[0-9]+                      {
                                  sscanf(yytext, "%lld", &for_error);
                                  if (for_error > 2147483647){
                                    strcpy(error_occurrence,"error in line ");
                                    sprintf(num_to_string, "%d", line_number);
                                    strcat(error_occurrence,num_to_string);
                                    strcat(error_occurrence," : integer constant is out of range\n");
                                    fprintf(yyout,"%s",error_occurrence);
                                  }
                                  else if (for_error < -2147483648){
                                    strcpy(error_occurrence,"error in line ");
                                    sprintf(num_to_string, "%d", line_number);
                                    strcat(error_occurrence,num_to_string);
                                    strcat(error_occurrence," : integer constant is out of range\n");
                                    fprintf(yyout,"%s",error_occurrence);
                                    }
                                    else {
                                      strcpy(current_symbole,"TOKEN_INTCONST ");
                                      strcat(current_symbole,yytext);
                                      strcat(current_symbole,"\n");
                                      fprintf(yyout,"%s",current_symbole);
                                    }
                                  }
[0-9]+"."[0-9]+    {
                                  strcpy(current_symbole,"TOKEN_FLOATCONST ");
                                  strcat(current_symbole,yytext);
                                  strcat(current_symbole,"\n");
                                  fprintf(yyout,"%s",current_symbole);
                                }
["][a-zA-Z_0-9\*#" "]*["]       {
                                  strcpy(current_symbole,"TOKEN_STRINGCONST ");
                                  strcat(current_symbole,yytext);
                                  strcat(current_symbole,"\n");
                                  fprintf(yyout,"%s",current_symbole);
                                }
['][a-zA-z0-9#][']               {
                                  strcpy(current_symbole,"TOKEN_CHARCONST ");
                                  strcat(current_symbole,yytext);
                                  strcat(current_symbole,"\n");
                                  fprintf(yyout,"%s",current_symbole);
                                }

[a-zA-Z_][a-zA-Z_0-9]* {  if (yyleng>32){
                            strcpy(error_occurrence,"error in line ");
                            sprintf(num_to_string, "%d",line_number);
                            strcat(error_occurrence,num_to_string);
                            strcat(error_occurrence," : size of variable is out of range\n");
                            fprintf(yyout,"%s",error_occurrence);
                          }
                          else{
                            strcpy(current_symbole,"TOKEN_ID ");
                            strcat(current_symbole,yytext);
                            strcat(current_symbole,"\n");
                            fprintf(yyout,"%s",current_symbole);
                          }
                        }
[0-9]+[a-zA-Z_0-9]*     {
                            strcpy(error_occurrence,"error in line ");
                            sprintf(num_to_string, "%d",line_number);
                            strcat(error_occurrence,num_to_string);
                            strcat(error_occurrence," : wrong id definition\n");
                            fprintf(yyout,"%s",error_occurrence);
                        }
%%

int main(int argc, char** argv){
  FILE *f = fopen("test.txt","r");
  yyin = f;
  FILE *fb = fopen("SymbolTable.txt", "w");
  yyout = fb;
  yylex();
  return 0;
}
