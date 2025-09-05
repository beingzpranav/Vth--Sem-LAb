#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Symbol {
    char name[100];
    int address;
    struct Symbol *next;
};

struct Symbol *head = NULL;


void insert(char name[], int address) {
    struct Symbol *temp, *ptr;
   
    ptr = head;
    while (ptr != NULL) {
        if (strcmp(ptr->name, name) == 0) {
            printf("Duplicate symbol not inserted.\n");
            return;
        }
        ptr = ptr->next;
    }
    temp = (struct Symbol *)malloc(sizeof(struct Symbol));
    strcpy(temp->name, name);
    temp->address = address;
    temp->next = head;
    head = temp;
    printf("Symbol inserted.\n");
}


void delete(char name[]) {
    struct Symbol *ptr = head, *prev = NULL;
    while (ptr != NULL && strcmp(ptr->name, name) != 0) {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Symbol not found.\n");
        return;
    }
    if (prev == NULL)
        head = ptr->next;
    else
        prev->next = ptr->next;
    free(ptr);
    printf("Symbol deleted.\n");
}


void display() {
    struct Symbol *ptr = head;
    if (ptr == NULL) {
        printf("Symbol table is empty.\n");
        return;
    }
    printf("Name\t\tAddress\n");
    while (ptr != NULL) {
        printf("%s\t\t%d\n", ptr->name, ptr->address);
        ptr = ptr->next;
    }
}

int main() {
    int choice, addr;
    char name[100];
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter symbol name: ");
                    scanf("%99s", name);
                printf("Enter address: ");
                scanf("%d", &addr);
                insert(name, addr);
                break;
            case 2:
                printf("Enter symbol name to delete: ");
                    scanf("%99s", name);
                delete(name);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
