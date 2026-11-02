
#include <stdio.h>
#define MAX 5

int pq[MAX];
int front = -1, rear = -1;

void insert(int x)
{
    int i;

    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
        pq[rear] = x;
        return;
    }

    i = rear;

    while (i >= front && pq[i] < x)
    {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = x;
    rear++;
}

void delete()
{
    int i;

    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", pq[front]);

    for (i = front; i < rear; i++)
        pq[i] = pq[i + 1];

    rear--;

    if (rear == -1)
        front = -1;
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    for (i = front; i <= rear; i++)
        printf("%d ", pq[i]);

    printf("\n");
}

int main()
{
    int choice, x;

    while (1)
    {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insert(x);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
