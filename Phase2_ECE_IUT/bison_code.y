%{
    #include <stdio.h>
    #include <string.h>
    #include <iostream>
    #include <iterator>
    #include <map>

    using namespace std;
    extern FILE* yyin;
    extern int yylex();
    int line_num = 0;
    int column_num = 0;
    void yyerror(const char* error);
    char IDS_type[50];
    map<string, string> variable_table;
    map<string, string>::iterator itr;

    struct tnode {
      public:
      bool leaf;
      char syn[50];
      char value[50];
      char token_name[50];
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

%}

%union{

    struct tnode *node;
    int intval;
    float floatval;
    char charval;
    char* strval;
}

%token <strval> TOKEN_CHARCONST TOKEN_INTCONST TOKEN_FLOATCONST TOKEN_STRINGCONST TOKEN_ID;

%token <strval> TOKEN_VOIDTYPE TOKEN_INTTYPE TOKEN_LOOP TOKEN_RETURN ;

%token <strval> TOKEN_IFCONDITION TOKEN_LOGICOP TOKEN_ARITHMATICOP;

%token <strval> TOKEN_BITWISEOP TOKEN_RELATIONOP TOKEN_LOGICOP_NOT;

%token <strval> TOKEN_ASSIGNOP TOKEN_ARITHMATICOP1;

%token <strval> TOKEN_ARITHMATICOP2 TOKEN_LEFTPAREN TOKEN_RIGHTPAREN TOKEN_LCB TOKEN_RCB;

%token <strval> TOKEN_SEMICOLON TOKEN_COMMA TOKEN_UNTIL TOKEN_LB TOKEN_RB;

%token <strval> TOKEN_DOUBLETYPE;

%token <strval> TOKEN_FLOATTYPE TOKEN_CHARTYPE TOKEN_STRINGTYPE TOKEN_MAINFUNC;

%token <strval> TOKEN_BREAKSTMT TOKEN_CONTINUESTMT TOKEN_ELSECONDITION;

%token <strval>  TOKEN_PRFUNC;

%type <node> PROGRAM GLOBAL_DECLARE PGM  F_ARG  STMTS  STMT  PRINTFUNC;

%type <node> TYPE EXP  LOOP  CONDITION  ELSECON  STMT_RETURN  STMT_DECLARE;

%type <node> ARRAY_VAR  IDS  CALL  ARGS  STMT_ASSIGN;


%left TOKEN_RELATIONOP
%right TOKEN_ASSIGNOP
%left TOKEN_LOGICOP
%right TOKEN_LOGICOP_NOT
%left TOKEN_BITWISEOP
%left TOKEN_ARITHMATICOP2
%left TOKEN_ARITHMATICOP1
%right TOKEN_ARITHMATICOP
%left TOKEN_RIGHTPAREN


%%
/************** PROGRAM**************/
PROGRAM:          GLOBAL_DECLARE
                  { root = new tnode;
                    strcpy(root->token_name, "PROGRAM");
                    root->addchild($1);
                  } ;
/************** GLOBAL_DECLARE **************/
GLOBAL_DECLARE:   TYPE TOKEN_ID TOKEN_ASSIGNOP EXP TOKEN_SEMICOLON GLOBAL_DECLARE
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "GLOBAL_DECLARE");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_ID", $2);
                    temp->addchild_str("TOKEN_ASSIGNOP", $3);
                    temp->addchild($4);
                    temp->addchild_str("TOKEN_SEMICOLON", $5);
                    temp->addchild($6);
                    //*****************************************
                    itr =  variable_table.find($2);
                    if(itr != variable_table.end())
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",variable "<<$2<<" already exists.\n";
                    variable_table. insert(pair<string, string>($2, $1->syn));
                    if(strcmp($1->syn, $4->syn) != 0)
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching types in assign operation.\n";
                    //*****************************************
                    $$ = temp;
                  }
                  | PGM
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "GLOBAL_DECLARE");
                    temp->addchild($1);
                    $$ = temp;
                  };
/************** PGM **************/
PGM :		          TYPE TOKEN_ID TOKEN_LEFTPAREN F_ARG TOKEN_RIGHTPAREN  TOKEN_LCB  STMTS  TOKEN_RCB PGM
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "PGM");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_ID", $2);
                    temp->addchild_str("TOKEN_LEFTPAREN", $3);
                    temp->addchild($4);
                    temp->addchild_str("TOKEN_RIGHTPAREN", $5);
                    temp->addchild_str("TOKEN_LCB", $6);
                    temp->addchild($7);
                    temp->addchild_str("TOKEN_RCB", $8);
                    $$ = temp;
                  }
                  |{ struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "PGM");
                    $$ = temp;
                  };/*epsilon*/
/************** F_ARG **************/
F_ARG :		        TYPE TOKEN_ID ARRAY_VAR TOKEN_COMMA F_ARG
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "F_ARG");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_ID", $2);
                    temp->addchild($3);
                    temp->addchild_str("TOKEN_COMMA", $4);
                    temp->addchild($5);
                    //*****************************************
                    variable_table. insert(pair<string, string>($2, $1->syn));
                    //*****************************************
                    $$ = temp;
                  }
                  | TYPE TOKEN_ID ARRAY_VAR
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "F_ARG");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_ID", $2);
                    temp->addchild($3);
                    //*****************************************
                    variable_table. insert(pair<string, string>($2, $1->syn));
                    //*****************************************
                    $$ = temp;
                  }
                  |{ struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "F_ARG");
                    $$ = temp;
                  };/*epsilon*/
/************** STMTS **************/
STMTS :		        STMT TOKEN_SEMICOLON STMTS
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMTS");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_SEMICOLON", $2);
                    temp->addchild($3);
                    $$ = temp;
                  }
                  | CONDITION STMTS
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMTS");
                    temp->addchild($1);
                    temp->addchild($2);
                    $$ = temp;
                  }
                  | LOOP STMTS
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMTS");
                    temp->addchild($1);
                    temp->addchild($2);
                    $$ = temp;
                  }
                  |{ struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMTS");
                    $$ = temp;
                  };/*epsilon*/
/************** STMT **************/
STMT :		        STMT_DECLARE
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT");
                    temp->addchild($1);
                    $$ = temp;
                  }
                  | STMT_ASSIGN
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT");
                    temp->addchild($1);
                    $$ = temp;
                  }
                  | STMT_RETURN
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT");
                    temp->addchild($1);
                    $$ = temp;
                  }
                  | CALL
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT");
                    temp->addchild($1);
                    $$ = temp;
                  }
                  | EXP
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT");
                    temp->addchild($1);
                    $$ = temp;
                  }
                  | PRINTFUNC
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT");
                    temp->addchild($1);
                    $$ = temp;
                  }
                  |{ struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT");
                    $$ = temp;
                  };/*epsilon*/
/************** PRINTFUNC **************/
PRINTFUNC :		    TOKEN_PRFUNC TOKEN_LEFTPAREN EXP TOKEN_RIGHTPAREN
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "PRINTFUNC");
                    temp->addchild_str("TOKEN_PRFUNC", $1);
                    temp->addchild_str("TOKEN_LEFTPAREN", $2);
                    temp->addchild($3);
                    temp->addchild_str("TOKEN_RIGHTPAREN", $4);
                    $$ = temp;
                  };
/************** TYPE **************/
TYPE:             TOKEN_VOIDTYPE
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "TYPE");
                    temp->addchild_str("TOKEN_VOIDTYPE", $1);
                    strcpy(temp->syn, "void");
                    $$ = temp;
                  }
                  | TOKEN_INTTYPE
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "TYPE");
                    temp->addchild_str("TOKEN_INTTYPE", $1);
                    strcpy(temp->syn, "int");
                    $$ = temp;
                  }
                  | TOKEN_DOUBLETYPE
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "TYPE");
                    temp->addchild_str("TOKEN_DOUBLETYPE", $1);
                    strcpy(temp->syn, "double");
                    $$ = temp;
                  }
                  | TOKEN_FLOATTYPE
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "TYPE");
                    temp->addchild_str("TOKEN_FLOATTYPE", $1);
                    strcpy(temp->syn, "float");
                    $$ = temp;
                  }
                  | TOKEN_CHARTYPE
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "TYPE");
                    temp->addchild_str("TOKEN_CHARTYPE", $1);
                    strcpy(temp->syn, "char");
                    $$ = temp;
                  }
                  | TOKEN_STRINGTYPE
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "TYPE");
                    temp->addchild_str("TOKEN_STRINGTYPE", $1);
                    strcpy(temp->syn, "string");
                    $$ = temp;
                  };
/************** EXP **************/
EXP :		          EXP TOKEN_RELATIONOP EXP
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_RELATIONOP", $2);
                    temp->addchild($3);
                    //******************************************
                    if(strcmp($1->syn,$3->syn) != 0)
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching types in assign operation.\n";
                    strcpy(temp->syn,$1->syn);
                    //******************************************
                    $$ = temp;
                  }
		         		  |  EXP TOKEN_ARITHMATICOP2 EXP
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_ARITHMATICOP2", $2);
                    temp->addchild($3);
                    //******************************************
                    if(strcmp($1->syn,$3->syn) != 0)
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching types in arithmatic operation.\n";
                    strcpy(temp->syn,$1->syn);
                    //******************************************
                    $$ = temp;
                  }
		         		  |  EXP TOKEN_ARITHMATICOP1 EXP
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_ARITHMATICOP1", $2);
                    temp->addchild($3);
                    //******************************************
                    if(strcmp($1->syn,$3->syn) != 0)
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching types in arithmatic operation.\n";
                    strcpy(temp->syn,$1->syn);
                    //******************************************
                    $$ = temp;
                  }
		         		  |  EXP TOKEN_ARITHMATICOP EXP
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_ARITHMATICOP", $2);
                    temp->addchild($3);
                    //******************************************
                    if(strcmp($1->syn,$3->syn) != 0)
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching types in arithmatic operation.\n";
                    strcpy(temp->syn,$1->syn);
                    //******************************************
                    $$ = temp;
                  }
		         		  |  EXP TOKEN_LOGICOP EXP
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_LOGICOP", $2);
                    temp->addchild($3);
                    //******************************************
                    if(strcmp($1->syn,$3->syn) != 0)
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching types in arithmatic operation.\n";
                    strcpy(temp->syn,$1->syn);
                    //******************************************
                    $$ = temp;
                  }
		         		  |  EXP TOKEN_BITWISEOP EXP
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_BITWISEOP", $2);
                    temp->addchild($3);
                    //******************************************
                    if(strcmp($1->syn,$3->syn) != 0)
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching types in arithmatic operation.\n";
                    strcpy(temp->syn,$1->syn);
                    //******************************************
                    $$ = temp;
                  }
		         		  |  TOKEN_ID TOKEN_LB EXP TOKEN_RB
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild_str("TOKEN_ID", $1);
                    temp->addchild_str("TOKEN_LB", $2);
                    temp->addchild($3);
                    temp->addchild_str("TOKEN_RB", $4);
                    //******************************************
                    if(strcmp("int",$3->syn) != 0)
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",array index must be integer.\n";
                    itr = variable_table.find($1);
                    if(itr == variable_table.end())
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",variable "<<$1<<" not defined\n";
                    else
                      strcpy(temp->syn,itr->second.c_str());
                    //******************************************
                    $$ = temp;
                  }
		         		  |  TOKEN_LOGICOP_NOT EXP
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild_str("TOKEN_LOGICOP_NOT", $1);
                    temp->addchild($2);
                    //******************************************
                    if(strcmp($2->syn,"string") == 0)
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not before string is illegal.\n";
                    strcpy(temp->syn,$2->syn);
                    //******************************************
                    $$ = temp;
                  }
		         		  |  TOKEN_LEFTPAREN EXP TOKEN_RIGHTPAREN
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild_str("TOKEN_LEFTPAREN", $1);
                    temp->addchild($2);
                    temp->addchild_str("TOKEN_RIGHTPAREN", $3);
                    strcpy(temp->syn,$2->syn);
                    $$ = temp;
                  }
		         		  |  TOKEN_ID
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild_str("TOKEN_ID", $1);
                    //******************************************
                    itr = variable_table.find($1);
                    if(itr == variable_table.end())
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",variable "<<$1<<" not defined\n";
                    else
                      strcpy(temp->syn,itr->second.c_str());
                    //******************************************
                    $$ = temp;
                  }
		         		  |  TOKEN_INTCONST
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild_str("TOKEN_INTCONST", $1);
                    strcpy(temp->syn,"int");
                    $$ = temp;
                  }
		         		  |  TOKEN_STRINGCONST
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild_str("TOKEN_STRINGCONST", $1);
                    strcpy(temp->syn,"string");
                    $$ = temp;
                  }
		         		  |  TOKEN_CHARCONST
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild_str("TOKEN_CHARCONST", $1);
                    strcpy(temp->syn,"char");
                    $$ = temp;
                  }
		         		  |  TOKEN_FLOATCONST
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild_str("TOKEN_FLOATCONST", $1);
                    strcpy(temp->syn,"float");
                    $$ = temp;
                  }
/************** LOOP **************/
LOOP :		        TOKEN_LOOP TOKEN_ID TOKEN_LEFTPAREN EXP TOKEN_UNTIL EXP TOKEN_RIGHTPAREN TOKEN_LCB STMTS TOKEN_RCB
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "LOOP");
                    temp->addchild_str("TOKEN_LOOP", $1);
                    temp->addchild_str("TOKEN_ID", $2);
                    temp->addchild_str("TOKEN_LEFTPAREN", $3);
                    temp->addchild($4);
                    temp->addchild_str("TOKEN_UNTIL", $5);
                    temp->addchild($6);
                    temp->addchild_str("TOKEN_RIGHTPAREN", $7);
                    temp->addchild_str("TOKEN_LCB", $8);
                    temp->addchild($9);
                    temp->addchild_str("TOKEN_RCB", $10);
                    $$ = temp;
                  };
/************** CONDITION **************/
CONDITION :	      TOKEN_IFCONDITION TOKEN_LEFTPAREN EXP TOKEN_RIGHTPAREN TOKEN_LCB STMTS TOKEN_RCB
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "CONDITION");
                    temp->addchild_str("TOKEN_IFCONDITION", $1);
                    temp->addchild_str("TOKEN_LEFTPAREN", $2);
                    temp->addchild($3);
                    temp->addchild_str("TOKEN_RIGHTPAREN", $4);
                    temp->addchild_str("TOKEN_LCB", $5);
                    temp->addchild($6);
                    temp->addchild_str("TOKEN_RCB", $7);
                    $$ = temp;
                  }
                  | TOKEN_IFCONDITION TOKEN_LEFTPAREN EXP TOKEN_RIGHTPAREN TOKEN_LCB STMTS TOKEN_RCB ELSECON
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "CONDITION");
                    temp->addchild_str("TOKEN_IFCONDITION", $1);
                    temp->addchild_str("TOKEN_LEFTPAREN", $2);
                    temp->addchild($3);
                    temp->addchild_str("TOKEN_RIGHTPAREN", $4);
                    temp->addchild_str("TOKEN_LCB", $5);
                    temp->addchild($6);
                    temp->addchild_str("TOKEN_RCB", $7);
                    temp->addchild($8);
                    $$ = temp;
                  };
/************** ELSECON **************/
ELSECON :		      TOKEN_ELSECONDITION TOKEN_LCB STMTS TOKEN_RCB
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "ELSECON");
                    temp->addchild_str("TOKEN_ELSECONDITION", $1);
                    temp->addchild_str("TOKEN_LCB", $2);
                    temp->addchild($3);
                    temp->addchild_str("TOKEN_RCB", $4);
                    $$ = temp;
                  };
/************** STMT_RETURN **************/
STMT_RETURN :	    TOKEN_RETURN EXP
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT_RETURN");
                    temp->addchild_str("TOKEN_RETURN", $1);
                    temp->addchild($2);
                    $$ = temp;
                  };
/************** STMT_DECLARE **************/
STMT_DECLARE :	  TYPE TOKEN_ID ARRAY_VAR {strcpy(IDS_type, $1->syn);}IDS
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT_DECLARE");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_ID", $2);
                    temp->addchild($3);
                    temp->addchild($5);
                    //*****************************************
                    itr =  variable_table.find($2);
                    if(itr != variable_table.end())
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",variable "<<$2<<" already exists.\n";
                    variable_table. insert(pair<string, string>($2, $1->syn));
                    //*****************************************
                    $$ = temp;
                  };
/************** ARRAY_VAR **************/
ARRAY_VAR :		    TOKEN_LB EXP TOKEN_RB
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "ARRAY_VAR");
                    temp->addchild_str("TOKEN_LB", $1);
                    temp->addchild($2);
                    temp->addchild_str("TOKEN_RB", $3);
                    $$ = temp;
                  }
                  | TOKEN_LB TOKEN_RB
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "ARRAY_VAR");
                    temp->addchild_str("TOKEN_LB", $1);
                    temp->addchild_str("TOKEN_RB", $2);
                    $$ = temp;
                  }
                  |{  struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "ARRAY_VAR");
                    $$ = temp;
                  };/*epsilon*/
/************** IDS **************/
IDS :		          STMT_ASSIGN IDS
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "IDS");
                    temp->addchild($1);
                    temp->addchild($2);
                    $$ = temp;
                  }
                  | TOKEN_COMMA TOKEN_ID ARRAY_VAR IDS
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "IDS");
                    temp->addchild_str("TOKEN_COMMA", $1);
                    temp->addchild_str("TOKEN_ID", $2);
                    temp->addchild($3);
                    temp->addchild($4);
                    //*****************************************
                    itr =  variable_table.find($2);
                    if(itr != variable_table.end())
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",variable "<<$2<<" already exists.\n";
                    variable_table. insert(pair<string, string>($2, IDS_type));
                    //*****************************************
                    $$ = temp;
                  }
                  |{ struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "IDS");
                    $$ = temp;
                  };/*epsilon*/
/************** CALL **************/
CALL :		        TOKEN_ID TOKEN_LEFTPAREN ARGS TOKEN_RIGHTPAREN
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "CALL");
                    temp->addchild_str("TOKEN_ID", $1);
                    temp->addchild_str("TOKEN_LEFTPAREN", $2);
                    temp->addchild($3);
                    temp->addchild_str("TOKEN_RIGHTPAREN", $4);
                    $$ = temp;
                  };
/************** ARGS **************/
ARGS :		        EXP ARGS
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "ARGS");
                    temp->addchild($1);
                    temp->addchild($2);
                    $$ = temp;
                  }
                  | TOKEN_COMMA EXP ARGS
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "ARGS");
                    temp->addchild_str("TOKEN_COMMA", $1);
                    temp->addchild($2);
                    temp->addchild($3);
                    $$ = temp;
                  }
                  |{ struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "ARGS");
                    $$ = temp;
                  };/*epsilon*/
/************** STMT_ASSIGN **************/
STMT_ASSIGN :     TOKEN_ID ARRAY_VAR TOKEN_ASSIGNOP EXP
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT_ASSIGN");
                    temp->addchild_str("TOKEN_ID", $1);
                    temp->addchild($2);
                    temp->addchild_str("TOKEN_ASSIGNOP", $3);
                    temp->addchild($4);
                    //******************************************
                    itr = variable_table.find($1);
                    if(itr == variable_table.end())
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",variable "<<$1<<" not defined\n";
                    else if(strcmp(itr->second.c_str(), $4->syn) != 0)
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching types in assign operation.\n";
                    //******************************************
                    $$ = temp;
                  }
                  | TOKEN_ASSIGNOP EXP
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT_ASSIGN");
                    temp->addchild_str("TOKEN_ASSIGNOP", $1);
                    temp->addchild($2);
                    //******************************************
                    if(strcmp(IDS_type, $2->syn) != 0)
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching types in assign operation.\n";
                    //******************************************
                    $$ = temp;
                  };
%%


int main(int argc,char **argv)
{
  FILE *file = fopen(argv[1],"r");
  printByTokenName = (argv[2][0] == '1')?1:0;
  yyin = file;
  yyparse();
  if(root != NULL)
    print(root);
  return 0;
}

void yyerror(const char* error)
{
  cout<<"line:"<<line_num+1<<",column:"<<column_num<<","<<error<<endl;
}
