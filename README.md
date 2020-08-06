# LG mini C compiler
## Description:  
Project of IUT compiler course in 3 phase for C.  
The project of the IUT compiler course in 3 phases for C.  
It's a simplified C compiler that checks syntax, semantic and finally generates assembly codes.  
This project has been done in two-person([@elnazrahmati](https://github.com/elnazrahmati) and me) teams.   
## Requirements:
- Linux (I used Ubuntu)
- flex
- bison
- C and CPP compiler(I used gcc and g++)
## Phase 1:
Check the syntax of the C codes with **flex**.  
```bash
flex -o myapp.c phase1.lex
gcc myapp.c
./a.out 
```
## Phase 2:
In this phase, we change the flex file of phase1 to return tokens instead of printing them.  
They gave us a grammar with lots of conflicts so we have to handle these conflicts and make a grammar without conflict.    
The goal of this phase is to print the **parse tree** of the input and check semantic whether there is an error or not.  
```bash
bison -d bison_code.y -o app.cpp
flex -o app_lex.cpp flex_code.l
g++ app.cpp app_lex.cpp 
```
for printing the parse tree by token value run:
```
./a.out test.txt 0
```
for printing the parse tree by token name run: 
```
./a.out test.txt 1
```
## Phase 3:
