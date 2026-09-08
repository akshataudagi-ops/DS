#include <stdio.h>

int a[100], top=-1, maxsize;
void push(int item) {
    if(top == maxsize-1) {
        printf("full\n");
        } else{
        top++;
        a[top]= item;
        }            
    }
void pop() {
    
    int item;
   
     if(top==-1) {
            printf("empty\n");
        }else{
            item = a[top];
            top= top-1;
            printf("the popped ele is %d\n", item);
        }
}
void display() {
    int i;
    if(top==-1){
        printf("empty\n");

    }else{
        printf("elemests : \n");
        for(i=top; i>=0;i--){
            printf("%d\n", a[i]);
        }
    }
}
int main() {
    int choice;
     printf("enter array size : ");
     scanf("%d", &maxsize);

    

    do {
        printf("Menu : \n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.exit\n");

        printf("enter choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                int item;

                printf("item : ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("exit\n");
                break;
            default:
                printf("invalid\n");
        }
    }while(choice!=4);
    
    return 0;
}