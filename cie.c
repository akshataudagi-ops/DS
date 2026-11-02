#include <stdio.h>
// void fun(int n)
// {
// if(n > 0)
// {
// printf ("%d", n);
// fun(n-1); 

// }
// }
// int main()
// {
// fun(3);
// return 0;
// }


// void print(int n)
// {
// if (n < 0)
// return;
// else
// {
// printf("%d ", n);
// print(n - 1); // The last executed statement is recursive call
// }

// }
// int main()
// {
// print(3);
// return 0;
// }

void odd(int n);   // Function prototype
void even(int n);
void odd(int n)
{
    if (n<=10)
    {
        printf("%d",n+1); 
        n++;
        even(n);
    }
    return;
}

void even(int n)
{
    if (n<=10)
    {
        printf("%d",n-1); 
        n++;
        odd(n);
    }
    return;
}
int main(){
    int n =1;
    odd(n);
    return 0;
}