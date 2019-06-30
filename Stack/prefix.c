/* C program to evaluate the given prefix expression. */

#include <stdio.h>
#include <stdlib.h>
void push(char);
int pop();
struct STACK
{
    char element[25];
    int top;
}stack;

int main()
{
    stack.top=-1;
    int val1,val2;
    char prefix[25],symbol;
    int i,res;
    printf("Enter a valid prefix expression:\t");
    scanf("%s",prefix);
    for(i=strlen(prefix)-1;i>=0;i--)
    {
        symbol=prefix[i];
        if(isdigit(symbol))
        {
            push(symbol-'0');
        }
        else
        {
            val1=pop();
            val2=pop();
            switch(symbol)
            {
                case '+': res=val1+val2; break;
                case '-': res=val1-val2; break;
                case '*': res=val1*val2; break;
                case '/': res=val1/val2; break;
            }
            push(res);
        }
    }
    res=pop();
    printf("\n value of %s is %d",prefix,res);
}

void push(char item)
{
    stack.element[++stack.top]=item;
}

int pop()
{
    return(stack.element[stack.top--]);
}
