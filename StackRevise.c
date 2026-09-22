#include <stdio.h>
int maxsize,top=-1,a[100];

void push(int item) {
    if(top == maxsize-1) {
        printf("Stack is full\n");
    } else{
        top++;
        a[top] = item;
    }
}
void pop() {
    int item;
    if(top == -1) {
        printf("Stack is empty\n");
    } else {
        item = a[top];
        top--;
    }
}

void display() {
    int i;
    if(top == -1){
        printf("Stack is empty");

    }else {
        for(int i = top; i>=0; i--){
            printf("%d\n",a[i]);
        }
    }
}
int main(){
    maxsize = 5;

    push(10);
    push(20);
    push(30);
    display();
    push(40);
    push(50);
    display();
    pop();
    display();
    pop();
    display();
}