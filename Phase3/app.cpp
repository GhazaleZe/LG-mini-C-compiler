/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "bison_code.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <string>
    #include <iostream>
    #include <iterator>
    #include <map>
    #include <stack>

    using namespace std;
    extern FILE* yyin;
    extern int yylex();
    int line_num = 0;
    int column_num = 0;
    int exit_num = 0;
    int is_array_var = 0;
    bool error_flag = 1;
    void yyerror(const char* error);
    char IDS_type[50];
    map<string, string> global_variable_table;
    map<string, string> main_variable_table;
    map<string, string> function_variable_table;
    map<string, string> local_variable_table;
    map<string, string> variable_type;
    map<string, int> variable_size;
    map<string, int> function_table;
    map<string, string>::iterator itr;
    map<string, int>::iterator itr1;
    stack<int> return_type;
    int loop_counter=0;
    int labe_counter=0;
    bool in_main = 0;
    int in_local = 0, in_function = 0;

    struct tnode {
      public:
      bool leaf;
      char syn[50];
      char value[50];
      char token_name[50];
      int varsize;
      string code;
      struct tnode *next;
      struct tnode *child;

      tnode()
      {
        next = NULL;
        child = NULL;
        leaf = 0;
      }
      void addchild(tnode* child_adr)
      {
        if(child == NULL)
          child = child_adr;
        else
        {
          struct tnode *ptr;
          for(ptr = child; ptr->next != NULL; ptr = ptr->next);
          ptr->next = child_adr;
        }
      }
      void addchild_str(string tok, string val)
      {
        struct tnode *temp = new struct tnode();
        temp->leaf = 1;
        strcpy(temp->value, val.c_str());
        strcpy(temp->token_name, tok.c_str());
        addchild(temp);
      }

    };//end of class tnode
    struct tnode *root=NULL;
    bool printByTokenName;
    int depth = 0;
    int a_reg_count = 0;
    /********************** print ************************/
    void print(struct tnode *s)
    {
      struct tnode *ptr;
      if(s->leaf)
      {
        for(int i=0;i<depth-1;i++)
          cout<<"\t";
        if(depth)
          cout<<"|___";
        if(printByTokenName)
          cout << s->token_name << "\n";
        else
          cout << s->value << "\n";
      }
      else
      {
        for(int i=0;i<depth-1;i++)
          cout<<"\t";
        if(depth)
          cout<<"|___";
        cout << s->token_name << "\n";
        depth++;
      }
      for(ptr = s->child; ptr != NULL; ptr = ptr->next)
        print(ptr);
      if(!s->leaf)
        depth--;
    }


#line 175 "app.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "app.hpp".  */
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
#line 110 "bison_code.y" /* yacc.c:355  */


    struct tnode *node;
    int intval;
    float floatval;
    char charval;
    char* strval;

#line 263 "app.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_APP_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 280 "app.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   274

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   161,   161,   171,   171,   203,   215,   225,   215,   268,
     273,   310,   344,   349,   359,   368,   377,   382,   389,   396,
     403,   410,   417,   424,   429,   442,   449,   456,   463,   470,
     477,   485,   536,   566,   601,   627,   679,   708,   784,   815,
     829,   892,   908,   915,   922,   930,   930,  1023,  1053,  1085,
    1087,  1099,  1119,  1130,  1130,  1162,  1162,  1202,  1216,  1223,
    1229,  1269,  1302,  1308,  1307,  1343,  1361,  1380,  1385,  1468,
    1479,  1493
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_CHARCONST", "TOKEN_INTCONST",
  "TOKEN_FLOATCONST", "TOKEN_STRINGCONST", "TOKEN_ID", "TOKEN_VOIDTYPE",
  "TOKEN_INTTYPE", "TOKEN_LOOP", "TOKEN_RETURN", "TOKEN_IFCONDITION",
  "TOKEN_LOGICOP", "TOKEN_ARITHMATICOP", "TOKEN_BITWISEOP",
  "TOKEN_RELATIONOP", "TOKEN_LOGICOP_NOT", "TOKEN_ASSIGNOP",
  "TOKEN_ARITHMATICOP1", "TOKEN_ARITHMATICOP2", "TOKEN_LEFTPAREN",
  "TOKEN_RIGHTPAREN", "TOKEN_LCB", "TOKEN_RCB", "TOKEN_SEMICOLON",
  "TOKEN_COMMA", "TOKEN_UNTIL", "TOKEN_LB", "TOKEN_RB", "TOKEN_DOUBLETYPE",
  "TOKEN_FLOATTYPE", "TOKEN_CHARTYPE", "TOKEN_STRINGTYPE",
  "TOKEN_MAINFUNC", "TOKEN_BREAKSTMT", "TOKEN_CONTINUESTMT",
  "TOKEN_ELSECONDITION", "TOKEN_PRFUNC", "$accept", "PROGRAM",
  "GLOBAL_DECLARE", "$@1", "PGM", "$@2", "$@3", "F_ARG", "STMTS", "STMT",
  "PRINTFUNC", "TYPE", "EXP", "LOOP", "$@4", "CONDITION", "M", "ELSECON",
  "STMT_RETURN", "STMT_DECLARE", "$@5", "$@6", "ARRAY_VAR", "IDS", "CALL",
  "$@7", "ARGS", "STMT_ASSIGN", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

#define YYPACT_NINF -80

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-80)))

#define YYTABLE_NINF -60

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,   -80,   -80,   -80,   -80,   -80,   -80,     5,   -80,   -80,
      -1,   -80,    11,    13,    15,   156,    20,   -80,   -80,   -80,
     -80,    12,   156,   156,   206,   -80,    34,   156,    77,   214,
     156,   156,   156,   156,   156,   156,    20,    23,    38,   170,
     -80,    77,    57,   136,   105,    57,   -10,   -80,    65,    18,
      46,   -80,    96,   -80,   178,    20,    62,   156,    64,   161,
      74,    85,    86,   -80,   108,   254,    96,   102,    96,   -80,
     -80,   -80,   -80,   -80,   -80,    52,    18,    98,   254,   156,
      49,   254,   -80,   156,    20,    96,    38,   -80,   115,   -80,
     156,   132,   -80,   189,   161,   224,   234,   -80,   116,   -80,
      -4,   109,   132,   -80,   110,   113,   254,   -80,   -80,   -80,
     -80,   107,    56,   156,   -80,   -80,   117,   134,   -80,    38,
     107,   197,    96,    38,   -80,   156,   118,    36,   244,   106,
     -80,   107,   121,   -80,   -80,   -80,    96,   131,   133,    96,
     -80,   145,   -80
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       9,    25,    26,    27,    28,    29,    30,     0,     2,     5,
       0,     1,     3,     0,     0,     0,    12,    43,    41,    44,
      42,    40,     0,     0,     0,     7,     0,     0,    38,     0,
       0,     0,     0,     0,     0,     0,     9,     0,    59,     0,
      39,    35,    34,    36,    31,    33,    32,     4,     0,     0,
      11,    37,    16,    58,     0,    12,    40,    52,     0,     0,
       0,     0,     0,    22,     0,    21,    16,     0,    16,    19,
      17,    20,    18,    57,    10,    67,     0,     0,    51,     0,
      40,    69,    70,     0,     9,    16,    59,    15,     0,    14,
       0,    67,    63,     0,     0,     0,     0,     8,     0,    13,
      53,     0,    67,    65,     0,    37,    68,    71,    49,    24,
       6,    62,     0,     0,    66,    64,     0,     0,    54,    59,
      62,     0,    16,    59,    56,     0,     0,    62,     0,    47,
      61,    62,     0,    49,    48,    60,    16,     0,     0,    16,
      46,     0,    50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   135,   -80,    88,   -80,   -80,   119,   -55,   -80,
     -80,    10,   -15,   -80,   -80,   -80,    37,   -80,   -80,   -80,
     -80,   -80,   -37,   -38,   -57,   -80,   -64,   -79
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,    13,     9,    14,    37,    25,    61,    62,
      63,    64,    65,    66,    67,    68,   116,   134,    69,    70,
     111,   112,    77,   118,    71,   104,    92,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,    50,    82,   -55,    31,    11,    12,    28,    29,    34,
      10,    87,    39,    89,   -55,    41,    42,    43,    44,    45,
      46,    17,    18,    19,    20,    21,    26,   103,     1,     2,
      99,    15,    -6,   120,    54,    22,    16,   107,   114,    23,
      27,    38,    78,   119,    81,    48,    10,    53,   131,   100,
       3,     4,     5,     6,    59,    17,    18,    19,    20,    21,
      91,    93,   117,   119,    95,    26,    49,   126,    96,    22,
      75,    31,    55,    23,    59,   102,    91,    27,    90,   106,
     -59,   138,   124,    75,   141,    79,   127,    91,    52,   130,
      76,    31,    32,   135,    98,    83,    34,    35,   121,    17,
      18,    19,    20,    56,     1,     2,   -45,    57,    58,    84,
     128,    85,    88,    22,    59,    86,    94,    23,    30,    31,
      32,   -23,   101,   110,    34,    35,     3,     4,     5,     6,
     113,   -57,   115,   117,    60,    17,    18,    19,    20,    21,
     122,   123,   129,   133,   136,    30,    31,    32,    33,    22,
      31,    34,    35,    23,   139,    34,    35,   140,    90,    17,
      18,    19,    20,    21,    17,    18,    19,    20,    80,   142,
     137,    47,    97,    22,    74,     0,     0,    23,    22,     0,
       0,     0,    23,    30,    31,    32,    33,     0,     0,    34,
      35,    30,    31,    32,    33,     0,     0,    34,    35,    51,
       0,     0,    30,    31,    32,    33,     0,    73,    34,    35,
      30,    31,    32,    33,     0,     0,    34,    35,   105,    30,
      31,    32,    33,     0,   125,    34,    35,    30,    31,    32,
      33,    36,     0,    34,    35,     0,    40,    30,    31,    32,
      33,     0,     0,    34,    35,     0,   108,    30,    31,    32,
      33,     0,     0,    34,    35,     0,   109,    30,    31,    32,
      33,     0,     0,    34,    35,     0,   132,    30,    31,    32,
      33,     0,     0,    34,    35
};

static const yytype_int16 yycheck[] =
{
      15,    38,    59,     7,    14,     0,     7,    22,    23,    19,
       0,    66,    27,    68,    18,    30,    31,    32,    33,    34,
      35,     3,     4,     5,     6,     7,    16,    91,     8,     9,
      85,    18,    21,   112,    49,    17,    21,    94,   102,    21,
      28,     7,    57,     7,    59,    22,    36,    29,   127,    86,
      30,    31,    32,    33,    18,     3,     4,     5,     6,     7,
      75,    76,    26,     7,    79,    55,    28,   122,    83,    17,
      21,    14,    26,    21,    18,    90,    91,    28,    26,    94,
      18,   136,   120,    21,   139,    21,   123,   102,    23,   127,
      28,    14,    15,   131,    84,    21,    19,    20,   113,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    24,
     125,    25,    10,    17,    18,     7,    18,    21,    13,    14,
      15,    25,     7,     7,    19,    20,    30,    31,    32,    33,
      21,    18,    22,    26,    38,     3,     4,     5,     6,     7,
      23,     7,    24,    37,    23,    13,    14,    15,    16,    17,
      14,    19,    20,    21,    23,    19,    20,    24,    26,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,    24,
     133,    36,    84,    17,    55,    -1,    -1,    21,    17,    -1,
      -1,    -1,    21,    13,    14,    15,    16,    -1,    -1,    19,
      20,    13,    14,    15,    16,    -1,    -1,    19,    20,    29,
      -1,    -1,    13,    14,    15,    16,    -1,    29,    19,    20,
      13,    14,    15,    16,    -1,    -1,    19,    20,    29,    13,
      14,    15,    16,    -1,    27,    19,    20,    13,    14,    15,
      16,    25,    -1,    19,    20,    -1,    22,    13,    14,    15,
      16,    -1,    -1,    19,    20,    -1,    22,    13,    14,    15,
      16,    -1,    -1,    19,    20,    -1,    22,    13,    14,    15,
      16,    -1,    -1,    19,    20,    -1,    22,    13,    14,    15,
      16,    -1,    -1,    19,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    30,    31,    32,    33,    40,    41,    43,
      50,     0,     7,    42,    44,    18,    21,     3,     4,     5,
       6,     7,    17,    21,    51,    46,    50,    28,    51,    51,
      13,    14,    15,    16,    19,    20,    25,    45,     7,    51,
      22,    51,    51,    51,    51,    51,    51,    41,    22,    28,
      61,    29,    23,    29,    51,    26,     7,    11,    12,    18,
      38,    47,    48,    49,    50,    51,    52,    53,    54,    57,
      58,    63,    66,    29,    46,    21,    28,    61,    51,    21,
       7,    51,    63,    21,    24,    25,     7,    47,    10,    47,
      26,    51,    65,    51,    18,    51,    51,    43,    50,    47,
      61,     7,    51,    65,    64,    29,    51,    63,    22,    22,
       7,    59,    60,    21,    65,    22,    55,    26,    62,     7,
      66,    51,    23,     7,    62,    27,    47,    61,    51,    24,
      62,    66,    22,    37,    56,    62,    23,    55,    47,    23,
      24,    47,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    42,    41,    41,    44,    45,    43,    43,
      46,    46,    46,    47,    47,    47,    47,    48,    48,    48,
      48,    48,    48,    48,    49,    50,    50,    50,    50,    50,
      50,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    53,    52,    54,    54,    55,
      56,    57,    57,    59,    58,    60,    58,    61,    61,    61,
      62,    62,    62,    64,    63,    65,    65,    65,    66,    66,
      66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     7,     1,     0,     0,    11,     0,
       5,     3,     0,     3,     2,     2,     0,     1,     1,     1,
       1,     1,     1,     0,     4,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     4,     2,     3,
       1,     1,     1,     1,     1,     0,    11,     8,     9,     0,
       5,     2,     1,     0,     5,     0,     6,     3,     2,     0,
       5,     4,     0,     0,     5,     2,     3,     0,     4,     2,
       2,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 162 "bison_code.y" /* yacc.c:1646  */
    { root = new tnode;
                    strcpy(root->token_name, "PROGRAM");
                    root->addchild((yyvsp[0].node));
                    (root->code).append("GD:\n");
                    (root->code).append((yyvsp[0].node)->code);
					(root->code).append("\tli $v0, 10\n");
					(root->code).append("\tsyscall\n");
                  }
#line 1493 "app.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 171 "bison_code.y" /* yacc.c:1646  */
    {
                    itr =  global_variable_table.find((yyvsp[0].strval));
                    if(itr != global_variable_table.end())
                    {
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",variable "<<(yyvsp[0].strval)<<" already exists.\n";
                      error_flag = 0;
                    }
                    string new_name = (yyvsp[0].strval);
                    global_variable_table.insert(pair<string, string>((yyvsp[0].strval), new_name));
                    variable_size.insert(pair<string, int>(new_name, 1)); variable_type.insert(pair<string, string>((yyvsp[0].strval), (yyvsp[-1].node)->syn));
                  }
#line 1509 "app.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 182 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "GLOBAL_DECLARE");
                    temp->addchild((yyvsp[-6].node));
                    temp->addchild_str("TOKEN_ID", (yyvsp[-5].strval));
                    temp->addchild_str("TOKEN_ASSIGNOP", (yyvsp[-3].strval));
                    temp->addchild((yyvsp[-2].node));
                    temp->addchild_str("TOKEN_SEMICOLON", (yyvsp[-1].strval));
                    temp->addchild((yyvsp[0].node));
                    //code generation
                    if(error_flag){
                    (temp->code).append((yyvsp[-2].node)->code);
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tsw   $t0, ");
                    itr =  global_variable_table.find((yyvsp[-5].strval));
                    (temp->code).append(itr->second);
                    (temp->code).append("\n");
                    (temp->code).append((yyvsp[0].node)->code);
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 1535 "app.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 204 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "GLOBAL_DECLARE");
                    temp->addchild((yyvsp[0].node));
                    //code generation
                    if(error_flag){
                    (temp->code).append("\tjr $ra\n");//use jal GD in main
                    (temp->code).append((yyvsp[0].node)->code);
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 1550 "app.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 215 "bison_code.y" /* yacc.c:1646  */
    {
                    if(strcmp((yyvsp[-1].node)->syn,"int")==0)
                      return_type.push(1);
                    else
                      return_type.push(0);
                    if(strcmp((yyvsp[0].strval),"main")==0)
                      in_main = 1;
                    else
                      in_function++;
                  }
#line 1565 "app.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 225 "bison_code.y" /* yacc.c:1646  */
    {
                    itr1 =  function_table.find((yyvsp[-3].strval));
                    if(itr1 != function_table.end())
                    {
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",function "<<(yyvsp[-3].strval)<<" already exists.\n";
                      error_flag = 0;
                    }
                    function_table.insert(pair<string, int>((yyvsp[-3].strval),a_reg_count));
                    a_reg_count = 0;
                  }
#line 1580 "app.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 235 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "PGM");
                    temp->addchild((yyvsp[-10].node));
                    temp->addchild_str("TOKEN_ID", (yyvsp[-9].strval));
                    temp->addchild_str("TOKEN_LEFTPAREN", (yyvsp[-7].strval));
                    temp->addchild((yyvsp[-6].node));
                    temp->addchild_str("TOKEN_RIGHTPAREN", (yyvsp[-4].strval));
                    temp->addchild_str("TOKEN_LCB", (yyvsp[-3].strval));
                    temp->addchild((yyvsp[-2].node));
                    temp->addchild_str("TOKEN_RCB", (yyvsp[-1].strval));
                    temp->addchild((yyvsp[0].node));
                    //code generation
                    if(error_flag){
                    (temp->code).append((yyvsp[-9].strval));
                    (temp->code).append(":\n");
                    if(strcmp((yyvsp[-9].strval),"main")==0)
                    {
                      in_main = 0;
                      (temp->code).append("\tjal GD\n");
					  return_type.pop();
                    }
                    else
                    {
                      in_function--;
                      function_variable_table.clear();
					  return_type.pop();
                    }
                    (temp->code).append((yyvsp[-6].node)->code);
                    (temp->code).append((yyvsp[-2].node)->code);
                    (temp->code).append((yyvsp[0].node)->code);
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 1618 "app.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 268 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "PGM");
                    (yyval.node) = temp;
                  }
#line 1627 "app.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 274 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "F_ARG");
                    temp->addchild((yyvsp[-4].node));
                    temp->addchild_str("TOKEN_ID", (yyvsp[-3].strval));
                    temp->addchild((yyvsp[-2].node));
                    temp->addchild_str("TOKEN_COMMA", (yyvsp[-1].strval));
                    temp->addchild((yyvsp[0].node));
                    strcpy(temp->syn,(yyvsp[-4].node)->syn);
                    //*****************************************
                    string new_name = (yyvsp[-3].strval);
                    if(in_main)
                    {
                      new_name = "_" + new_name;
                      main_variable_table.insert(pair<string, string>((yyvsp[-3].strval), new_name));
                      variable_size.insert(pair<string, int>(new_name, 1)); variable_type.insert(pair<string, string>((yyvsp[-3].strval), (yyvsp[-4].node)->syn));
                    }
                    else
                    {
                      new_name = "__" + new_name;
                      function_variable_table.insert(pair<string, string>((yyvsp[-3].strval), new_name));
                      variable_size.insert(pair<string, int>(new_name, 1)); variable_type.insert(pair<string, string>((yyvsp[-3].strval), (yyvsp[-4].node)->syn));
                    }
                    //*****************************************
                    //code generation
                    if(error_flag){
                    char reg_num[5];
                    sprintf(reg_num,"%d",a_reg_count++);
                    (temp->code).append("\tsw   $a");
                    (temp->code).append(reg_num);
                    (temp->code).append(", ");
                    (temp->code).append(new_name);
                    (temp->code).append("\n");
                    (temp->code).append((yyvsp[0].node)->code);
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 1668 "app.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 311 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "F_ARG");
                    temp->addchild((yyvsp[-2].node));
                    temp->addchild_str("TOKEN_ID", (yyvsp[-1].strval));
                    temp->addchild((yyvsp[0].node));
                    strcpy(temp->syn,(yyvsp[-2].node)->syn);
                    //*****************************************
                    string new_name = (yyvsp[-1].strval);
                    if(in_main)
                    {
                      new_name = "_" + new_name;
                      main_variable_table.insert(pair<string, string>((yyvsp[-1].strval), new_name));
                      variable_size.insert(pair<string, int>(new_name, 1)); variable_type.insert(pair<string, string>((yyvsp[-1].strval), (yyvsp[-2].node)->syn));
                    }
                    else
                    {
                      new_name = "__" + new_name;
                      function_variable_table.insert(pair<string, string>((yyvsp[-1].strval), new_name));
                      variable_size.insert(pair<string, int>(new_name, 1)); variable_type.insert(pair<string, string>((yyvsp[-1].strval), (yyvsp[-2].node)->syn));
                    }
                    //*****************************************
                    //code generation
                    if(error_flag){
                    char reg_num[5];
                    sprintf(reg_num,"%d",a_reg_count++);
                    (temp->code).append("\tsw   $a");
                    (temp->code).append(reg_num);
                    (temp->code).append(", ");
                    (temp->code).append(new_name);
                    (temp->code).append("\n");
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 1706 "app.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 344 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "F_ARG");
                    (yyval.node) = temp;
                  }
#line 1715 "app.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 350 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMTS");
                    temp->addchild((yyvsp[-2].node));
                    temp->addchild_str("TOKEN_SEMICOLON", (yyvsp[-1].strval));
                    temp->addchild((yyvsp[0].node));
                    (temp->code).append((yyvsp[-2].node)->code);
                    (temp->code).append((yyvsp[0].node)->code);
                    (yyval.node) = temp;
                  }
#line 1729 "app.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 360 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMTS");
                    temp->addchild((yyvsp[-1].node));
                    temp->addchild((yyvsp[0].node));
                    (temp->code).append((yyvsp[-1].node)->code);
                    (temp->code).append((yyvsp[0].node)->code);
                    (yyval.node) = temp;
                  }
#line 1742 "app.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 369 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMTS");
                    temp->addchild((yyvsp[-1].node));
                    temp->addchild((yyvsp[0].node));
                    (temp->code).append((yyvsp[-1].node)->code);
                    (temp->code).append((yyvsp[0].node)->code);
                    (yyval.node) = temp;
                  }
#line 1755 "app.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 377 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMTS");
                    (yyval.node) = temp;
                  }
#line 1764 "app.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 383 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT");
                    temp->addchild((yyvsp[0].node));
                    (temp->code).append((yyvsp[0].node)->code);
                    (yyval.node) = temp;
                  }
#line 1775 "app.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 390 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT");
                    temp->addchild((yyvsp[0].node));
                    (temp->code).append((yyvsp[0].node)->code);
                    (yyval.node) = temp;
                  }
#line 1786 "app.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 397 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT");
                    temp->addchild((yyvsp[0].node));
                    (temp->code).append((yyvsp[0].node)->code);
                    (yyval.node) = temp;
                  }
#line 1797 "app.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 404 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT");
                    temp->addchild((yyvsp[0].node));
                    (temp->code).append((yyvsp[0].node)->code);
                    (yyval.node) = temp;
                  }
#line 1808 "app.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 411 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT");
                    temp->addchild((yyvsp[0].node));
                    (temp->code).append((yyvsp[0].node)->code);
                    (yyval.node) = temp;
                  }
#line 1819 "app.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 418 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT");
                    temp->addchild((yyvsp[0].node));
                    (temp->code).append((yyvsp[0].node)->code);
                    (yyval.node) = temp;
                  }
#line 1830 "app.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 424 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT");
                    (yyval.node) = temp;
                  }
#line 1839 "app.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 430 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "PRINTFUNC");
                    temp->addchild_str("TOKEN_PRFUNC", (yyvsp[-3].strval));
                    temp->addchild_str("TOKEN_LEFTPAREN", (yyvsp[-2].strval));
                    temp->addchild((yyvsp[-1].node));
                    temp->addchild_str("TOKEN_RIGHTPAREN", (yyvsp[0].strval));
                    (temp->code).append((yyvsp[-1].node)->code);
                    (temp->code).append("\tmove $a0, $sp\n\tli $v0, 1\n\tsyscall\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (yyval.node) = temp;
                  }
#line 1855 "app.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 443 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "TYPE");
                    temp->addchild_str("TOKEN_VOIDTYPE", (yyvsp[0].strval));
                    strcpy(temp->syn, "void");
                    (yyval.node) = temp;
                  }
#line 1866 "app.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 450 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "TYPE");
                    temp->addchild_str("TOKEN_INTTYPE", (yyvsp[0].strval));
                    strcpy(temp->syn, "int");
                    (yyval.node) = temp;
                  }
#line 1877 "app.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 457 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "TYPE");
                    temp->addchild_str("TOKEN_DOUBLETYPE", (yyvsp[0].strval));
                    strcpy(temp->syn, "double");
                    (yyval.node) = temp;
                  }
#line 1888 "app.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 464 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "TYPE");
                    temp->addchild_str("TOKEN_FLOATTYPE", (yyvsp[0].strval));
                    strcpy(temp->syn, "float");
                    (yyval.node) = temp;
                  }
#line 1899 "app.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 471 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "TYPE");
                    temp->addchild_str("TOKEN_CHARTYPE", (yyvsp[0].strval));
                    strcpy(temp->syn, "char");
                    (yyval.node) = temp;
                  }
#line 1910 "app.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 478 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "TYPE");
                    temp->addchild_str("TOKEN_STRINGTYPE", (yyvsp[0].strval));
                    strcpy(temp->syn, "string");
                    (yyval.node) = temp;
                  }
#line 1921 "app.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 486 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild((yyvsp[-2].node));
                    temp->addchild_str("TOKEN_RELATIONOP", (yyvsp[-1].strval));
                    temp->addchild((yyvsp[0].node));
                    //******************************************
                    //if(strcmp($1->syn,$3->syn) != 0)
                      //cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching types in assign operation.\n";
                    strcpy(temp->syn,(yyvsp[-2].node)->syn);
                    //******************************************
                    //code generation
                    if(error_flag){
                    char exit_label[5];
                    sprintf(exit_label,"%d",++exit_num);
                    (temp->code).append((yyvsp[-2].node)->code);
                    (temp->code).append((yyvsp[0].node)->code);
                    (temp->code).append("\tlw   $t1, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tli   $s0, 1\n");
                    if(strcmp((yyvsp[-1].strval),"==")==0)
                        (temp->code).append("\tbeq  $t0, $t1, Exit");

                    else if(strcmp((yyvsp[-1].strval),"!=")==0)
                        (temp->code).append("\tbnq  $t0, $t1, Exit");

                    else if(strcmp((yyvsp[-1].strval),">=")==0)
                        (temp->code).append("\tbge  $t0, $t1, Exit");

                    else if(strcmp((yyvsp[-1].strval),"<=")==0)
                        (temp->code).append("\tble  $t0, $t1, Exit");

                    else if(strcmp((yyvsp[-1].strval),">")==0)
                        (temp->code).append("\tbgt  $t0, $t1, Exit");

                    else if(strcmp((yyvsp[-1].strval),"<")==0)
                        (temp->code).append("\tblt  $t0, $t1, Exit");

                    (temp->code).append(exit_label);
                    (temp->code).append("\n");
                    (temp->code).append("\tli   $s0, 0\n");
                    (temp->code).append("Exit");
                    (temp->code).append(exit_label);
                    (temp->code).append(":\n");
                    (temp->code).append("\taddi $sp, $sp, -4\n");
                    (temp->code).append("\tsw   $s0, ($sp)\n");
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 1976 "app.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 537 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild((yyvsp[-2].node));
                    temp->addchild_str("TOKEN_ARITHMATICOP2", (yyvsp[-1].strval));
                    temp->addchild((yyvsp[0].node));
                    //******************************************
                    //if(strcmp($1->syn,$3->syn) != 0)
                      //cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching types in arithmatic operation.\n";
                    strcpy(temp->syn,(yyvsp[-2].node)->syn);
                    //******************************************
                    //code generation
                    if(error_flag){
                    //+ , -
                    (temp->code).append((yyvsp[-2].node)->code);
                    (temp->code).append((yyvsp[0].node)->code);
                    (temp->code).append("\tlw   $t1, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    if(strcmp((yyvsp[-1].strval),"+")==0)
                        (temp->code).append("\tadd  $s0, $t0, $t1\n");
                    else if(strcmp((yyvsp[-1].strval),"-")==0)
                        (temp->code).append("\tsub  $s0, $t0, $t1\n");
                    (temp->code).append("\taddi $sp, $sp, -4\n");
                    (temp->code).append("\tsw   $s0, ($sp)\n");
                    }//end of code generation

                    (yyval.node) = temp;
                  }
#line 2010 "app.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 567 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild((yyvsp[-2].node));
                    temp->addchild_str("TOKEN_ARITHMATICOP1", (yyvsp[-1].strval));
                    temp->addchild((yyvsp[0].node));
                    //******************************************
                    //if(strcmp($1->syn,$3->syn) != 0)
                      //cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching types in arithmatic operation.\n";
                    strcpy(temp->syn,(yyvsp[-2].node)->syn);
                    //******************************************
                    //code generation
                    if(error_flag){
                    //* , /
                    (temp->code).append((yyvsp[-2].node)->code);
                    (temp->code).append((yyvsp[0].node)->code);
                    (temp->code).append("\tlw   $t1, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    if(strcmp((yyvsp[-1].strval),"*")==0)
                    {
                        (temp->code).append("\tmult $t0, $t1\n");
                        (temp->code).append("\tmflo	$s0\n");
                    }
                    else if(strcmp((yyvsp[-1].strval),"/")==0)
                    {
                        (temp->code).append("\tdiv  $t0, $t1\n");
                        (temp->code).append("\tmflo	$s0\n");
                    }
                    (temp->code).append("\taddi $sp, $sp, -4\n");
                    (temp->code).append("\tsw   $s0, ($sp)\n");
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 2049 "app.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 602 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild((yyvsp[-2].node));
                    temp->addchild_str("TOKEN_ARITHMATICOP", (yyvsp[-1].strval));
                    temp->addchild((yyvsp[0].node));
                    //******************************************
                    //if(strcmp($1->syn,$3->syn) != 0)
                      //cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching types in arithmatic operation.\n";
                    strcpy(temp->syn,(yyvsp[-2].node)->syn);
                    //******************************************
                    //code generation
                    if(error_flag){
                    //^
                    (temp->code).append((yyvsp[-2].node)->code);
                    (temp->code).append((yyvsp[0].node)->code);
                    (temp->code).append("\tlw   $t1, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\txor  $s0, $t0, $t1\n");
                    (temp->code).append("\taddi $sp, $sp, -4\n");
                    (temp->code).append("\tsw   $s0, ($sp)\n");
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 2079 "app.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 628 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild((yyvsp[-2].node));
                    temp->addchild_str("TOKEN_LOGICOP", (yyvsp[-1].strval));
                    temp->addchild((yyvsp[0].node));
                    //******************************************
                    //if(strcmp($1->syn,$3->syn) != 0)
                      //cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching types in arithmatic operation.\n";
                    strcpy(temp->syn,(yyvsp[-2].node)->syn);
                    //******************************************
                    //code generation
                    if(error_flag){
                    //&& , ||
                    char exit_label[5];
                    sprintf(exit_label,"%d",++exit_num);
                    (temp->code).append((yyvsp[-2].node)->code);
                    (temp->code).append((yyvsp[0].node)->code);
                    (temp->code).append("\tlw   $t1, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    if(strcmp((yyvsp[-1].strval),"&&")==0)
                    {
                        (temp->code).append("\tli   $s0, 0\n");
                        (temp->code).append("\tbeq  $t0, $zero, Exit");
                        (temp->code).append(exit_label);
                        (temp->code).append("\n");
                        (temp->code).append("\tbeq  $t1, $zero, Exit");
                        (temp->code).append(exit_label);
                        (temp->code).append("\n");
                        (temp->code).append("\tli   $s0, 1\n");
                    }
                    else if(strcmp((yyvsp[-1].strval),"||")==0)
                    {
                      (temp->code).append("\tli   $s0, 1\n");
                      (temp->code).append("\tbne  $t0, $zero, Exit");
                      (temp->code).append(exit_label);
                      (temp->code).append("\n");
                      (temp->code).append("\tbne $t1, $zero, Exit");
                      (temp->code).append(exit_label);
                      (temp->code).append("\n");
                      (temp->code).append("\tli   $s0, 0\n");
                    }
                    (temp->code).append("Exit");
                    (temp->code).append(exit_label);
                    (temp->code).append(":\n");
                    (temp->code).append("\taddi $sp, $sp, -4\n");
                    (temp->code).append("\tsw   $s0, ($sp)\n");
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 2135 "app.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 680 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild((yyvsp[-2].node));
                    temp->addchild_str("TOKEN_BITWISEOP", (yyvsp[-1].strval));
                    temp->addchild((yyvsp[0].node));
                    //******************************************
                    //if(strcmp($1->syn,$3->syn) != 0)
                      //cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching types in arithmatic operation.\n";
                    strcpy(temp->syn,(yyvsp[-2].node)->syn);
                    //******************************************
                    //code generation
                    if(error_flag){
                    //& , |
                    (temp->code).append((yyvsp[-2].node)->code);
                    (temp->code).append((yyvsp[0].node)->code);
                    (temp->code).append("\tlw   $t1, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    if(strcmp((yyvsp[-1].strval),"&")==0)
                        (temp->code).append("\tand  $s0, $t0, $t1\n");
                    else if(strcmp((yyvsp[-1].strval),"|")==0)
                        (temp->code).append("\tor   $s0, $t0, $t1\n");
                    (temp->code).append("\taddi $sp, $sp, -4\n");
                    (temp->code).append("\tsw   $s0, ($sp)\n");
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 2168 "app.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 709 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild_str("TOKEN_ID", (yyvsp[-3].strval));
                    temp->addchild_str("TOKEN_LB", (yyvsp[-2].strval));
                    temp->addchild((yyvsp[-1].node));
                    temp->addchild_str("TOKEN_RB", (yyvsp[0].strval));
                    //******************************************
                    //if(strcmp("int",$3->syn) != 0)
                      //cout<<"line:"<<line_num+1<<",column:"<<column_num<<",array index must be integer.\n";
                      bool flag = 0;
                      if(in_local)
                      {
                        itr = local_variable_table.find((yyvsp[-3].strval));
                        if(itr == local_variable_table.end())
                          if(in_main)
                          {
                            itr = main_variable_table.find((yyvsp[-3].strval));
                            if(itr != main_variable_table.end())
                              flag = 1;
                          }
                          else
                          {
                            itr = function_variable_table.find((yyvsp[-3].strval));
                            if(itr != function_variable_table.end())
                              flag = 1;
                          }
                        else
                          flag = 1;
                      }
                      else if(in_main)
                      {
                        itr = main_variable_table.find((yyvsp[-3].strval));
                        if(itr != main_variable_table.end())
                          flag = 1;
                      }
                      else if(in_function)
                      {
                        itr = function_variable_table.find((yyvsp[-3].strval));
                        if(itr != function_variable_table.end())
                          flag = 1;
                      }
                      if(!flag)
                      {
                        itr = global_variable_table.find((yyvsp[-3].strval));
                        if(itr != global_variable_table.end())
                          flag = 1;
                      }
                      if(!flag)
                      {
                        cout<<"line:"<<line_num+1<<",column:"<<column_num<<",variable "<<(yyvsp[-3].strval)<<" not defined\n";
                        error_flag = 0;
                      }
                      itr = variable_type.find((yyvsp[-3].strval));
                      if(itr!=variable_type.end())
                        strcpy(temp->syn,itr->second.c_str());

                    //******************************************
                    //code generation
                    if(error_flag){
                    //arr[index]
                    (temp->code).append((yyvsp[-1].node)->code);
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tla   $t1, ");
                    (temp->code).append(itr->second);
                    (temp->code).append("\n");
                    (temp->code).append("\tadd  $t0, $t0, $t0\n");
                    (temp->code).append("\tadd  $t0, $t0, $t0\n");
                    (temp->code).append("\tadd  $t1, $t1, $t0\n");
                    (temp->code).append("\tlw   $s0, ($t1)\n");
                    (temp->code).append("\taddi $sp, $sp, -4\n");
                    (temp->code).append("\tsw   $s0, ($sp)\n");
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 2248 "app.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 785 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild_str("TOKEN_LOGICOP_NOT", (yyvsp[-1].strval));
                    temp->addchild((yyvsp[0].node));
                    //******************************************
                    //if(strcmp($2->syn,"string") == 0)
                      //cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not before string is illegal.\n";
                    strcpy(temp->syn,(yyvsp[0].node)->syn);
                    //******************************************
                    //code generation
                    if(error_flag){
                    //!
                    char exit_label[5];
                    sprintf(exit_label,"%d",++exit_num);
                    (temp->code).append((yyvsp[0].node)->code);
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tli   $s0, 1\n");
                    (temp->code).append("\tbeq $t0, $zero, Exit");
                    (temp->code).append(exit_label);
                    (temp->code).append("\n");
                    (temp->code).append("\tli   $s0, 0\n");
                    (temp->code).append("Exit");
                    (temp->code).append(exit_label);
                    (temp->code).append(":\n");
                    (temp->code).append("\taddi $sp, $sp, -4\n");
                    (temp->code).append("\tsw   $s0, ($sp)\n");
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 2283 "app.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 816 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild_str("TOKEN_LEFTPAREN", (yyvsp[-2].strval));
                    temp->addchild((yyvsp[-1].node));
                    temp->addchild_str("TOKEN_RIGHTPAREN", (yyvsp[0].strval));
                    strcpy(temp->syn,(yyvsp[-1].node)->syn);
                    //code generation
                    if(error_flag){
                    //(e)
                    (temp->code).append((yyvsp[-1].node)->code);
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 2301 "app.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 830 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild_str("TOKEN_ID", (yyvsp[0].strval));
                    //******************************************
                    bool flag = 0;
                    if(in_local)
                    {
                      itr = local_variable_table.find((yyvsp[0].strval));
                      if(itr == local_variable_table.end())
                        if(in_main)
                        {
                          itr = main_variable_table.find((yyvsp[0].strval));
                          if(itr != main_variable_table.end())
                            flag = 1;
                        }
                        else
                        {
                          itr = function_variable_table.find((yyvsp[0].strval));
                          if(itr != function_variable_table.end())
                            flag = 1;
                        }
                      else
                        flag = 1;
                    }
                    else if(in_main)
                    {
                      itr = main_variable_table.find((yyvsp[0].strval));
                      if(itr != main_variable_table.end())
                        flag = 1;
                    }
                    else if(in_function)
                    {
                      itr = function_variable_table.find((yyvsp[0].strval));
                      if(itr != function_variable_table.end())
                        flag = 1;
                    }
                    if(!flag)
                    {
                      itr = global_variable_table.find((yyvsp[0].strval));
                      if(itr != global_variable_table.end())
                        flag = 1;
                    }
                    if(!flag)
                    {
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",variable "<<(yyvsp[0].strval)<<" not defined\n";
                      error_flag = 0;
                    }
                    //******************************************
                    //code generation
                    if(error_flag){
                    //var
                    (temp->code).append("\tlw   $s0, ");
                    (temp->code).append(itr->second);
                    (temp->code).append("\n");
                    (temp->code).append("\taddi $sp, $sp, -4\n");
                    (temp->code).append("\tsw   $s0, ($sp)\n");
                    }//end of code generation
                    itr = variable_type.find((yyvsp[0].strval));
                    if(itr!=variable_type.end())
                      strcpy(temp->syn,itr->second.c_str());
                    (yyval.node) = temp;
                  }
#line 2368 "app.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 893 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild_str("TOKEN_INTCONST", (yyvsp[0].strval));
                    strcpy(temp->syn,"int");
                    temp->varsize = atoi((yyvsp[0].strval));
                    //code generation
                    if(error_flag){
                    (temp->code).append("\tli   $s0, ");
                    (temp->code).append((yyvsp[0].strval));
                    (temp->code).append("\n");
                    (temp->code).append("\taddi $sp, $sp, -4\n");
                    (temp->code).append("\tsw   $s0, ($sp)\n");
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 2388 "app.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 909 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild_str("TOKEN_STRINGCONST", (yyvsp[0].strval));
                    strcpy(temp->syn,"string");
                    (yyval.node) = temp;
                  }
#line 2399 "app.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 916 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild_str("TOKEN_CHARCONST", (yyvsp[0].strval));
                    strcpy(temp->syn,"char");
                    (yyval.node) = temp;
                  }
#line 2410 "app.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 923 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild_str("TOKEN_FLOATCONST", (yyvsp[0].strval));
                    strcpy(temp->syn,"float");
                    (yyval.node) = temp;
                  }
#line 2421 "app.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 930 "bison_code.y" /* yacc.c:1646  */
    {in_local++;}
#line 2427 "app.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 931 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "LOOP");
                    temp->addchild_str("TOKEN_LOOP", (yyvsp[-9].strval));
                    temp->addchild_str("TOKEN_ID", (yyvsp[-8].strval));
                    temp->addchild_str("TOKEN_LEFTPAREN", (yyvsp[-7].strval));
                    temp->addchild((yyvsp[-6].node));
                    temp->addchild_str("TOKEN_UNTIL", (yyvsp[-5].strval));
                    temp->addchild((yyvsp[-4].node));
                    temp->addchild_str("TOKEN_RIGHTPAREN", (yyvsp[-3].strval));
                    temp->addchild_str("TOKEN_LCB", (yyvsp[-2].strval));
                    temp->addchild((yyvsp[-1].node));
                    temp->addchild_str("TOKEN_RCB", (yyvsp[0].strval));
                     in_local--; local_variable_table.clear();
                    //******************************************
                    bool flag = 0;
                    if(in_local)
                    {
                      itr = local_variable_table.find((yyvsp[-8].strval));
                      if(itr == local_variable_table.end())
                        if(in_main)
                        {
                          itr = main_variable_table.find((yyvsp[-8].strval));
                          if(itr != main_variable_table.end())
                            flag = 1;
                        }
                        else
                        {
                          itr = function_variable_table.find((yyvsp[-8].strval));
                          if(itr != function_variable_table.end())
                            flag = 1;
                        }
                      else
                        flag = 1;
                    }
                    else if(in_main)
                    {
                      itr = main_variable_table.find((yyvsp[-8].strval));
                      if(itr != main_variable_table.end())
                        flag = 1;
                    }
                    else if(in_function)
                    {
                      itr = function_variable_table.find((yyvsp[-8].strval));
                      if(itr != function_variable_table.end())
                        flag = 1;
                    }
                    if(!flag)
                    {
                      itr = global_variable_table.find((yyvsp[-8].strval));
                      if(itr != global_variable_table.end())
                        flag = 1;
                    }
                    if(!flag)
                    {
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",variable "<<(yyvsp[-8].strval)<<" not defined\n";
                      error_flag = 0;
                    }
                    //******************************************
                    //code generation
                    if(error_flag){
                    string help1,help2;
                    loop_counter++;
                    help1=to_string(loop_counter);
                    help1="LOOP"+help1;
                    (temp->code).append((yyvsp[-6].node)->code);
                    (temp->code).append((yyvsp[-4].node)->code);
                    (temp->code).append("\tlw   $t4, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tlw   $t3, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tsw   $t4, ");
                    (temp->code).append(itr->second);//momkene nabashe
                    (temp->code).append("\n");
                    labe_counter++;
                    help2=to_string(labe_counter);
                    help2="L"+help2;
                    (temp->code).append(help1);
                    (temp->code).append(":\n");
                    (temp->code).append("\taddi $t3, $t3, 1\n");
                    (temp->code).append("\tbeq  $t3, $t4, ");
                    (temp->code).append(help2);
                    (temp->code).append("\n");
                    (temp->code).append((yyvsp[-1].node)->code);
                    (temp->code).append("\tj    ");
                    (temp->code).append(help1);
                    (temp->code).append("\n");
                    (temp->code).append(help2);
                    (temp->code).append(":\n");
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 2523 "app.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 1024 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "CONDITION");
                    temp->addchild_str("TOKEN_IFCONDITION", (yyvsp[-7].strval));
                    temp->addchild_str("TOKEN_LEFTPAREN", (yyvsp[-6].strval));
                    temp->addchild((yyvsp[-5].node));
                    temp->addchild_str("TOKEN_RIGHTPAREN", (yyvsp[-4].strval));
                    temp->addchild_str("TOKEN_LCB", (yyvsp[-2].strval));
                    temp->addchild((yyvsp[-1].node));
                    temp->addchild_str("TOKEN_RCB", (yyvsp[0].strval));
                    //code generation
                    if(error_flag){
                    string help1;
                    exit_num++;
                    help1=to_string(exit_num);
                    help1="Exit"+help1;
                    (temp->code).append((yyvsp[-5].node)->code);
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tbeq  $t0, $zero, ");
                    (temp->code).append(help1);
                    (temp->code).append("\n");
                    (temp->code).append((yyvsp[-1].node)->code);
                    (temp->code).append(help1);
                    (temp->code).append(":\n");
                    }
                    //end of code generation
                    (yyval.node) = temp;
                     in_local--; local_variable_table.clear();
                  }
#line 2557 "app.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 1054 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "CONDITION");
                    temp->addchild_str("TOKEN_IFCONDITION", (yyvsp[-8].strval));
                    temp->addchild_str("TOKEN_LEFTPAREN", (yyvsp[-7].strval));
                    temp->addchild((yyvsp[-6].node));
                    temp->addchild_str("TOKEN_RIGHTPAREN", (yyvsp[-5].strval));
                    temp->addchild_str("TOKEN_LCB", (yyvsp[-3].strval));
                    temp->addchild((yyvsp[-2].node));
                    temp->addchild_str("TOKEN_RCB", (yyvsp[-1].strval));
                    temp->addchild((yyvsp[0].node));
                    //code generation
                    if(error_flag){
                    string help1;
                    exit_num++;
                    help1=to_string(exit_num);
                    help1="Exit"+help1;
                    (temp->code).append((yyvsp[-6].node)->code);
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tbeq  $t0, $zero, ");
                    (temp->code).append(help1);
                    (temp->code).append("\n");
                    (temp->code).append((yyvsp[-2].node)->code);
                    (temp->code).append(help1);
                    (temp->code).append(":\n");
                    (temp->code).append((yyvsp[0].node)->code);
                    }
                    //end of code generation
                    (yyval.node) = temp;
                     in_local--; local_variable_table.clear();
                  }
#line 2593 "app.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 1085 "bison_code.y" /* yacc.c:1646  */
    {in_local++;}
#line 2599 "app.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 1088 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "ELSECON");
                    temp->addchild_str("TOKEN_ELSECONDITION", (yyvsp[-4].strval));
                    temp->addchild_str("TOKEN_LCB", (yyvsp[-2].strval));
                    temp->addchild((yyvsp[-1].node));
                    temp->addchild_str("TOKEN_RCB", (yyvsp[0].strval));
                    (temp->code).append((yyvsp[-1].node)->code);
                    (yyval.node) = temp;
                     in_local--; local_variable_table.clear();
                  }
#line 2614 "app.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 1100 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT_RETURN");
                    temp->addchild_str("TOKEN_RETURN", (yyvsp[-1].strval));
                    temp->addchild((yyvsp[0].node));

                    if((strcmp((yyvsp[0].node)->syn,"int") == 0&&!return_type.top())||(strcmp((yyvsp[0].node)->syn,"void") == 0&&return_type.top()))
                    {
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching return types.\n";
                      error_flag = 0;
                    }
                    //code generation
                    if(error_flag){
                    (temp->code).append((yyvsp[0].node)->code);
                    (temp->code).append("\tlw $v0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tjr $ra\n");
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 2638 "app.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 1120 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT_RETURN");
                    temp->addchild_str("TOKEN_RETURN", (yyvsp[0].strval));
                    //code generation
                    if(error_flag){
                    (temp->code).append("\tjr $ra\n");
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 2652 "app.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 1130 "bison_code.y" /* yacc.c:1646  */
    {strcpy(IDS_type, (yyvsp[-2].node)->syn);}
#line 2658 "app.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 1131 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT_DECLARE");
                    temp->addchild((yyvsp[-4].node));
                    temp->addchild_str("TOKEN_ID", (yyvsp[-3].strval));
                    temp->addchild((yyvsp[-2].node));
                    temp->addchild((yyvsp[0].node));
                    //*****************************************
                    string new_name = (yyvsp[-3].strval);
                    if(in_local)
                    {
                      new_name = "___" + new_name;
                      local_variable_table.insert(pair<string, string>((yyvsp[-3].strval), new_name));
                    }
                    else if(in_function && !in_main)
                    {
                      new_name = "__" + new_name;
                      function_variable_table.insert(pair<string, string>((yyvsp[-3].strval), new_name));
                    }
                    else if(in_main)
                    {
                      new_name = "_" + new_name;
                      main_variable_table.insert(pair<string, string>((yyvsp[-3].strval), new_name));
                    }
                    variable_size.insert(pair<string, int>(new_name, (yyvsp[-2].node)->varsize)); variable_type.insert(pair<string, string>((yyvsp[-3].strval), (yyvsp[-4].node)->syn));
                    //*****************************************
                    //code generation
                    if(error_flag){
                    (temp->code).append((yyvsp[0].node)->code);
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 2694 "app.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 1162 "bison_code.y" /* yacc.c:1646  */
    {strcpy(IDS_type, (yyvsp[-2].node)->syn);}
#line 2700 "app.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 1163 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT_DECLARE");
                    temp->addchild((yyvsp[-5].node));
                    temp->addchild_str("TOKEN_ID", (yyvsp[-4].strval));
                    temp->addchild((yyvsp[-3].node));
                    temp->addchild((yyvsp[-1].node));
                    temp->addchild((yyvsp[0].node));
                    //*****************************************
                    string new_name = (yyvsp[-4].strval);
                    if(in_local)
                    {
                      new_name = "___" + new_name;
                      local_variable_table.insert(pair<string, string>((yyvsp[-4].strval), new_name));
                    }
                    else if(in_function && !in_main)
                    {
                      new_name = "__" + new_name;
                      function_variable_table.insert(pair<string, string>((yyvsp[-4].strval), new_name));
                    }
                    else if(in_main)
                    {
                      new_name = "_" + new_name;
                      main_variable_table.insert(pair<string, string>((yyvsp[-4].strval), new_name));
                    }
                    variable_size.insert(pair<string, int>(new_name, (yyvsp[-3].node)->varsize)); variable_type.insert(pair<string, string>((yyvsp[-4].strval), (yyvsp[-5].node)->syn));
                    //*****************************************
                    //code generation
                    if(error_flag){
                    (temp->code).append((yyvsp[-1].node)->code);
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tsw   $t0, ");
                    (temp->code).append(new_name);
                    (temp->code).append("\n");
                    (temp->code).append((yyvsp[0].node)->code);
                    }//end of code generation
                    (yyval.node) = temp;
                    }
#line 2743 "app.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 1203 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "ARRAY_VAR");
                    temp->addchild_str("TOKEN_LB", (yyvsp[-2].strval));
                    temp->addchild((yyvsp[-1].node));
                    temp->addchild_str("TOKEN_RB", (yyvsp[0].strval));
                    temp->varsize = (yyvsp[-1].node)->varsize;
                    //code generation
                    if(error_flag){
                    (temp->code).append((yyvsp[-1].node)->code);
                    is_array_var = 1;
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 2761 "app.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 1217 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "ARRAY_VAR");
                    temp->addchild_str("TOKEN_LB", (yyvsp[-1].strval));
                    temp->addchild_str("TOKEN_RB", (yyvsp[0].strval));
                    (yyval.node) = temp;
                  }
#line 2772 "app.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 1223 "bison_code.y" /* yacc.c:1646  */
    {  struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "ARRAY_VAR");
                    temp->varsize = 1;
                    (yyval.node) = temp;
                  }
#line 2782 "app.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 1230 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "IDS");
                    temp->addchild_str("TOKEN_COMMA", (yyvsp[-4].strval));
                    temp->addchild_str("TOKEN_ID", (yyvsp[-3].strval));
                    temp->addchild((yyvsp[-2].node));
                    temp->addchild((yyvsp[-1].node));
                    temp->addchild((yyvsp[0].node));
                    //*****************************************
                    string new_name = (yyvsp[-3].strval);
                    if(in_local)
                    {
                      new_name = "___" + new_name;
                      local_variable_table.insert(pair<string, string>((yyvsp[-3].strval), new_name));
                    }
                    else if(in_function && !in_main)
                    {
                      new_name = "__" + new_name;
                      function_variable_table.insert(pair<string, string>((yyvsp[-3].strval), new_name));
                    }
                    else if(in_main)
                    {
                      new_name = "_" + new_name;
                      main_variable_table.insert(pair<string, string>((yyvsp[-3].strval), new_name));
                    }
                    variable_size.insert(pair<string, int>(new_name, (yyvsp[-2].node)->varsize));
                    variable_type.insert(pair<string, string>((yyvsp[-3].strval), IDS_type));
                    //*****************************************
                    //code generation
                    if(error_flag){
                    (temp->code).append((yyvsp[-1].node)->code);
                    (temp->code).append("\tlw $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tsw   $t0, ");
                    (temp->code).append(new_name);
                    (temp->code).append("\n");
                    (temp->code).append((yyvsp[0].node)->code);
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 2826 "app.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 1270 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "IDS");
                    temp->addchild_str("TOKEN_COMMA", (yyvsp[-3].strval));
                    temp->addchild_str("TOKEN_ID", (yyvsp[-2].strval));
                    temp->addchild((yyvsp[-1].node));
                    temp->addchild((yyvsp[0].node));
                    //*****************************************
                    string new_name = (yyvsp[-2].strval);
                    if(in_local)
                    {
                      new_name = "___" + new_name;
                      local_variable_table.insert(pair<string, string>((yyvsp[-2].strval), new_name));
                    }
                    else if(in_function && !in_main)
                    {
                      new_name = "__" + new_name;
                      function_variable_table.insert(pair<string, string>((yyvsp[-2].strval), new_name));
                    }
                    else if(in_main)
                    {
                      new_name = "_" + new_name;
                      main_variable_table.insert(pair<string, string>((yyvsp[-2].strval), new_name));
                    }
                    variable_size.insert(pair<string, int>(new_name, (yyvsp[-1].node)->varsize));
                    variable_type.insert(pair<string, string>((yyvsp[-2].strval), IDS_type));
                    //*****************************************
                    //code generation
                    if(error_flag){
                    (temp->code).append((yyvsp[0].node)->code);
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 2863 "app.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 1302 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "IDS");
                    (yyval.node) = temp;
                  }
#line 2872 "app.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 1308 "bison_code.y" /* yacc.c:1646  */
    {
                    itr1 = function_table.find((yyvsp[-2].strval));
                    if(itr1 == function_table.end())
                    {
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",function "<<(yyvsp[-2].strval)<<" not defined\n";
                      error_flag = 0;
                    }
                    else if(itr1->second > a_reg_count)
                    {
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<", too few arguments in function call\n";
                      error_flag = 0;
                    }
                    else if(itr1->second < a_reg_count)
                    {
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<", too many arguments in function call\n";
                      error_flag = 0;
                    }
                    a_reg_count = 0;
                  }
#line 2896 "app.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 1327 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "CALL");
                    temp->addchild_str("TOKEN_ID", (yyvsp[-4].strval));
                    temp->addchild_str("TOKEN_LEFTPAREN", (yyvsp[-3].strval));
                    temp->addchild((yyvsp[-2].node));
                    temp->addchild_str("TOKEN_RIGHTPAREN", (yyvsp[0].strval));
                    //code generation
                    if(error_flag){
                    (temp->code).append((yyvsp[-2].node)->code);
                    (temp->code).append("\tjal ");
                    (temp->code).append((yyvsp[-4].strval));
                    (temp->code).append("\n");
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 2916 "app.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 1344 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "ARGS");
                    temp->addchild((yyvsp[-1].node));
                    temp->addchild((yyvsp[0].node));
                    //code generation
                    if(error_flag){
                    char reg_num[5];
                    sprintf(reg_num,"%d",a_reg_count++);
                    (temp->code).append((yyvsp[-1].node)->code);
                    (temp->code).append("\tlw   $a");
                    (temp->code).append(reg_num);
                    (temp->code).append(", $sp\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append((yyvsp[0].node)->code);
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 2938 "app.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 1362 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "ARGS");
                    temp->addchild_str("TOKEN_COMMA", (yyvsp[-2].strval));
                    temp->addchild((yyvsp[-1].node));
                    temp->addchild((yyvsp[0].node));
                    //code generation
                    if(error_flag){
                    char reg_num[5];
                    sprintf(reg_num,"%d",a_reg_count++);
                    (temp->code).append((yyvsp[-1].node)->code);
                    (temp->code).append("\tlw $a");
                    (temp->code).append(reg_num);
                    (temp->code).append(", $sp\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append((yyvsp[0].node)->code);
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 2961 "app.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 1380 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "ARGS");
                    (yyval.node) = temp;
                  }
#line 2970 "app.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 1386 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT_ASSIGN");
                    temp->addchild_str("TOKEN_ID", (yyvsp[-3].strval));
                    temp->addchild((yyvsp[-2].node));
                    temp->addchild_str("TOKEN_ASSIGNOP", (yyvsp[-1].strval));
                    temp->addchild((yyvsp[0].node));
                    //******************************************
                    bool flag = 0;
                    if(in_local)
                    {
                      itr = local_variable_table.find((yyvsp[-3].strval));
                      if(itr == local_variable_table.end())
                        if(in_main)
                        {
                          itr = main_variable_table.find((yyvsp[-3].strval));
                          if(itr != main_variable_table.end())
                            flag = 1;
                        }
                        else
                        {
                          itr = function_variable_table.find((yyvsp[-3].strval));
                          if(itr != function_variable_table.end())
                            flag = 1;
                        }
                      else
                        flag = 1;
                    }
                    else if(in_main)
                    {
                      itr = main_variable_table.find((yyvsp[-3].strval));
                      if(itr != main_variable_table.end())
                        flag = 1;
                    }
                    else if(in_function)
                    {
                      itr = function_variable_table.find((yyvsp[-3].strval));
                      if(itr != function_variable_table.end())
                        flag = 1;
                    }
                    if(!flag)
                    {
                      itr = global_variable_table.find((yyvsp[-3].strval));
                      if(itr != global_variable_table.end())
                        flag = 1;
                    }
                    if(!flag)
                    {
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",variable "<<(yyvsp[-3].strval)<<" not defined\n";
                      error_flag = 0;
                    }
                    //******************************************
                    //code generation
                    if(error_flag){
                    if(is_array_var)
                    {
                      is_array_var = 0;
                      (temp->code).append((yyvsp[-2].node)->code);
                      (temp->code).append("\tlw   $t0, ($sp)\n");
                      (temp->code).append("\taddi $sp, $sp, 4\n");
                      (temp->code).append("\tla   $t1, ");
                      (temp->code).append(itr->second);
                      (temp->code).append("\n");
                      (temp->code).append("\tadd $t0, $t0, $t0\n");
                      (temp->code).append("\tadd $t0, $t0, $t0\n");
                      (temp->code).append("\tadd $t1, $t1, $t0\n");
                      (temp->code).append((yyvsp[0].node)->code);
                      (temp->code).append("\tlw   $s0, ($sp)\n");
                      (temp->code).append("\taddi $sp, $sp, 4\n");
                      (temp->code).append("\tsw   $s0, ($t1)\n");
                    }
                    else
                    {
                      (temp->code).append((yyvsp[0].node)->code);
                      (temp->code).append("\tlw   $s0, ($sp)\n");
                      (temp->code).append("\taddi $sp, $sp, 4\n");
                      (temp->code).append("\tsw   $s0, ");
                      (temp->code).append(itr->second);
                      (temp->code).append("\n");
                    }
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 3057 "app.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 1469 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT_ASSIGN");
                    temp->addchild_str("TOKEN_ASSIGNOP", (yyvsp[-1].strval));
                    temp->addchild((yyvsp[0].node));
                    //code generation
                    if(error_flag){
                    (temp->code).append((yyvsp[0].node)->code);
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 3072 "app.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 1480 "bison_code.y" /* yacc.c:1646  */
    {
                    struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT_ASSIGN");
                    temp->addchild_str("TOKEN_ASSIGNOP", (yyvsp[-1].strval));
                    temp->addchild((yyvsp[0].node));
                    //code generation
                    if(error_flag){
                    (temp->code).append((yyvsp[0].node)->code);
                    (temp->code).append("\taddi $sp, $sp, -4\n");
                    (temp->code).append("\tsw   $v0, ($sp)\n");
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 3090 "app.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 1494 "bison_code.y" /* yacc.c:1646  */
    { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT_ASSIGN");
                    temp->addchild_str("TOKEN_ID", (yyvsp[-3].strval));
                    temp->addchild((yyvsp[-2].node));
                    temp->addchild_str("TOKEN_ASSIGNOP", (yyvsp[-1].strval));
                    temp->addchild((yyvsp[0].node));
                    //*********************************************
                    bool flag = 0;
                    if(in_local)
                    {
                      itr = local_variable_table.find((yyvsp[-3].strval));
                      if(itr == local_variable_table.end())
                        if(in_main)
                        {
                          itr = main_variable_table.find((yyvsp[-3].strval));
                          if(itr != main_variable_table.end())
                            flag = 1;
                        }
                        else
                        {
                          itr = function_variable_table.find((yyvsp[-3].strval));
                          if(itr != function_variable_table.end())
                            flag = 1;
                        }
                      else
                        flag = 1;
                    }
                    else if(in_main)
                    {
                      itr = main_variable_table.find((yyvsp[-3].strval));
                      if(itr != main_variable_table.end())
                        flag = 1;
                    }
                    else if(in_function)
                    {
                      itr = function_variable_table.find((yyvsp[-3].strval));
                      if(itr != function_variable_table.end())
                        flag = 1;
                    }
                    if(!flag)
                    {
                      itr = global_variable_table.find((yyvsp[-3].strval));
                      if(itr != global_variable_table.end())
                        flag = 1;
                    }
                    if(!flag)
                    {
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",variable "<<(yyvsp[-3].strval)<<" not defined\n";
                      error_flag = 0;
                    }
                    //*****************************************
                    //code generation
                    if(error_flag){
                    if(is_array_var)
                    {
                      is_array_var = 0;
                      (temp->code).append((yyvsp[-2].node)->code);
                      (temp->code).append("\tlw   $t0, ($sp)\n");
                      (temp->code).append("\taddi $sp, $sp, 4\n");
                      (temp->code).append("\tla $t1, ");
                      (temp->code).append(itr->second);
                      (temp->code).append("\n");
                      (temp->code).append("\tadd $t0, $t0, $t0\n");
                      (temp->code).append("\tadd $t0, $t0, $t0\n");
                      (temp->code).append("\tadd $t1, $t1, $t0\n");
                      (temp->code).append((yyvsp[0].node)->code);
                      (temp->code).append("\tsw  $v0, ($t1)\n");
                    }
                    else
                    {
                      (temp->code).append((yyvsp[0].node)->code);
                      (temp->code).append("\tsw   $v0, ");
                      (temp->code).append(itr->second);
                      (temp->code).append("\n");
                    }
                    }//end of code generation
                    (yyval.node) = temp;
                  }
#line 3173 "app.cpp" /* yacc.c:1646  */
    break;


#line 3177 "app.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1572 "bison_code.y" /* yacc.c:1906  */



int main(int argc,char **argv)
{
  FILE *file = fopen(argv[1],"r");
  //printByTokenName = (argv[2][0] == '1')?1:0;
  yyin = file;
  yyparse();
  if(root != NULL && error_flag)
  {
    cout<<"\t.data\n";
    for(itr1 = variable_size.begin(); itr1!=variable_size.end(); ++itr1)
    {
      if(itr1->second == 1)
        cout<<itr1->first<<":\t.word 0\n";
      else
        cout<<itr1->first<<":\t.space "<<itr1->second*4<<"\n";
    }
    cout<<"\t.text\n";
    cout<<root->code;
  }
  /*if(root != NULL)
    print(root);*/

  return 0;
}

void yyerror(const char* error)
{
  cout<<"line:"<<line_num+1<<",column:"<<column_num<<","<<error<<endl;
}
