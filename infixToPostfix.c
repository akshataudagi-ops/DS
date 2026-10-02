#include<stdio.h>
#include<ctype.h>
#define max 100

char stack[max];
int top = -1;

void push(char item) {
    if(top == max-1) {
        printf("Overflow\n");
    }
    else {
        top++;
        stack[top] = item;
    }
}

char pop() {
    char item;
    if(top == -1) {
        printf("Underflow\n");
        return '\0';
    }
    else {
        item = stack[top];
        top--;
        return item;
    }
}

int precedence(char c) {
    if(c == '^') {
        return 3;
    }
    else if(c == '/' || c == '*') {
        return 2;
    }
    else if(c == '+' || c == '-') {
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
    int i = 0, j = 0;
    char infix[100];
    char postfix[100];
    printf("enter infix exp: ");
    scanf("%s", infix);

    while(infix[i] != '\0') {
        char s = infix[i];
        if(s == '(') {
            push(s);
        }
        else if (isalnum(s)) {
            postfix[j] = s;
            j++;
        }
        else if (s == ')') {
            while(stack[top] != '(') {
                postfix[j] = pop();
                j++;
            }
          
            pop();
        }
        else {
            while(top != -1 && stack[top] != '(' && precedence(stack[top]) >= precedence(s)) {
                postfix[j] = pop();
                j++;
            }
            push(s);
        }
        i++;
        
    }
    while (top != -1)
    {   
        postfix[j] = pop();
        j++;
    }
    
    postfix[j] = '\0';

    printf("%s",postfix);
    return 0;
}