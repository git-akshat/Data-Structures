/* .Write a C program to implement CIRCULAR QUEUE to perform
 the insertion, deletion and display operations. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void insert_data();
void delete_data();
void display_elements();

struct CircularQ
{
    int element[MAX];
    int front,rear;
}cq;

int main()
{
    cq.front = cq.rear = -1;
    int choice;
    while(1)
    {
        printf("\nEnter your choice:\n1.Insert\t2.Delete\t3.Display\t4.Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
           case 1: insert_data();
                   break;

           case 2: delete_data();
                   break;

           case 3: display_elements();
                   break;

           case 4: exit(0);

           default: printf("\nInvalid choice!");
        }
    }
}

void insert_data()
{
    int data;
    if( (cq.rear+1) % MAX == cq.front)
    {
        printf("\nQueue full");
        return;
    }

    printf("\nEnter data to insert:\t");
    scanf("%d", &data);

    cq.rear = (cq.rear+1) % MAX;
    if(cq.rear == 0 && cq.front == -1)
    {
        cq.front = 0;
    }

    cq.element[cq.rear] = data;
    printf("\n");
}

void delete_data()
{
    if(cq.front == -1)
    {
        printf("\nQueue is empty");
        return;
    }

    printf("\nDeleted element is %d", cq.element[cq.front]);

    if(cq.front == cq.rear)
    {
        cq.front = cq.rear = -1;
    }
    else
    {
        cq.front = (cq.front+1) % MAX;
    }

    printf("\n");
}

void display_elements()
{
    int i;

    if(cq.front == -1)
    {
        printf("\nNothing to display! Queue Empty!\n");
        return;
    }

    printf("\nElements are:\n");

    if(cq.rear > cq.front)
    {
        for(i=cq.front; i <= cq.rear; i++)
        {
            printf("%d\t", cq.element[i]);
        }
    }

    else
    {
        for(i=cq.front; i <= MAX-1; i++)
        {
            printf("%d\t", cq.element[i]);
        }
        for(i=0; i<=cq.rear; i++)
        {
            printf("%d\t", cq.element[i]);
        }
    }

    printf("\n");
}