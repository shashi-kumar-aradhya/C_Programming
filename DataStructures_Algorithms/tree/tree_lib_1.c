#include<stdio.h> 
#include<stdlib.h> 
  
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
  
// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->key); 
        inorder(root->right); 
    } 
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}
 
  
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if(key > node->key)
        node->right = insert(node->right, key); 
    else 
	printf("Duplicate key\n");
  
    /* return the (unchanged) node pointer */
    return node; 
} 
  
/* Given a non-empty binary search tree, return the node with minimum 
   key value found in that tree. Note that the entire tree does not 
   need to be searched. */
struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
  
/* Given a binary search tree and a key, this function deletes the key 
   and returns the new root */
struct node* deleteNode(struct node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->key = temp->key; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 

int main(int argc, char *argv[])
{
        int num_ele= atoi(argv[1]);
        struct node *root = NULL;
        int i = 0;
        int del;
        for(i = 0; i < num_ele; i++)
        {
//                store_value = rand() %100;
               printf("Enter the ele to be inserted : ");
               scanf("%d", &del);
               root = insert(root, del);
               fflush(stdin);
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
        for(i = 0; i < num_ele/2; i++)
        {
               printf("Enter the ele to be deleted : ");
                scanf("%d", &del);
                root = deleteNode(root, del);
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

