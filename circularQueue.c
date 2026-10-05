#include <stdio.h>
#define max 5

int a[max];

int front = -1, rear = -1;

void insertcq() {
    if(front == (rear+1)%max) {
        printf("queue is full\n");
    }
    else{
        int item;
        printf("enter item: ");
        scanf("%d", &item);
        if(front == -1) {
            front = 0, rear = 0;
            a[rear] = item;
        }
        else{
            rear = (rear+1)%max;
            a[rear] = item;
        }
        printf("inserted %d\n", item);
    }
}
void deletecq(){
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
            front = (front + 1)% max;
        }
        printf("deleted %d\n", item);
    }
}

void display(){
    if(front == -1){
        printf("queue is empty\n");
    }
    else{
        if(front < rear){
            for(int i = front; i <= rear; i++){
                printf("%d\n", a[i]);
            }
        }
        else{
            for(int i = front; i <= max-1; i++) {
                printf("%d\n", a[i]);
            }
            for(int i = 0; i <= rear; i++) {
                printf("%d\n", a[i]);

            }
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
            insertcq();
            break;
            case 2:
            deletecq();
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