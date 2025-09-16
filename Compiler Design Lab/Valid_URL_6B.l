%{
#include<stdio.h>
%} 

%%

https?:\/\/[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}(\/[a-zA-Z0-9._~:/?#@!$&'()*+,;=-]*)? {printf("Accepted");}
.* {printf("Wrong");}

%%

int main(){
printf("Enter the URL: \n");
yylex();
}
int yywrap(){
return 1;
}
