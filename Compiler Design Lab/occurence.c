#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[100];
    int c;
    int count[256] = {0};

    
    printf("Enter the filename: ");
    scanf("%99s", filename);

   
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

   
    while ((c = fgetc(fp)) != EOF) {
        count[c]++;
    }

    fclose(fp);

    printf("Character Occurrence in %s:\n", filename);
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            printf("'%c' : %d\n", i, count[i]);
        }
    }

    return 0;
}
