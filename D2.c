#include <stdio.h>
#include <math.h>
#include <string.h>

int a[100], top = -1, maxsize = 100;

void push(int item) {
    if(top == maxsize - 1) {
        printf("full\n");
    } else {
        top++;
        a[top] = item;
    }
}

int pop() {
    int item;

    if(top == -1) {
        printf("empty\n");
        return -1;
    } else {
        item = a[top];
        top = top - 1;
        return item;
    }
}


int main() {
    char exp[100];

    printf("Enter expression: ");
    scanf("%s", exp);

    for(int i = 0; i < strlen(exp); i++) {

        if(exp[i] >= '0' && exp[i] <= '9') {
            push(exp[i] - '0');
        } 
        else {
            int x = pop();
            int y = pop();

            switch(exp[i]) {

                case '+':
                    push(y + x);
                    break;

                case '-':
                    push(y - x);
                    break;

                case '*':
                    push(y * x);
                    break;

                case '/':
                    push(y / x);
                    break;

                case '%':
                    push(y % x);
                    break;

                case '^':
                    push(pow(y, x));
                    break;

                default:
                    printf("Invalid operator\n");
            }
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}