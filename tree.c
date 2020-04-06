#include <stdio.h>
#include<stdlib.h>

//declaration of the tree element right, left and data type
struct node
{
  int data;
  struct node *left;
  struct node *right;
}*Node;

//Creating root node
struct node *create()
{
  int x;
  //struct node *newnode;
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  printf ("Enter the data for the nodes (-1 for no data)");
  scanf("%d",&x);
  newnode->data=x;
  if(x==-1)
  {
    printf ("Not entered any data\n");
    return NULL;
  }
  printf("Enter the left child of the rooted data %d\t",newnode->data);
  newnode->left=create();
  printf("Enter the right child of the rooted data %d\t",newnode->data);
  newnode->right=create();
  return newnode;
}

//Inorder traversing using recursion
void Inorder(struct node *root)
{
  if(root)
  {
    Inorder(root->left);
    printf ("%d  ",root->data);
    Inorder(root->right);
  }
}

//traversing in a tree using non-recursive iterations
/*void inOrder(struct binaryTreeNode)
{
  struct stack *s=createStack();
  while(1)
  {
    while(root)
    {
      push(s,root);
      root=root->left;
    }
    if(isEmpty(s))
    break;
    root=pop(s);
    printf("%d",root->data);
    root=root->right;
  }
  deleteStack(s);
}*/

int main ()
  {
    //struct node *t,*root;
    struct node *root=create();
    struct node *t=root;
    //traverse(t);
    printf ("Root child : %d"\n,t->data);
    printf ("Inorder traversal\n");
    Inorder(t);
    return 0;
  }
