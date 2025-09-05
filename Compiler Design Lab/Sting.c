/*WAP in c to identify the given string is keyword or not.*/

#include <stdio.h>
#include <string.h>

int isKeyword(char str[]) {
    
    char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue",
        "default", "do", "double", "else", "enum", "extern",
        "float", "for", "goto", "if", "int", "long", "register",
        "return", "short", "signed", "sizeof", "static", "struct",
        "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };
    int n = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < n; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0; 
}

int main() {
    char str[50];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isKeyword(str))
        printf("%s is a keyword.\n", str);
    else
        printf("%s is not a keyword.\n", str);

    return 0;
}