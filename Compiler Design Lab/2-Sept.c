/*Write a Program to count total number of keywords in a given file [ taking file from the user ]*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof",
    "static", "struct", "switch", "typedef", "union", "unsigned", "void",
    "volatile", "while"
};
int num_keywords = 32;

int isKeyword(const char *word) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
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

    char word[100];
    int count = 0;
    while (fscanf(fp, "%99s", word) == 1) {
        if (isKeyword(word))
            count++;
    }

    printf("Number of C keywords = %d\n", count);
    fclose(fp);
    return 0;
}
