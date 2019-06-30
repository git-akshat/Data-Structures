/* C program to perform the following operations:
a Construct a binary search tree of integers.
b Traverse the tree in inorder/ preorder/ postorder.
c Delete a given node from the BST. */

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *lbranch;
	struct node *rbranch;
};

typedef struct node* NODEPTR;

/* FUNCTION PROTOTYPES */
NODEPTR fnGetNode(void);
void fnFreeNode(NODEPTR x);
NODEPTR fnInsertNode(int, NODEPTR);
void fnInOrder(NODEPTR);
void fnPreOrder(NODEPTR);
void fnPostOrder(NODEPTR);
NODEPTR fnDeleteNode(NODEPTR, int);
NODEPTR fnMinValueNode(NODEPTR);

int main()
{
	NODEPTR root = NULL;
	int iChoice, iItem;
	for(;;)
	{
		printf("\n1.Insert a node\n2.Inorder traversal\n3.Preorder traversal");
		printf("\n4.Postorder traversal\n5.Delete a node\n6.Exit\n");
		printf("\nEnter your choice");
		scanf("%d",&iChoice);
	
		switch(iChoice)
		{
			case 1: printf("Enter the item to be inserted \n");
					scanf("%d",&iItem);
					root = fnInsertNode(iItem,root);
					break;
		
			case 2: if(root ==NULL)
					{
						printf("\nTree is Empty\n");
					}
					else
					{
						printf("\nInorder Traversal is :\n");
						fnInOrder(root);
						printf("\n");
					}
					break;
		
			case 3: if(root ==NULL)
					{
						printf("\nTree is Empty\n");
					}
					else
					{
						printf("\nPreorder Traversal is :\n");
						fnPreOrder(root);
						printf("\n");
					}
					break;
		
			case 4: if(root ==NULL)
					{
						printf("\nTree is Empty\n");
					}
					else
					{
						printf("\nPostorder Traversal is :\n");
						fnPostOrder(root);
						printf("\n");
					}
					break;
			
			case 5: printf("\nEnter node to be deleted : ");
					scanf("%d", &iItem);
					root = fnDeleteNode(root, iItem);
					break;
			
			case 6: exit(0);
			
			default: printf("Wrong choice\n");
					 break;
		}
	}
	return 0;
}

NODEPTR fnGetNode(void)
{
	NODEPTR x;
	x = ( NODEPTR ) malloc (sizeof(struct node));
	if(x == NULL)
	{
		printf("\nOut of Memory");
		exit(0);
	}
	return x;
}

void fnFreeNode(NODEPTR x)
{
	free(x);
}

NODEPTR fnInsertNode(int iItem, NODEPTR root)
{
	NODEPTR temp,prev,cur;
	
	temp = fnGetNode();
	temp->info = iItem;
	temp->lbranch = NULL;
	temp->rbranch = NULL;
	
	if(root == NULL)
		return temp;
	
	prev = NULL;
	cur = root;
	
	while(cur != NULL)
	{
		prev = cur;
		
		if(iItem == cur->info)
		{
			printf("\nDuplicate items not allowed\n");
			fnFreeNode(temp);
			return root;
		}
		
		cur = (iItem < cur->info)? cur->lbranch: cur->rbranch;
	}
	
	if(iItem < prev->info)
		prev->lbranch = temp;
	else
		prev->rbranch = temp;
	
	return root;

}

void fnPreOrder(NODEPTR root)
{
	if(root != NULL)
	{
		printf("%d\t",root->info);
		fnPreOrder(root->lbranch);
		fnPreOrder(root->rbranch);
	}
}

void fnInOrder(NODEPTR root)
{
	if(root != NULL)
	{
		fnInOrder(root->lbranch);
		printf("%d\t",root->info);
		fnInOrder(root->rbranch);
	}
}

void fnPostOrder(NODEPTR root)
{
	if(root != NULL)
	{
		fnPostOrder(root->lbranch);
		fnPostOrder(root->rbranch);
		printf("%d\t",root->info);
	}
}

NODEPTR fnDeleteNode(NODEPTR root, int iItem)
{
	if(root == NULL)
	{
		printf("\nBST is empty, cannot delete");
		return root;
	}
	// If the item to be deleted is smaller than the root’s item,
	// then it lies in left subtree
	if (iItem < root->info)
		root->lbranch = fnDeleteNode(root->lbranch, iItem);
	
	// If the item to be deleted is greater than the root’s item,
	// then it lies in right subtree
	else if (iItem > root->info)
		root->rbranch = fnDeleteNode(root->rbranch, iItem);
	
	// if item is same as root’s item, then This is the node
	// to be deleted
	else
	{
		// node with only one child or no child
		if (root->lbranch == NULL)
		{
			NODEPTR temp = root->rbranch;
			free(root);
			return temp;
		}
		else if (root->rbranch == NULL)
		{
			NODEPTR temp = root->lbranch;
			free(root);
			return temp;
		}
		
		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		NODEPTR temp = fnMinValueNode(root->rbranch);
		
		// Copy the inorder successor’s content to this node
		root->info = temp->info;
		
		// Delete the inorder successor
		root->rbranch = fnDeleteNode(root->rbranch, temp->info);
	}
	return root;
}

NODEPTR fnMinValueNode(NODEPTR node)
{
	NODEPTR current = node;
	
	/* loop down to find the leftmost leaf */
	while (current->lbranch != NULL)
		current = current->lbranch;
	
	return current;
}