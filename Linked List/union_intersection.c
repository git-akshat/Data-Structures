/* C program to construct two ordered singly linked lists with the following operations:
a insert into list1.
b insert into list2.
c to perform UNION(list1,list2)
d to perform INTERSECTION(list1,list2)
e display the contents of all three lists. */

#include <stdio.h>
#include <stdlib.h>
struct list
    {
        int data;
        struct list *link;
    };
    typedef struct list * node;
    node insert(node,int);
    node fnUnion(node,node,node);
    node fnInter(node,node,node);
    node remDuplicate(node);
    void display(node);

int main()
{
    int ch,data;
    node list1,list2,un,in;
    list1=list2=un=in=NULL;
    while(1)
    {
        printf("\nEnter your choice\n1.Insert in List1\n2.Insert in List2\n3.Find Union\n4.Find Intersection\n5.Display\n6.Exit\n");
        scanf("%d",&ch);
        switch(ch)
            {
                case 1:printf("\nEnter data to be inserted\n");
                        scanf("%d",&data);
                        list1=insert(list1,data);
                        break;
                case 2:printf("\nEnter data to be inserted into list 2\n");
                        scanf("%d",&data);
                        list2=insert(list2,data);
                        break;
                case 3: un=fnUnion(un,list1,list2);
                        break;
                case 4:in=fnInter(in,list1,list2);
                        break;
                case 5:printf("list 1:\t");display(list1); printf("\n");printf("list 2:\t");display(list2); break;
                case 6:exit(0);
            }
    }
    return 0;
}
node insert(node s1,int data)

    {

        node temp,cur=NULL,prev=NULL;

        if((temp=(node)malloc(sizeof(struct list)))==NULL)
            {

                printf("NO MEMORY ALLCOATED"); return;
            }
            temp->data=data;
            temp->link=NULL;


        if(s1==NULL||data<=s1->data)
            {

                temp->link=s1;
                s1=temp;
                return(s1);
            }

        cur=s1;
        while(cur!=NULL &&data>cur->data)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=temp;
        temp->link=cur;
        return(s1);
    }


node fnUnion(node un,node list1,node list2)
{
    node temp,temp2,l1,l2;
    int flag=1;
    l1=list1;
    l2=list2;
    l1=remDuplicate(l1);
    l2=remDuplicate(l2);
    if(l1==NULL)

    un= l2;
    else if(l2==NULL)
        un=l1;
    //insert list 1
    else
    {


            while(l1!=NULL)
            {
                un=insert(un,l1->data);
                l1=l1->link;
            }

            //insert list 2 elements
            temp=un;
            temp2=l2;
            while (temp2!=NULL)
                {

                    while(temp!=NULL)
                    {
                        if(temp->data==temp2->data)
                        {
                            flag=0; break;
                        }
                        temp=temp->link;

                    }
                    if(flag)un=insert(un,temp2->data);
                    flag=1;
                    temp2=temp2->link;
                    temp=un;
                }
    }

        printf("union found\n");
        display(un);
}

node fnInter(node in,node list1,node list2)
{
    int flag=0;
    node temp1,temp2,l1,l2;
    l1=list1;
    l2=list2;
    l1=remDuplicate(l1);
    l2=remDuplicate(l2);
    temp1=l1;
    temp2=l2;
    while (temp1!=NULL )

        {

            while(temp2!=NULL)
            {


                if(temp1->data==temp2->data)
                {
                    flag=1; break;
                }
                temp2=temp2->link;

            }
            if(flag)in=insert(in,temp2->data);
            flag=0;
            temp1=temp1->link;
            temp2=l2;
        }


        printf("intersection found\n");
        display(in);
}

node remDuplicate(node list)
{
    node prev,temp;
    if(list==NULL)
    return;
    prev=list;
    temp=prev->link;

    while(prev->link!=NULL)
    {
        if(prev->data==temp->data)
        {
                prev->link=temp->link;
                free(temp);
                temp=prev->link;
                continue;
        }
        prev=temp;
        temp=temp->link;
    }
    return list;
}
void display(node t)
{
    if(t==NULL)
    {
        printf("No list to display");return;
    }

    while(t!=NULL)
    {
        printf("%d\t",t->data);
        t=t->link;
    }
}

