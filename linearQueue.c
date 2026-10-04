#include <stdio.h>
#include <ctype.h>

int max = 5, front = -1, rear = -1;
int a[100];

void insertlq() {
    int item;
    

    if(rear == max - 1){
        printf("queue is full\n");
    }
    else{
        printf("enter item: ");
        scanf("%d", &item);
        if(front == -1 && rear == -1) {
            front = 0, rear = 0;
            a[rear] = item;
        }
        else{
            rear++;
            a[rear] = item;
        }
    }
}

void deletelq() {
    int item;
    if(front == -1) {
        printf("queue is empty\n");
    }
    else{
        if(front == rear){
            item = a[front];
            front = -1, rear = -1;
        }
        else{
            item = a[front];
            front++;
        }
        printf("Deleted item is %d, item");
    }
}

void display() {
    
    if(front == -1){
        printf("queue is empty\n");
    }
    else{
        for(int i = front; i <= rear; i++){
            printf("%d\n",a[i]);
        }
    }
}

int main() {
    int choice;
    do{
        printf("1.Insert 2.Delete 3.Display 4.exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            insertlq();
            break;
            case 2:
            deletelq();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("exiting\n");
            break;
            default:
            printf("invalid\n");
        }

    }while(choice != 4);
    return 0;
    
}