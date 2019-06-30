/* C program to perform the following operations using singly linked list:
a. to insert a node at the end of the list.
b. to insert a node at the end of the list.
c. to insert a node at the specified position in the list.
d. to display the contents of the list.
e. to reverse a given list. */

#include<stdio.h>
#include<stdlib.h>

struct list
{
	int data;
	struct list *link;
};

typedef struct list *node;

node insert_at_end(node); //insert rear
node delete_front(node);
node insert_at_pos(node); //before the position
void display(node);
node reverse(node);

void main()
{
	node s = NULL;
	int choice;
	while(1)
	{
		printf("\nEnter your choice");
		printf("\n1.Insert at end\n2.Delete from front\n3.Insert at position\n4.Display\n5.Reverse\n6.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:s=insert_at_end(s);
				   break;
			case 2:s=delete_front(s);
				   break;
			case 3:s=insert_at_pos(s);
				   break;
			case 4:display(s);
				   break;
			case 5:s=reverse(s);
				   break;
			case 6:exit(0);
		}
	}
}



node insert_at_end(node s1)
{
	int data;
	node temp, cur=NULL;

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


node delete_front(node s1)
{
	node cur=NULL;

	if(s1==NULL)
	{
		printf("Error! List is empty");
		return;
	}

	cur=s1;
	s1=s1->link;
	printf("\nDeleted data is %d",cur->data);
	free(cur);

	return(s1);
}


node insert_at_pos(node s1)
{
	int data,pos,count=1;
	node temp,cur=NULL,prev=NULL;
	if((temp=(node)malloc(sizeof(struct list)))==NULL)
	{
		printf("\nMemory not allocated!");
		return;
	}
	printf("\nEnter data and position: ");
	scanf("%d%d",&data,&pos);
	temp->data=data;
	temp->link=NULL;

	if(s1==NULL && pos==1)
	{
		s1=temp;
		return(s1);
	}

	if (pos==1)
	{
		temp->link=s1;
		s1=temp;
		return(s1);
	}

	cur=s1;
	while(cur!=NULL && count!=pos)
	{
	prev=cur;
	cur=cur->link;
	count++;
	}

	if(count==pos)
	{
		prev->link=temp;
		temp->link=cur;
	}
	else
	{
		printf("\nInvalid position!");
	}
	return(s1);
}


node reverse(node s1)
{
	node cur=NULL,prev=NULL;
	while(s1!=NULL)
	{
	cur=s1;
	s1=s1->link;
	cur->link=prev;
	prev=cur;
	}
	printf("list reversed\n");
	return(prev);
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