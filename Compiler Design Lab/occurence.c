// Write a Program to count totat number of occurences of a given file [Taking file from User]
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[100];
    int c;
    int count[256] = {0};
    char search_char;

    
    printf("Enter the filename: ");
    scanf("%99s", filename);
    printf("Enter the character to search for: ");
    scanf(" %c", &search_char); // Space before %c to skip any leftover whitespace

   
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

   
    while ((c = fgetc(fp)) != EOF) {
        count[c]++;
    }

    fclose(fp);

    printf("The character '%c' occurred %d times in %s.\n", search_char, count[(unsigned char)search_char], filename);

    return 0;
}
