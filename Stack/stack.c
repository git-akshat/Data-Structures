/* C program to implement STACK to perform the PUSH, POP and DISPLAY operations. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
void fnpush();
void fnpop();
void fndisplay();

struct stack
{
    int element[MAX];
    int top;
}s;

int main()
{
    int choice;
    s.top = -1;
    while(1)
    {
        printf("\nEnter your choice\n1.Push\t2.Pop\t3.Display\t4.Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: if(s.top == MAX-1)
                    {
                        printf("\nStack Overflow");
                        break;
                    }
                    fnpush();
                    break;

            case 2: if(s.top==-1)
                    {
                        printf("\nStack Underflow");
                        break;
                    }
                    fnpop();
                    break;

            case 3: fndisplay();
                    break;

            case 4: exit(0);

            default: printf("\nInvalid choice");
                     break;
        }
    }
}

void fnpush()
{
    printf("\nEnter item to push: ");
    scanf("%d", &s.element[++s.top]);
}

void fnpop()
{
    printf("\nPoped item is: %d", s.element[s.top--]);
}

void fndisplay()
{
    int i;
    printf("\nElements of stack are: ");

    for(i=s.top; i>-1; i--)
    {
        printf("%d ",s.element[i]);
    }
    printf("\n");
}