/* C program to implement addition of two polynomials using singly linked list..*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct polynomial
{
    int coeff;
    int exponent;
    struct polynomial *link;
 };

typedef struct polynomial *node;

node fnGetnode(void);
node fnInsertRear(int, int, node);
node fnAddPoly(node, node);
int evalPoly(node, int);
void fnDisplay(node first);


int main()
{
    node poly1, poly2, poly3;
    int i, x, res, degree, coefficient[10];
    poly1 = poly2 = poly3 = NULL;
    printf("\nEnter the degree of polynomial 1\n");
    scanf("%d", &degree);
    printf("\nEnter the coefficient\n");
    for(i=degree;i>=0;i--)
    {
        printf("of x^%d:\t",i);
        scanf("%d", &coefficient[i]);
        poly1 = fnInsertRear(coefficient[i], i, poly1);
    }
    printf("\nEnter the degree of polynomial 2\n");
    scanf("%d", &degree);
    printf("\nEnter the coefficient\n");
    for(i=degree;i>=0;i--)
    {
        printf("of x^%d:\t",i);
        scanf("%d", &coefficient[i]);
        poly2 = fnInsertRear(coefficient[i], i, poly2);
    }
    poly3 = fnAddPoly(poly1, poly2);
    printf("Polynomial 1 :\t");
    fnDisplay(poly1);
    printf("Polynomial 2 :\t");
    fnDisplay(poly2);
    printf("Polynomial Sum :");
    fnDisplay(poly3);
    printf("\nEnter the value of x\n");
    scanf("%d", &x);
    res = evalPoly(poly3, x);
    printf("\nValue of the polynomial sum for x = %d is %d\n", x, res);
    return 0;
}




//poly1 = fnInsertRear(coeff[i], i, poly1) ;
node fnInsertRear(int coeff, int Exp, node first)
{
    node temp,cur;
    temp = fnGetnode();
    temp->coeff = coeff;
    temp->exponent = Exp;
    temp->link = NULL;
    if(first == NULL)
    return temp;
    cur = first;
    while(cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}


node fnGetnode(void)
{
    node newnode;
    newnode = ( node ) malloc (sizeof(struct polynomial));
    if(newnode == NULL)
    {
        printf("Memory not allocated");
        exit(0);
    }
    return newnode;
}



void fnDisplay(node first)
{
    node cur;
    for(cur = first; cur->link != NULL; cur = cur->link)
    {

        printf(" (%d) x^%d +",cur->coeff,cur->exponent);
    }
    printf(" %d\n", cur->coeff);
}


// poly3 = fnAddPoly(poly1, poly2) ;
node fnAddPoly(node poly1, node poly2)
{
    node tracker1, tracker2,poly3 = NULL;
    tracker1 = poly1;
    tracker2 = poly2;
    while(tracker1 != NULL && tracker2 != NULL)
    {
        if(tracker1->exponent > tracker2->exponent)
        {
            poly3 = fnInsertRear(tracker1->coeff, tracker1->exponent, poly3);
            tracker1 = tracker1->link;
        }
        else if(tracker1->exponent == tracker2->exponent)
        {
            poly3 = fnInsertRear(tracker1->coeff + tracker2->coeff, tracker1->exponent, poly3);
            tracker1 = tracker1->link;
             tracker2 = tracker2->link;
        }
        else
        {
            poly3 = fnInsertRear(tracker2->coeff, tracker2->exponent, poly3);
            tracker2 = tracker2->link;
        }
    }
    return poly3;
}


int evalPoly(node list, int x)
{
    int Sum = 0;
    node cur = list;
    while(cur!=NULL)
    {
        Sum += (cur->coeff * (int)pow(x, cur->exponent));
        cur = cur->link;
    }
    return Sum;
}
