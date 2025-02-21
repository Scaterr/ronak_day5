#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Stack_t {
    char url[100];
};

typedef struct Stack_t Stack;

Stack history[MAX];
int top = -1;

void visitPage(const char* url);
void goBack();
void goForward();
void displayCurrentPage();

int main() {
    int choice;
    char url[100];
    do {
        printf("\nBrowser History Navigation\n");
        printf("1. Visit page\n2. Go Back\n3. Go Forward\n4. Display current page\n");
        printf("Enter your operation: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter URL: ");
                scanf(" %s", url);
                visitPage(url);
                break;
            }
            case 2: {
                goBack();
                break;
            }
            case 3: {
                goForward();
                break;
            }
            case 4: {
                displayCurrentPage();
                break;
            }
            default: {
                printf("Exiting Browser History Navigation...\n");
                break;
            }
        }
    }while ((choice >= 1) &&(choice <=4));
    return 0;
}

void visitPage(const char* url) {
    if (top < MAX - 1) {
        top++;
        strcpy(history[top].url, url);
        printf("Visited: %s\n", history[top].url);
    } else {
        printf("History stack is full!\n");
    }
}

void goBack() {
    if (top > 0) {
        top--;
        printf("Action: Go Back\n");
        printf("Current Page: %s\n", history[top].url);
    } else {
        printf("No previous page in history.\n");
    }
}

void goForward() {
    if (top < MAX - 1 && history[top + 1].url[0] != '\0') {
        top++;
        printf("Action: Go Forward\n");
        printf("Current Page: %s\n", history[top].url);
    } else {
        printf("No forward page in history.\n");
    }
}

void displayCurrentPage() {
    if (top >= 0) {
        printf("Current Page: %s\n", history[top].url);
    } else {
        printf("No page visited yet.\n");
    }
}
