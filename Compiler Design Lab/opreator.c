// WAP in C to count total no of operators in a given file. [Taking file from user]


#include <stdio.h>
#include <string.h>

int isOperator(char c) {
    
    return (c == '+' || c == '-' || c == '*' || c == '/' ||
            c == '%' || c == '=' || c == '<' || c == '>' ||
            c == '&' || c == '|' || c == '^' || c == '~' ||
            c == '!');
}

int main() {
    char filename[100];
    printf("Enter file name: ");
    scanf("%99s", filename);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Cannot open file!\n");
        return 1;
    }

    int count = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        if (isOperator(c))
            count++;
    }

    fclose(fp);
    printf("Number of operators = %d\n", count);
    return 0;
}
