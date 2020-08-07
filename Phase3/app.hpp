/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_APP_HPP_INCLUDED
# define YY_YY_APP_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOKEN_CHARCONST = 258,
    TOKEN_INTCONST = 259,
    TOKEN_FLOATCONST = 260,
    TOKEN_STRINGCONST = 261,
    TOKEN_ID = 262,
    TOKEN_VOIDTYPE = 263,
    TOKEN_INTTYPE = 264,
    TOKEN_LOOP = 265,
    TOKEN_RETURN = 266,
    TOKEN_IFCONDITION = 267,
    TOKEN_LOGICOP = 268,
    TOKEN_ARITHMATICOP = 269,
    TOKEN_BITWISEOP = 270,
    TOKEN_RELATIONOP = 271,
    TOKEN_LOGICOP_NOT = 272,
    TOKEN_ASSIGNOP = 273,
    TOKEN_ARITHMATICOP1 = 274,
    TOKEN_ARITHMATICOP2 = 275,
    TOKEN_LEFTPAREN = 276,
    TOKEN_RIGHTPAREN = 277,
    TOKEN_LCB = 278,
    TOKEN_RCB = 279,
    TOKEN_SEMICOLON = 280,
    TOKEN_COMMA = 281,
    TOKEN_UNTIL = 282,
    TOKEN_LB = 283,
    TOKEN_RB = 284,
    TOKEN_DOUBLETYPE = 285,
    TOKEN_FLOATTYPE = 286,
    TOKEN_CHARTYPE = 287,
    TOKEN_STRINGTYPE = 288,
    TOKEN_MAINFUNC = 289,
    TOKEN_BREAKSTMT = 290,
    TOKEN_CONTINUESTMT = 291,
    TOKEN_ELSECONDITION = 292,
    TOKEN_PRFUNC = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 110 "bison_code.y" /* yacc.c:1909  */


    struct tnode *node;
    int intval;
    float floatval;
    char charval;
    char* strval;

#line 102 "app.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_APP_HPP_INCLUDED  */
