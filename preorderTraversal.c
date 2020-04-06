#include <stdio.h>
#include<limits.h>
#include<stdlib.h>

//declaration of the tree element right, left and data type
struct node
{
  int data;
  struct node *left;
  struct node *right;
}*Node;
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

//Preorder traversing using recursion
void preorder(struct node *root)
{
  if(root)
  {
    printf ("%d  ",root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

int main ()
  {
    //struct node *t,*root;
    struct node *root=create();
    struct node *t=root;
    //traverse(t);
    printf ("Root child : %d\n",t->data);
    printf ("Preorder traversal\n");
    preorder(t);
    return 0;
  }
