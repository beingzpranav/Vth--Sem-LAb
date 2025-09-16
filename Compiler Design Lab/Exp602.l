%{
#include<stdio.h>
%} 

%%

[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,} {printf("Accepted");}
.* {printf("Wrong");}

%%

int main(){
printf("Enter the Email Address: \n");
yylex();
}
int yywrap(){
return 1;
}
