#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *createsllbeg() {
    struct node *start = NULL, *p;
    int item;
    printf("enter element(-999 to stop): ");
    scanf("%d",&item);
    while(item!=-999){
        p = (struct node *)malloc(sizeof(struct node));
        if(start == NULL){
            p->info = item;
            p->next = NULL;
            start = p;
        }
        else{
            p->info = item;
            p->next = start;
            start = p;
        }
        printf("enter element(-999 to stop): ");
        scanf("%d",&item);
    }
    return start;
}

void display(struct node *start){
    struct node *temp;
    temp = start;
    while(temp!=NULL){
        printf("%d -> ",temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct node *start;
    start = createsllbeg();
    display(start);
    return 0;
    
}