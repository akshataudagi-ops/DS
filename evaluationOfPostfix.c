#include<stdio.h>
#include<ctype.h>
#define max 100

int stack[max];
int top = -1;

void push(int item) {
    if(top == max-1) {
        printf("Overflow\n");
    }
    else {
        top++;
        stack[top] = item;
    }
}
int pop() {
    int item;
    if(top == -1) {
        printf("Underflow\n");
        return 0;
    }
    else {
        item = stack[top];
        top--;
        return item;
    }
}
int main() {
    int i = 0;
    char postfix[100];
    printf("Enter postfix exp: ");
    scanf("%s", postfix);
    

    while(postfix[i] != '\0') {
        char s = postfix[i]; 
        if(isdigit(s)) {
            push(s - '0');
        }
        else{
            int a = pop();
            int b = pop();
            switch(s){
                case '/':
                push(b/a);
                break;

                case '*':
                push(b*a);
                break;

                case '+':
                push(b+a);
                break;

                case '-':
                push(b-a);
                break;

                default:
                 printf("invalid char");
                 break;
            }
        }
        i++;
    }
    printf("%d", stack[top]);
}