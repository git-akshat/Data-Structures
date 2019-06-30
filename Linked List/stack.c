/*C program to implement a STACK using singly linked list. */

#include<stdio.h>
#include<stdlib.h>

struct list
{
	int data;
	struct list *link;
};

typedef struct list *node;

node push(node);
node pop(node);
void display(node);


void main()
{
	node s=NULL;
	int choice;
	while(1)
	{
		printf("\nEnter your choice");
		printf("\n1.Push\n2.pop\n3.Display\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:s=push(s);
				   break;
			case 2:s=pop(s);
				   break;
			case 3:display(s);
				   break;
			case 4:exit(0);
		}
	}
}


//inserting at rear end
node push(node s1)
{
	int data;
	node temp,cur=NULL;

	if((temp=(node)malloc(sizeof(struct list)))==NULL)
	{
		printf("\nMemory not allocated!");
		return;
	}
	printf("\nEnter data: ");
	scanf("%d",&data);
	temp->data=data;
	temp->link=NULL;

	if(s1==NULL)
	{
		return(temp);
	}
	cur=s1;
	while(cur->link!=NULL)
	{
		cur=cur->link;
	}
	cur->link=temp;

	return(s1);
}

//deleting from rear end
node pop(node s1)
{
	node cur=NULL,prev=NULL;

	if(s1==NULL)
	{
		printf("Error! List is empty");
		return s1;
	}

	if(s1->link==NULL)
    {
        printf("\nDeleted data is %d",s1->data);
        free(s1);
        return(NULL);
    }

	cur=s1;
    while(cur->link!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
	prev->link=NULL;
	printf("\nDeleted data is %d",cur->data);
	free(cur);

	return(s1);
}



void display(node s1)
{
	node cur=NULL;

	if(s1==NULL)
	{
		printf("\nList is empty");
		return;
	}

	cur=s1;
	printf("\nElements of list are:\t");
	while(cur!=NULL)
	{
		printf("%d\t",cur->data);
		cur=cur->link;
	}
}
