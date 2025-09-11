// Write a Lex Program to check a valid mobile Number 
%{
#include<stdio.h>
%}
%%
[1-9][0-9]{9} {printf("Valid Mobile Number");}
.+            {printf("Invalid Mobile Number");}
%%
int main(){
printf("Enter the Mobile Number: ");
yylex();
printf("\n");
return 0;
}

/* How to Run

1. flex filename.l
2. gcc lex.yy.c -lfl
3. ./a.out
*/
