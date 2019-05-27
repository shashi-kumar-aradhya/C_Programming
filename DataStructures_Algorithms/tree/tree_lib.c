#include <stdio.h>
#include <stdlib.h>


typedef struct tree 
{
	int value;
	struct tree *lchild;
	struct tree *rchild;
}node;



void preorder(node *);
void inrder(node *);
void postorder(node *);


void insert(node **root, int value)
{
	if(*root == NULL)
	{
		node *temp = (node *)malloc(sizeof(node));
		if (NULL == temp)
		{
			printf("Failure in allocating memory\n");
			return;
		}
		temp->value = value;
		temp->lchild = NULL;
		temp->rchild = NULL;
		*root = temp;
		//printf("Inserted value = %d\n", value);
	}
	else if((*root)->value > value)
	{
		//(*root)->lchild = insert(&((*root)->lchild), value);
		insert(&((*root)->lchild), value);
	}		
	else if((*root)->value < value)
	{
		//(*root)->rchild = insert(&((*root)->rchild), value);
		insert(&((*root)->rchild), value);
	}		
	else	
	{
		printf("Duplicate key = %d\n", value);
	}
}

void preorder(node *root)
{
	if (NULL == root)
	{
	//	printf("no nodes\n");
		return;

	}
	printf("%d\t", root->value);
	preorder(root->lchild);
	preorder(root->rchild);
}
void inorder(node *root)
{
	if (NULL == root)
	{
	//	printf("no nodes\n");
		return;

	}
	inorder(root->lchild);
	printf("%d\t", root->value);
	inorder(root->rchild);
	
}
void postorder(node *root)
{
	if (NULL == root)
	{
	//	printf("no nodes\n");
		return;

	}
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d\t", root->value);
}

node *delete(node *root, int value)
{
	if(root == NULL)
	{
		printf("Tree is empty\n");
		return root;
	}
	if(root->value > value)
	{
		root->lchild = delete(root->lchild, value);
	}
	else if(root->value < value)
	{
	
		root->rchild = delete(root->rchild, value);
	}
	else			//
	{
		node *temp = NULL;
		if((root->lchild != NULL ) && (root->rchild != NULL))
		{
			temp = root->rchild;
			while(temp->lchild != NULL)
				temp = temp->lchild;
			root->value = temp->value;
			root->rchild = delete(root->rchild, temp->value);
		}
		else 
		{
			temp = root;
			if(NULL == root->lchild)
				root = root->lchild;
			else if(NULL == root->rchild)
				root = root->rchild;
			else
				root = NULL;
			free(temp);
		}
	}
	return root;
}
int main(int argc, char *argv[])
{
	int num_ele= atoi(argv[1]);
	node *root = NULL;
	int i = 0;
	int store_value;
	int del;
	for(i = 0; i < num_ele; i++)
	{
		store_value = rand() %100;
		insert(&root, store_value);
	}
	printf("Preorder : ");
	preorder(root);
	printf("\n");	
	printf("Inorder : ");
	inorder(root);
	printf("\n");	
	printf("Postorder : ");
	postorder(root);
	printf("\n");	
	for(i = 0; i < 5; i++)
	{
		printf("Enter the ele to be deleted : ");
		scanf("%d", &del);
		root = delete(root, del);
		printf("Preorder : ");
		preorder(root);
		printf("\n");	
		printf("Inorder : ");
		inorder(root);
		printf("\n");	
		printf("Postorder : ");
		postorder(root);
		printf("\n");	
		fflush(stdin);
	}
	return 0;
}


