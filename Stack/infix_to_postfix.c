/* C program to convert the given infix expression to postfix expression. */

#include <stdio.h>
#include <stdlib.h>

void push(char);
char pop();
int preced(char);

struct STACK
{
    char element[25];
    int top;
}stack;

int main()
{
    stack.top=-1;
    char infix[25],postfix[25],symbol,ch;
    int i,j=0;
    printf("Enter a valid infix expression:\t");
    scanf("%s",infix);
    for(i=0;infix[i]!='\0';i++)
    {
        symbol=infix[i];
        if(isalnum(symbol))
        {
            postfix[j++]=symbol;
        }
        else if(symbol=='(')
        {
            push(symbol);
        }
        else if(symbol==')')
        {
            while((ch=pop())!='(')
            {
                postfix[j++]=ch;
            }
        }
        else
        {
            while(stack.top!=-1 && preced(stack.element[stack.top])>=preced(symbol))
            {
                postfix[j++]=pop();
            }
            push(symbol);
        }
    }
    while(stack.top!=-1)
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("\nPostfix expression is: %s",postfix);
}

void push(char item)
{
    stack.element[++stack.top]=item;
}

char pop()
{
    return (stack.element[stack.top--]);
}

int preced(char ch)
{
    switch(ch)
    {
        case '(': return -1; break;
        case '+': return 0; break;
        case '-': return 0; break;
        case '/': return 1; break;
        case '*': return 1; break;
        case '%': return 1; break;
        case '$': return 2; break;
        case '^': return 2; break;
    }

}
