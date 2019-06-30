/* C program to construct an expression tree for a given postfix expression and evaluate
the expression tree. */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

struct exp_tree
{
    char info;
    struct exp_tree *lchild,*rchild;
};

typedef struct exp_tree *node;

node create_tree(char postfix[]);
float  eval(node root);

int main()
{
	 char postfix[30];
	 float res;
	 node  root = NULL;
     printf("\nEnter a valid Postfix expression\n");
	 scanf("%s",postfix);

	 root = create_tree(postfix);

	 res = eval (root);

	 printf("\nResult = %f",res);
     return 0;
}


node create_tree(char postfix[])
{
	 node newnode, stack[20];
	 int i=0, top = -1;
	 char ch;

	 while((ch=postfix[i++])!='\0')
	{
	     newnode = (node)malloc(sizeof(struct exp_tree));
	     newnode->info = ch;
	     newnode->lchild = newnode->rchild = NULL;

	     if(isalnum(ch))
		     stack[++top]=newnode;
	     else
	     {
		     newnode->rchild = stack[top--];
		     newnode->lchild = stack[top--];
             stack[++top]=newnode;
	     }
	  }
	  return(stack[top--]);
}

float  eval(node root)
{
	float num;
	switch(root->info)
	{
	    case  '+' : return (eval(root->lchild) + eval(root->rchild));
	    case  '-' : return (eval(root->lchild) - eval(root->rchild));
	    case  '*' : return (eval(root->lchild) * eval(root->rchild));
	    case  '/' : return (eval(root->lchild) / eval(root->rchild));
	    case  '^' : return (pow(eval(root->lchild), eval(root->rchild)));
	    default:    if(isalpha(root->info))
		         	{
		         		printf("\n%c = ",root->info);
			        	scanf("%f",&num);
			        	return(num);
		         	}
		        	else
		        	{
    			        return(root->info - '0');
		        	}
    }
}


