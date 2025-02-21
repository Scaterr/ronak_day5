#include<stdio.h>
#include<stdlib.h>
#define MAX 100 

struct Stock_t{
    char item[100];
};

int top = -1;
typedef struct Stock_t Stock;
void addStock(int n, Stock stocks[]);
void dispatchStock(int n, Stock stocks[]);
void displayStock(int n, Stock stocks[]);

int main(){
    int choice, n;
    Stock stocks[MAX];
    do{
        printf("\nWarehouse Stock Management\n");
        printf("1. Add stock\n2. Dispatch stocks\n3. Display Stocks\n");
        printf("\nEnter your operation: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                printf("Enter the number of Stocks: ");
                scanf("%d", &n);
                addStock(n, stocks);
            } break;
            case 2:{
                dispatchStock(n, stocks);
            } break;
            case 3:{
                displayStock(n, stocks);
            } break;
            default:{
                printf("Exiting Operation...\n");
            }
        }
    } while((choice >= 1) && (choice <= 3));
    return 0;
}

void addStock(int n, Stock stocks[]){
    if(top < MAX - 1){
        for(int i = 0; i < n; i++){
            top++;
            printf("Stock Added: Item ");
            scanf("%s", stocks[top].item);
        }
    }
}

void dispatchStock(int n, Stock stocks[]){
    if(top >= 0){
        printf("Dispatching item: Item %s\n", stocks[top].item);
        top--;
    }else{
        printf("Warehouse is Empty\n");
    }
}

void displayStock(int n, Stock stocks[]){
    if(top >= 0){
        printf("Remaining Stock:\n");
        for(int i = top; i >= 0; i--){
            printf("Item: %s", stocks[i].item);
            if(i > 0) printf("\n");
        }
        printf("\n");
    }
}
