/* C program to implement DEQUE using doubly linked list to perform
   the insertion, deletion and display operations. */

#include <stdio.h>
#include <stdlib.h>

struct DEQ
{
    int data;
    struct DEQ *prev, *next;
};

typedef struct DEQ *node;

node insert_front();
node insert_rear();
node delete_front();
node delete_rear();
void display(node);


int main()
{
    node s=NULL;
    int ch;
    while(1)
    {
        printf("\nEnter your choice");
        printf("\n1.Insert at front\n2.Insert at rear\n3.Delete from front\n4.Delete from rear\n5.Display\n6.Exit\n");
        scanf("%d",&ch);
          switch(ch)
        {
                case 1:s=insert_front(s);
                        break;

                case 2:s=insert_rear(s);
                        break;

                case 3:s=delete_front(s);
                        break;

                case 4:s=delete_rear(s);
                        break;

                case 5:display(s);
                        break;

                case 6: exit(0);

                default: printf("\nInvalid choice");
        }
    }
}


node insert_front(node s1)
{
    node temp;
    int data;

    if((temp=(node)malloc(sizeof(struct DEQ)))==NULL)

    {
        printf("\nMemory not allocated");
        return;
    }

    printf("\nEnter data to be inserted:\t");
    scanf("%d",&data);
     temp->data=data;
    temp->prev=temp->next=NULL;


    if(s1==NULL)
    {
        return(temp);
    }

    temp->next=s1;
    s1->prev=temp;
    s1=temp;
    return(s1);
}


node insert_rear(node s1)
{
    node temp,cur=NULL;
    int data;

    if((temp=(node)malloc(sizeof(struct DEQ)))==NULL)
    {
        printf("\nMemory not allocated");
        return;
    }

    printf("\nEnter data to be inserted:\t");
    scanf("%d",&data);
    temp->data=data;
    temp->prev=temp->next=NULL;

    if(s1==NULL)
    {
        return(temp);
    }
    cur=s1;
    while(cur->next!=NULL)
    {
       cur=cur->next;
    }
    cur->next=temp;
    temp->prev=cur;
    return(s1);
}



node delete_front(node s1)
{
    node temp=NULL;
    if(s1==NULL)
    {
        printf("\nList does not exist!");
        return;
    }
    if(s1->next==NULL)
    {
        free(s1);
        return(NULL);
    }
    temp=s1;
    s1=s1->next;
    s1->prev=NULL;
    printf("\nDeleted data is %d",temp->data);
    free(temp);
    return(s1);
}

node delete_rear(node s1)
{
    node cur;
    if(s1==NULL)
    {
        printf("\nList does not exist!");
        return;
    }
    if(s1->next==NULL)
    {
        free(s1);
        return(NULL);
    }
    cur=s1;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->prev->next=NULL;
    printf("\nDeleted data is %d",cur->data);
    free(cur);
    return(s1);
}

void display(node s1)
{
    node cur=NULL;

    if(s1==NULL)
    {
        printf("\nList does not exist!");
        return;
    }

    cur=s1;
    printf("\nElements of list are:\t");
    while(cur!=NULL)
    {
        printf("%d\t",cur->data);
        cur=cur->next;
    }
}
