%{
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
                    (root->code).append("GD:\n");
                    (root->code).append($1->code);
					(root->code).append("\tli $v0, 10\n");
					(root->code).append("\tsyscall\n");
                  } ;
/************** GLOBAL_DECLARE **************/
GLOBAL_DECLARE:   TYPE TOKEN_ID{
                    itr =  global_variable_table.find($2);
                    if(itr != global_variable_table.end())
                    {
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",variable "<<$2<<" already exists.\n";
                      error_flag = 0;
                    }
                    string new_name = $2;
                    global_variable_table.insert(pair<string, string>($2, new_name));
                    variable_size.insert(pair<string, int>(new_name, 1)); variable_type.insert(pair<string, string>($2, $1->syn));
                  } TOKEN_ASSIGNOP EXP TOKEN_SEMICOLON GLOBAL_DECLARE
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "GLOBAL_DECLARE");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_ID", $2);
                    temp->addchild_str("TOKEN_ASSIGNOP", $4);
                    temp->addchild($5);
                    temp->addchild_str("TOKEN_SEMICOLON", $6);
                    temp->addchild($7);
                    //code generation
                    if(error_flag){
                    (temp->code).append($5->code);
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tsw   $t0, ");
                    itr =  global_variable_table.find($2);
                    (temp->code).append(itr->second);
                    (temp->code).append("\n");
                    (temp->code).append($7->code);
                    }//end of code generation
                    $$ = temp;
                  }
                  | PGM
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "GLOBAL_DECLARE");
                    temp->addchild($1);
                    //code generation
                    if(error_flag){
                    (temp->code).append("\tjr $ra\n");//use jal GD in main
                    (temp->code).append($1->code);
                    }//end of code generation
                    $$ = temp;
                  };
/************** PGM **************/
PGM :		          TYPE TOKEN_ID{
                    if(strcmp($1->syn,"int")==0)
                      return_type.push(1);
                    else
                      return_type.push(0);
                    if(strcmp($2,"main")==0)
                      in_main = 1;
                    else
                      in_function++;
                  } TOKEN_LEFTPAREN F_ARG
                  {
                    itr1 =  function_table.find($2);
                    if(itr1 != function_table.end())
                    {
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",function "<<$2<<" already exists.\n";
                      error_flag = 0;
                    }
                    function_table.insert(pair<string, int>($2,a_reg_count));
                    a_reg_count = 0;
                  } TOKEN_RIGHTPAREN  TOKEN_LCB  STMTS  TOKEN_RCB PGM
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "PGM");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_ID", $2);
                    temp->addchild_str("TOKEN_LEFTPAREN", $4);
                    temp->addchild($5);
                    temp->addchild_str("TOKEN_RIGHTPAREN", $7);
                    temp->addchild_str("TOKEN_LCB", $8);
                    temp->addchild($9);
                    temp->addchild_str("TOKEN_RCB", $10);
                    temp->addchild($11);
                    //code generation
                    if(error_flag){
                    (temp->code).append($2);
                    (temp->code).append(":\n");
                    if(strcmp($2,"main")==0)
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
                    (temp->code).append($5->code);
                    (temp->code).append($9->code);
                    (temp->code).append($11->code);
                    }//end of code generation
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
                    strcpy(temp->syn,$1->syn);
                    //*****************************************
                    string new_name = $2;
                    if(in_main)
                    {
                      new_name = "_" + new_name;
                      main_variable_table.insert(pair<string, string>($2, new_name));
                      variable_size.insert(pair<string, int>(new_name, 1)); variable_type.insert(pair<string, string>($2, $1->syn));
                    }
                    else
                    {
                      new_name = "__" + new_name;
                      function_variable_table.insert(pair<string, string>($2, new_name));
                      variable_size.insert(pair<string, int>(new_name, 1)); variable_type.insert(pair<string, string>($2, $1->syn));
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
                    (temp->code).append($5->code);
                    }//end of code generation
                    $$ = temp;
                  }
                  | TYPE TOKEN_ID ARRAY_VAR
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "F_ARG");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_ID", $2);
                    temp->addchild($3);
                    strcpy(temp->syn,$1->syn);
                    //*****************************************
                    string new_name = $2;
                    if(in_main)
                    {
                      new_name = "_" + new_name;
                      main_variable_table.insert(pair<string, string>($2, new_name));
                      variable_size.insert(pair<string, int>(new_name, 1)); variable_type.insert(pair<string, string>($2, $1->syn));
                    }
                    else
                    {
                      new_name = "__" + new_name;
                      function_variable_table.insert(pair<string, string>($2, new_name));
                      variable_size.insert(pair<string, int>(new_name, 1)); variable_type.insert(pair<string, string>($2, $1->syn));
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
                    (temp->code).append($1->code);
                    (temp->code).append($3->code);
                    $$ = temp;
                  }
                  | CONDITION STMTS
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMTS");
                    temp->addchild($1);
                    temp->addchild($2);
                    (temp->code).append($1->code);
                    (temp->code).append($2->code);
                    $$ = temp;
                  }
                  | LOOP STMTS
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMTS");
                    temp->addchild($1);
                    temp->addchild($2);
                    (temp->code).append($1->code);
                    (temp->code).append($2->code);
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
                    (temp->code).append($1->code);
                    $$ = temp;
                  }
                  | STMT_ASSIGN
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT");
                    temp->addchild($1);
                    (temp->code).append($1->code);
                    $$ = temp;
                  }
                  | STMT_RETURN
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT");
                    temp->addchild($1);
                    (temp->code).append($1->code);
                    $$ = temp;
                  }
                  | CALL
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT");
                    temp->addchild($1);
                    (temp->code).append($1->code);
                    $$ = temp;
                  }
                  | EXP
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT");
                    temp->addchild($1);
                    (temp->code).append($1->code);
                    $$ = temp;
                  }
                  | PRINTFUNC
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT");
                    temp->addchild($1);
                    (temp->code).append($1->code);
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
                    (temp->code).append($3->code);
                    (temp->code).append("\tmove $a0, $sp\n\tli $v0, 1\n\tsyscall\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
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
                    //if(strcmp($1->syn,$3->syn) != 0)
                      //cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching types in assign operation.\n";
                    strcpy(temp->syn,$1->syn);
                    //******************************************
                    //code generation
                    if(error_flag){
                    char exit_label[5];
                    sprintf(exit_label,"%d",++exit_num);
                    (temp->code).append($1->code);
                    (temp->code).append($3->code);
                    (temp->code).append("\tlw   $t1, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tli   $s0, 1\n");
                    if(strcmp($2,"==")==0)
                        (temp->code).append("\tbeq  $t0, $t1, Exit");

                    else if(strcmp($2,"!=")==0)
                        (temp->code).append("\tbnq  $t0, $t1, Exit");

                    else if(strcmp($2,">=")==0)
                        (temp->code).append("\tbge  $t0, $t1, Exit");

                    else if(strcmp($2,"<=")==0)
                        (temp->code).append("\tble  $t0, $t1, Exit");

                    else if(strcmp($2,">")==0)
                        (temp->code).append("\tbgt  $t0, $t1, Exit");

                    else if(strcmp($2,"<")==0)
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
                    $$ = temp;
                  }
		         		  |  EXP TOKEN_ARITHMATICOP2 EXP
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_ARITHMATICOP2", $2);
                    temp->addchild($3);
                    //******************************************
                    //if(strcmp($1->syn,$3->syn) != 0)
                      //cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching types in arithmatic operation.\n";
                    strcpy(temp->syn,$1->syn);
                    //******************************************
                    //code generation
                    if(error_flag){
                    //+ , -
                    (temp->code).append($1->code);
                    (temp->code).append($3->code);
                    (temp->code).append("\tlw   $t1, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    if(strcmp($2,"+")==0)
                        (temp->code).append("\tadd  $s0, $t0, $t1\n");
                    else if(strcmp($2,"-")==0)
                        (temp->code).append("\tsub  $s0, $t0, $t1\n");
                    (temp->code).append("\taddi $sp, $sp, -4\n");
                    (temp->code).append("\tsw   $s0, ($sp)\n");
                    }//end of code generation

                    $$ = temp;
                  }
		         		  |  EXP TOKEN_ARITHMATICOP1 EXP
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_ARITHMATICOP1", $2);
                    temp->addchild($3);
                    //******************************************
                    //if(strcmp($1->syn,$3->syn) != 0)
                      //cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching types in arithmatic operation.\n";
                    strcpy(temp->syn,$1->syn);
                    //******************************************
                    //code generation
                    if(error_flag){
                    //* , /
                    (temp->code).append($1->code);
                    (temp->code).append($3->code);
                    (temp->code).append("\tlw   $t1, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    if(strcmp($2,"*")==0)
                    {
                        (temp->code).append("\tmult $t0, $t1\n");
                        (temp->code).append("\tmflo	$s0\n");
                    }
                    else if(strcmp($2,"/")==0)
                    {
                        (temp->code).append("\tdiv  $t0, $t1\n");
                        (temp->code).append("\tmflo	$s0\n");
                    }
                    (temp->code).append("\taddi $sp, $sp, -4\n");
                    (temp->code).append("\tsw   $s0, ($sp)\n");
                    }//end of code generation
                    $$ = temp;
                  }
		         		  |  EXP TOKEN_ARITHMATICOP EXP
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_ARITHMATICOP", $2);
                    temp->addchild($3);
                    //******************************************
                    //if(strcmp($1->syn,$3->syn) != 0)
                      //cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching types in arithmatic operation.\n";
                    strcpy(temp->syn,$1->syn);
                    //******************************************
                    //code generation
                    if(error_flag){
                    //^
                    (temp->code).append($1->code);
                    (temp->code).append($3->code);
                    (temp->code).append("\tlw   $t1, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\txor  $s0, $t0, $t1\n");
                    (temp->code).append("\taddi $sp, $sp, -4\n");
                    (temp->code).append("\tsw   $s0, ($sp)\n");
                    }//end of code generation
                    $$ = temp;
                  }
		         		  |  EXP TOKEN_LOGICOP EXP
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_LOGICOP", $2);
                    temp->addchild($3);
                    //******************************************
                    //if(strcmp($1->syn,$3->syn) != 0)
                      //cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching types in arithmatic operation.\n";
                    strcpy(temp->syn,$1->syn);
                    //******************************************
                    //code generation
                    if(error_flag){
                    //&& , ||
                    char exit_label[5];
                    sprintf(exit_label,"%d",++exit_num);
                    (temp->code).append($1->code);
                    (temp->code).append($3->code);
                    (temp->code).append("\tlw   $t1, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    if(strcmp($2,"&&")==0)
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
                    else if(strcmp($2,"||")==0)
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
                    $$ = temp;
                  }
		         		  |  EXP TOKEN_BITWISEOP EXP
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_BITWISEOP", $2);
                    temp->addchild($3);
                    //******************************************
                    //if(strcmp($1->syn,$3->syn) != 0)
                      //cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching types in arithmatic operation.\n";
                    strcpy(temp->syn,$1->syn);
                    //******************************************
                    //code generation
                    if(error_flag){
                    //& , |
                    (temp->code).append($1->code);
                    (temp->code).append($3->code);
                    (temp->code).append("\tlw   $t1, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    if(strcmp($2,"&")==0)
                        (temp->code).append("\tand  $s0, $t0, $t1\n");
                    else if(strcmp($2,"|")==0)
                        (temp->code).append("\tor   $s0, $t0, $t1\n");
                    (temp->code).append("\taddi $sp, $sp, -4\n");
                    (temp->code).append("\tsw   $s0, ($sp)\n");
                    }//end of code generation
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
                    //if(strcmp("int",$3->syn) != 0)
                      //cout<<"line:"<<line_num+1<<",column:"<<column_num<<",array index must be integer.\n";
                      bool flag = 0;
                      if(in_local)
                      {
                        itr = local_variable_table.find($1);
                        if(itr == local_variable_table.end())
                          if(in_main)
                          {
                            itr = main_variable_table.find($1);
                            if(itr != main_variable_table.end())
                              flag = 1;
                          }
                          else
                          {
                            itr = function_variable_table.find($1);
                            if(itr != function_variable_table.end())
                              flag = 1;
                          }
                        else
                          flag = 1;
                      }
                      else if(in_main)
                      {
                        itr = main_variable_table.find($1);
                        if(itr != main_variable_table.end())
                          flag = 1;
                      }
                      else if(in_function)
                      {
                        itr = function_variable_table.find($1);
                        if(itr != function_variable_table.end())
                          flag = 1;
                      }
                      if(!flag)
                      {
                        itr = global_variable_table.find($1);
                        if(itr != global_variable_table.end())
                          flag = 1;
                      }
                      if(!flag)
                      {
                        cout<<"line:"<<line_num+1<<",column:"<<column_num<<",variable "<<$1<<" not defined\n";
                        error_flag = 0;
                      }
                      itr = variable_type.find($1);
                      if(itr!=variable_type.end())
                        strcpy(temp->syn,itr->second.c_str());

                    //******************************************
                    //code generation
                    if(error_flag){
                    //arr[index]
                    (temp->code).append($3->code);
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
                    $$ = temp;
                  }
		         		  |  TOKEN_LOGICOP_NOT EXP
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild_str("TOKEN_LOGICOP_NOT", $1);
                    temp->addchild($2);
                    //******************************************
                    //if(strcmp($2->syn,"string") == 0)
                      //cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not before string is illegal.\n";
                    strcpy(temp->syn,$2->syn);
                    //******************************************
                    //code generation
                    if(error_flag){
                    //!
                    char exit_label[5];
                    sprintf(exit_label,"%d",++exit_num);
                    (temp->code).append($2->code);
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
                    $$ = temp;
                  }
		         		  |  TOKEN_LEFTPAREN EXP TOKEN_RIGHTPAREN
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild_str("TOKEN_LEFTPAREN", $1);
                    temp->addchild($2);
                    temp->addchild_str("TOKEN_RIGHTPAREN", $3);
                    strcpy(temp->syn,$2->syn);
                    //code generation
                    if(error_flag){
                    //(e)
                    (temp->code).append($2->code);
                    }//end of code generation
                    $$ = temp;
                  }
		         		  |  TOKEN_ID
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild_str("TOKEN_ID", $1);
                    //******************************************
                    bool flag = 0;
                    if(in_local)
                    {
                      itr = local_variable_table.find($1);
                      if(itr == local_variable_table.end())
                        if(in_main)
                        {
                          itr = main_variable_table.find($1);
                          if(itr != main_variable_table.end())
                            flag = 1;
                        }
                        else
                        {
                          itr = function_variable_table.find($1);
                          if(itr != function_variable_table.end())
                            flag = 1;
                        }
                      else
                        flag = 1;
                    }
                    else if(in_main)
                    {
                      itr = main_variable_table.find($1);
                      if(itr != main_variable_table.end())
                        flag = 1;
                    }
                    else if(in_function)
                    {
                      itr = function_variable_table.find($1);
                      if(itr != function_variable_table.end())
                        flag = 1;
                    }
                    if(!flag)
                    {
                      itr = global_variable_table.find($1);
                      if(itr != global_variable_table.end())
                        flag = 1;
                    }
                    if(!flag)
                    {
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",variable "<<$1<<" not defined\n";
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
                    itr = variable_type.find($1);
                    if(itr!=variable_type.end())
                      strcpy(temp->syn,itr->second.c_str());
                    $$ = temp;
                  }
		         		  |  TOKEN_INTCONST
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "EXP");
                    temp->addchild_str("TOKEN_INTCONST", $1);
                    strcpy(temp->syn,"int");
                    temp->varsize = atoi($1);
                    //code generation
                    if(error_flag){
                    (temp->code).append("\tli   $s0, ");
                    (temp->code).append($1);
                    (temp->code).append("\n");
                    (temp->code).append("\taddi $sp, $sp, -4\n");
                    (temp->code).append("\tsw   $s0, ($sp)\n");
                    }//end of code generation
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
LOOP :		        {in_local++;}TOKEN_LOOP TOKEN_ID TOKEN_LEFTPAREN EXP TOKEN_UNTIL EXP TOKEN_RIGHTPAREN TOKEN_LCB STMTS TOKEN_RCB
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "LOOP");
                    temp->addchild_str("TOKEN_LOOP", $2);
                    temp->addchild_str("TOKEN_ID", $3);
                    temp->addchild_str("TOKEN_LEFTPAREN", $4);
                    temp->addchild($5);
                    temp->addchild_str("TOKEN_UNTIL", $6);
                    temp->addchild($7);
                    temp->addchild_str("TOKEN_RIGHTPAREN", $8);
                    temp->addchild_str("TOKEN_LCB", $9);
                    temp->addchild($10);
                    temp->addchild_str("TOKEN_RCB", $11);
                     in_local--; local_variable_table.clear();
                    //******************************************
                    bool flag = 0;
                    if(in_local)
                    {
                      itr = local_variable_table.find($3);
                      if(itr == local_variable_table.end())
                        if(in_main)
                        {
                          itr = main_variable_table.find($3);
                          if(itr != main_variable_table.end())
                            flag = 1;
                        }
                        else
                        {
                          itr = function_variable_table.find($3);
                          if(itr != function_variable_table.end())
                            flag = 1;
                        }
                      else
                        flag = 1;
                    }
                    else if(in_main)
                    {
                      itr = main_variable_table.find($3);
                      if(itr != main_variable_table.end())
                        flag = 1;
                    }
                    else if(in_function)
                    {
                      itr = function_variable_table.find($3);
                      if(itr != function_variable_table.end())
                        flag = 1;
                    }
                    if(!flag)
                    {
                      itr = global_variable_table.find($3);
                      if(itr != global_variable_table.end())
                        flag = 1;
                    }
                    if(!flag)
                    {
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",variable "<<$3<<" not defined\n";
                      error_flag = 0;
                    }
                    //******************************************
                    //code generation
                    if(error_flag){
                    string help1,help2;
                    loop_counter++;
                    help1=to_string(loop_counter);
                    help1="LOOP"+help1;
                    (temp->code).append($5->code);
                    (temp->code).append($7->code);
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
                    (temp->code).append($10->code);
                    (temp->code).append("\tj    ");
                    (temp->code).append(help1);
                    (temp->code).append("\n");
                    (temp->code).append(help2);
                    (temp->code).append(":\n");
                    }//end of code generation
                    $$ = temp;
                  };
/************** CONDITION **************/
CONDITION :	      TOKEN_IFCONDITION TOKEN_LEFTPAREN EXP TOKEN_RIGHTPAREN M TOKEN_LCB STMTS TOKEN_RCB
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "CONDITION");
                    temp->addchild_str("TOKEN_IFCONDITION", $1);
                    temp->addchild_str("TOKEN_LEFTPAREN", $2);
                    temp->addchild($3);
                    temp->addchild_str("TOKEN_RIGHTPAREN", $4);
                    temp->addchild_str("TOKEN_LCB", $6);
                    temp->addchild($7);
                    temp->addchild_str("TOKEN_RCB", $8);
                    //code generation
                    if(error_flag){
                    string help1;
                    exit_num++;
                    help1=to_string(exit_num);
                    help1="Exit"+help1;
                    (temp->code).append($3->code);
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tbeq  $t0, $zero, ");
                    (temp->code).append(help1);
                    (temp->code).append("\n");
                    (temp->code).append($7->code);
                    (temp->code).append(help1);
                    (temp->code).append(":\n");
                    }
                    //end of code generation
                    $$ = temp;
                     in_local--; local_variable_table.clear();
                  }
                  | TOKEN_IFCONDITION TOKEN_LEFTPAREN EXP TOKEN_RIGHTPAREN M TOKEN_LCB STMTS TOKEN_RCB ELSECON
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "CONDITION");
                    temp->addchild_str("TOKEN_IFCONDITION", $1);
                    temp->addchild_str("TOKEN_LEFTPAREN", $2);
                    temp->addchild($3);
                    temp->addchild_str("TOKEN_RIGHTPAREN", $4);
                    temp->addchild_str("TOKEN_LCB", $6);
                    temp->addchild($7);
                    temp->addchild_str("TOKEN_RCB", $8);
                    temp->addchild($9);
                    //code generation
                    if(error_flag){
                    string help1;
                    exit_num++;
                    help1=to_string(exit_num);
                    help1="Exit"+help1;
                    (temp->code).append($3->code);
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tbeq  $t0, $zero, ");
                    (temp->code).append(help1);
                    (temp->code).append("\n");
                    (temp->code).append($7->code);
                    (temp->code).append(help1);
                    (temp->code).append(":\n");
                    (temp->code).append($9->code);
                    }
                    //end of code generation
                    $$ = temp;
                     in_local--; local_variable_table.clear();
                  };
M:                {in_local++;};
/************** ELSECON **************/
ELSECON :		      TOKEN_ELSECONDITION M TOKEN_LCB STMTS TOKEN_RCB
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "ELSECON");
                    temp->addchild_str("TOKEN_ELSECONDITION", $1);
                    temp->addchild_str("TOKEN_LCB", $3);
                    temp->addchild($4);
                    temp->addchild_str("TOKEN_RCB", $5);
                    (temp->code).append($4->code);
                    $$ = temp;
                     in_local--; local_variable_table.clear();
                  };
/************** STMT_RETURN **************/
STMT_RETURN :	    TOKEN_RETURN EXP
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT_RETURN");
                    temp->addchild_str("TOKEN_RETURN", $1);
                    temp->addchild($2);

                    if((strcmp($2->syn,"int") == 0&&!return_type.top())||(strcmp($2->syn,"void") == 0&&return_type.top()))
                    {
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",not matching return types.\n";
                      error_flag = 0;
                    }
                    //code generation
                    if(error_flag){
                    (temp->code).append($2->code);
                    (temp->code).append("\tlw $v0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tjr $ra\n");
                    }//end of code generation
                    $$ = temp;
                  }
                  |TOKEN_RETURN
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT_RETURN");
                    temp->addchild_str("TOKEN_RETURN", $1);
                    //code generation
                    if(error_flag){
                    (temp->code).append("\tjr $ra\n");
                    }//end of code generation
                    $$ = temp;
                  };
/************** STMT_DECLARE **************/
STMT_DECLARE :	  TYPE TOKEN_ID ARRAY_VAR {strcpy(IDS_type, $1->syn);} IDS
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT_DECLARE");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_ID", $2);
                    temp->addchild($3);
                    temp->addchild($5);
                    //*****************************************
                    string new_name = $2;
                    if(in_local)
                    {
                      new_name = "___" + new_name;
                      local_variable_table.insert(pair<string, string>($2, new_name));
                    }
                    else if(in_function && !in_main)
                    {
                      new_name = "__" + new_name;
                      function_variable_table.insert(pair<string, string>($2, new_name));
                    }
                    else if(in_main)
                    {
                      new_name = "_" + new_name;
                      main_variable_table.insert(pair<string, string>($2, new_name));
                    }
                    variable_size.insert(pair<string, int>(new_name, $3->varsize)); variable_type.insert(pair<string, string>($2, $1->syn));
                    //*****************************************
                    //code generation
                    if(error_flag){
                    (temp->code).append($5->code);
                    }//end of code generation
                    $$ = temp;
                  }
                  |TYPE TOKEN_ID ARRAY_VAR {strcpy(IDS_type, $1->syn);} STMT_ASSIGN IDS
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT_DECLARE");
                    temp->addchild($1);
                    temp->addchild_str("TOKEN_ID", $2);
                    temp->addchild($3);
                    temp->addchild($5);
                    temp->addchild($6);
                    //*****************************************
                    string new_name = $2;
                    if(in_local)
                    {
                      new_name = "___" + new_name;
                      local_variable_table.insert(pair<string, string>($2, new_name));
                    }
                    else if(in_function && !in_main)
                    {
                      new_name = "__" + new_name;
                      function_variable_table.insert(pair<string, string>($2, new_name));
                    }
                    else if(in_main)
                    {
                      new_name = "_" + new_name;
                      main_variable_table.insert(pair<string, string>($2, new_name));
                    }
                    variable_size.insert(pair<string, int>(new_name, $3->varsize)); variable_type.insert(pair<string, string>($2, $1->syn));
                    //*****************************************
                    //code generation
                    if(error_flag){
                    (temp->code).append($5->code);
                    (temp->code).append("\tlw   $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tsw   $t0, ");
                    (temp->code).append(new_name);
                    (temp->code).append("\n");
                    (temp->code).append($6->code);
                    }//end of code generation
                    $$ = temp;
                    };
/************** ARRAY_VAR **************/
ARRAY_VAR :		    TOKEN_LB EXP TOKEN_RB
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "ARRAY_VAR");
                    temp->addchild_str("TOKEN_LB", $1);
                    temp->addchild($2);
                    temp->addchild_str("TOKEN_RB", $3);
                    temp->varsize = $2->varsize;
                    //code generation
                    if(error_flag){
                    (temp->code).append($2->code);
                    is_array_var = 1;
                    }//end of code generation
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
                    temp->varsize = 1;
                    $$ = temp;
                  };/*epsilon*/
/************** IDS **************/
IDS :		          TOKEN_COMMA TOKEN_ID ARRAY_VAR STMT_ASSIGN IDS
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "IDS");
                    temp->addchild_str("TOKEN_COMMA", $1);
                    temp->addchild_str("TOKEN_ID", $2);
                    temp->addchild($3);
                    temp->addchild($4);
                    temp->addchild($5);
                    //*****************************************
                    string new_name = $2;
                    if(in_local)
                    {
                      new_name = "___" + new_name;
                      local_variable_table.insert(pair<string, string>($2, new_name));
                    }
                    else if(in_function && !in_main)
                    {
                      new_name = "__" + new_name;
                      function_variable_table.insert(pair<string, string>($2, new_name));
                    }
                    else if(in_main)
                    {
                      new_name = "_" + new_name;
                      main_variable_table.insert(pair<string, string>($2, new_name));
                    }
                    variable_size.insert(pair<string, int>(new_name, $3->varsize));
                    variable_type.insert(pair<string, string>($2, IDS_type));
                    //*****************************************
                    //code generation
                    if(error_flag){
                    (temp->code).append($4->code);
                    (temp->code).append("\tlw $t0, ($sp)\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append("\tsw   $t0, ");
                    (temp->code).append(new_name);
                    (temp->code).append("\n");
                    (temp->code).append($5->code);
                    }//end of code generation
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
                    string new_name = $2;
                    if(in_local)
                    {
                      new_name = "___" + new_name;
                      local_variable_table.insert(pair<string, string>($2, new_name));
                    }
                    else if(in_function && !in_main)
                    {
                      new_name = "__" + new_name;
                      function_variable_table.insert(pair<string, string>($2, new_name));
                    }
                    else if(in_main)
                    {
                      new_name = "_" + new_name;
                      main_variable_table.insert(pair<string, string>($2, new_name));
                    }
                    variable_size.insert(pair<string, int>(new_name, $3->varsize));
                    variable_type.insert(pair<string, string>($2, IDS_type));
                    //*****************************************
                    //code generation
                    if(error_flag){
                    (temp->code).append($4->code);
                    }//end of code generation
                    $$ = temp;
                  }
                  |{ struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "IDS");
                    $$ = temp;
                  };/*epsilon*/
/************** CALL **************/
CALL :		        TOKEN_ID TOKEN_LEFTPAREN ARGS
                  {
                    itr1 = function_table.find($1);
                    if(itr1 == function_table.end())
                    {
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",function "<<$1<<" not defined\n";
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
                  } TOKEN_RIGHTPAREN
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "CALL");
                    temp->addchild_str("TOKEN_ID", $1);
                    temp->addchild_str("TOKEN_LEFTPAREN", $2);
                    temp->addchild($3);
                    temp->addchild_str("TOKEN_RIGHTPAREN", $5);
                    //code generation
                    if(error_flag){
                    (temp->code).append($3->code);
                    (temp->code).append("\tjal ");
                    (temp->code).append($1);
                    (temp->code).append("\n");
                    }//end of code generation
                    $$ = temp;
                  };
/************** ARGS **************/
ARGS :		        EXP ARGS
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "ARGS");
                    temp->addchild($1);
                    temp->addchild($2);
                    //code generation
                    if(error_flag){
                    char reg_num[5];
                    sprintf(reg_num,"%d",a_reg_count++);
                    (temp->code).append($1->code);
                    (temp->code).append("\tlw   $a");
                    (temp->code).append(reg_num);
                    (temp->code).append(", $sp\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append($2->code);
                    }//end of code generation
                    $$ = temp;
                  }
                  | TOKEN_COMMA EXP ARGS
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "ARGS");
                    temp->addchild_str("TOKEN_COMMA", $1);
                    temp->addchild($2);
                    temp->addchild($3);
                    //code generation
                    if(error_flag){
                    char reg_num[5];
                    sprintf(reg_num,"%d",a_reg_count++);
                    (temp->code).append($2->code);
                    (temp->code).append("\tlw $a");
                    (temp->code).append(reg_num);
                    (temp->code).append(", $sp\n");
                    (temp->code).append("\taddi $sp, $sp, 4\n");
                    (temp->code).append($3->code);
                    }//end of code generation
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
                    bool flag = 0;
                    if(in_local)
                    {
                      itr = local_variable_table.find($1);
                      if(itr == local_variable_table.end())
                        if(in_main)
                        {
                          itr = main_variable_table.find($1);
                          if(itr != main_variable_table.end())
                            flag = 1;
                        }
                        else
                        {
                          itr = function_variable_table.find($1);
                          if(itr != function_variable_table.end())
                            flag = 1;
                        }
                      else
                        flag = 1;
                    }
                    else if(in_main)
                    {
                      itr = main_variable_table.find($1);
                      if(itr != main_variable_table.end())
                        flag = 1;
                    }
                    else if(in_function)
                    {
                      itr = function_variable_table.find($1);
                      if(itr != function_variable_table.end())
                        flag = 1;
                    }
                    if(!flag)
                    {
                      itr = global_variable_table.find($1);
                      if(itr != global_variable_table.end())
                        flag = 1;
                    }
                    if(!flag)
                    {
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",variable "<<$1<<" not defined\n";
                      error_flag = 0;
                    }
                    //******************************************
                    //code generation
                    if(error_flag){
                    if(is_array_var)
                    {
                      is_array_var = 0;
                      (temp->code).append($2->code);
                      (temp->code).append("\tlw   $t0, ($sp)\n");
                      (temp->code).append("\taddi $sp, $sp, 4\n");
                      (temp->code).append("\tla   $t1, ");
                      (temp->code).append(itr->second);
                      (temp->code).append("\n");
                      (temp->code).append("\tadd $t0, $t0, $t0\n");
                      (temp->code).append("\tadd $t0, $t0, $t0\n");
                      (temp->code).append("\tadd $t1, $t1, $t0\n");
                      (temp->code).append($4->code);
                      (temp->code).append("\tlw   $s0, ($sp)\n");
                      (temp->code).append("\taddi $sp, $sp, 4\n");
                      (temp->code).append("\tsw   $s0, ($t1)\n");
                    }
                    else
                    {
                      (temp->code).append($4->code);
                      (temp->code).append("\tlw   $s0, ($sp)\n");
                      (temp->code).append("\taddi $sp, $sp, 4\n");
                      (temp->code).append("\tsw   $s0, ");
                      (temp->code).append(itr->second);
                      (temp->code).append("\n");
                    }
                    }//end of code generation
                    $$ = temp;
                  }
                  | TOKEN_ASSIGNOP EXP
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT_ASSIGN");
                    temp->addchild_str("TOKEN_ASSIGNOP", $1);
                    temp->addchild($2);
                    //code generation
                    if(error_flag){
                    (temp->code).append($2->code);
                    }//end of code generation
                    $$ = temp;
                  }
                  |TOKEN_ASSIGNOP CALL
                  {
                    struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT_ASSIGN");
                    temp->addchild_str("TOKEN_ASSIGNOP", $1);
                    temp->addchild($2);
                    //code generation
                    if(error_flag){
                    (temp->code).append($2->code);
                    (temp->code).append("\taddi $sp, $sp, -4\n");
                    (temp->code).append("\tsw   $v0, ($sp)\n");
                    }//end of code generation
                    $$ = temp;
                  }
                  |TOKEN_ID ARRAY_VAR TOKEN_ASSIGNOP CALL
                  { struct tnode *temp = new struct tnode();
                    strcpy(temp->token_name, "STMT_ASSIGN");
                    temp->addchild_str("TOKEN_ID", $1);
                    temp->addchild($2);
                    temp->addchild_str("TOKEN_ASSIGNOP", $3);
                    temp->addchild($4);
                    //*********************************************
                    bool flag = 0;
                    if(in_local)
                    {
                      itr = local_variable_table.find($1);
                      if(itr == local_variable_table.end())
                        if(in_main)
                        {
                          itr = main_variable_table.find($1);
                          if(itr != main_variable_table.end())
                            flag = 1;
                        }
                        else
                        {
                          itr = function_variable_table.find($1);
                          if(itr != function_variable_table.end())
                            flag = 1;
                        }
                      else
                        flag = 1;
                    }
                    else if(in_main)
                    {
                      itr = main_variable_table.find($1);
                      if(itr != main_variable_table.end())
                        flag = 1;
                    }
                    else if(in_function)
                    {
                      itr = function_variable_table.find($1);
                      if(itr != function_variable_table.end())
                        flag = 1;
                    }
                    if(!flag)
                    {
                      itr = global_variable_table.find($1);
                      if(itr != global_variable_table.end())
                        flag = 1;
                    }
                    if(!flag)
                    {
                      cout<<"line:"<<line_num+1<<",column:"<<column_num<<",variable "<<$1<<" not defined\n";
                      error_flag = 0;
                    }
                    //*****************************************
                    //code generation
                    if(error_flag){
                    if(is_array_var)
                    {
                      is_array_var = 0;
                      (temp->code).append($2->code);
                      (temp->code).append("\tlw   $t0, ($sp)\n");
                      (temp->code).append("\taddi $sp, $sp, 4\n");
                      (temp->code).append("\tla $t1, ");
                      (temp->code).append(itr->second);
                      (temp->code).append("\n");
                      (temp->code).append("\tadd $t0, $t0, $t0\n");
                      (temp->code).append("\tadd $t0, $t0, $t0\n");
                      (temp->code).append("\tadd $t1, $t1, $t0\n");
                      (temp->code).append($4->code);
                      (temp->code).append("\tsw  $v0, ($t1)\n");
                    }
                    else
                    {
                      (temp->code).append($4->code);
                      (temp->code).append("\tsw   $v0, ");
                      (temp->code).append(itr->second);
                      (temp->code).append("\n");
                    }
                    }//end of code generation
                    $$ = temp;
                  };
%%


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
