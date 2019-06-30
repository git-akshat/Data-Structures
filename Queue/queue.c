/* C program to implement ordinary QUEUE to perform the insertion, deletion
and display operations.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
void insert_element();
void delete_element();
void display_element();

struct queue
{
  int element[MAX];
  int front, rear;
}q;

int main()
{
  q.front = q.rear = -1;
  int choice;
  while(1)
  {
    printf("\nEnter your choice\n1.Insert\t2.Delete\t3.Display\t4.exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: insert_element();
              break;

      case 2: delete_element();
              break;

      case 3: display_element();
              break;

      case 4: exit(0);

      default: printf("\nInvalid input!");
    }
  }
}

void insert_element()
{
  int data;

  if(q.rear == MAX -1)
  {
    printf("\nQueue is full");
    return;
  }

  printf("\nEnter data to insert into queue: ");
  scanf("%d", &data);

  if(q.rear++ == 0)
  {
    q.front = 0;
  }

  q.element[q.rear] == data;

}

void delete_element()
{
  int data;

  if(q.front == -1)
  {
    printf("\nCan't delete! Queue is empty.");
    return;
  }

  data = q.element[q.front];
  printf("\nDeleted element is: %d", data);

  if(q.front == q.rear)
  {
    q.front = q.rear = -1;
  }
  else
  {
    q.front++;
  }

}

void display_element()
{
  int i;

  if(q.front == -1)
  {
    printf("\nQueue is empty.");
    return;
  }

  print("\nElements: ");
  for(i = q.front; i <= q.rear; i++)
  {
    printf("%d ", q.element[i]);
  }
}