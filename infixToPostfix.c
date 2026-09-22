#include <stdio.h>
#include <string.h>
#include <ctype.h>

int top = -1, maxsize = 100;
char a[100];

void push(char item) {
    if(top == maxsize - 1) {
        printf("full\n");
    } else {
        top++;
        a[top] = item;
    }
}
int precedence(char c)
{
    if (c == '^')
        return 3;

    else if (c == '*' || c == '/')
        return 2;

    else if (c == '+' || c == '-')
        return 1;

    return 0;
}

int pop() {
    char item;

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
    int i,j=0;
   
    char exp[100];
    char pe[100];
    printf("enter exp \n");
    scanf("%s", exp);

    for (int i = 0; i<strlen(exp); i++) {
        if(exp[i] == '(') {
            push(exp[i]);
        }
        else if (isdigit(exp[i])) {
            pe[j] = exp[i];
            j++;
        }
        else if (exp[i] == ')') {
            int popped;
            while(top != -1 && a[top] != '(') {
            pe[j] = pop();
            j++;
        }
        pop();
    }


        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^' ){
            
            while(top != -1 &&
            precedence(a[top]) >= precedence(exp[i])) {
            pe[j] = pop();
            j++;
            
            }
            push(exp[i]);

        }
     }
     while(top != -1) {
     pe[j] = pop();
     j++;
     }
     pe[j] = '\0';
     printf("%s", pe);
     return 0;

    
}