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
/*
//Creating a Stack using linked list
struct LL
{
  int data;
  struct LL *next;
};

struct stack
{
  struct LL *top;
};
//declaring a stack
struct stack *createStack()
{
  struct stack *stk;
  stk=malloc(sizeof(struct stack));
  stk->top=NULL;
  return stk;
}
//insering an element in a stack
void push(struct stack *stk, int data)
{
 struct LL *temp;
 temp=malloc(sizeof(struct LL));
 if(!temp)
 {
   printf ("Stack Overflow\n");
   return ;
 }
 temp->data=data;
 temp->next=stk->top;
 stk->top=temp;
}
//Checking for an empty stack
int isEmpty(struct stack *stk)
{
 return (stk->top==NULL);
}
//deletion of an element
int pop(struct stack *stk)
{
  int data;
  struct LL *temp;
  if(isEmpty(stk))
  return INT_MIN;
  temp=stk->top;
  stk->top=stk->top->next;
  data=temp->data;
  free(temp);
  return data;
}
void delete(struct stack *stk)
//freeing up the stack memory
{
  struct LL*temp,*p;
  p=stk->top;
  while(p)
  {
    temp=p->next;
    p=p->next;
    free(temp);
  }
  free(stk);
}
*/
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
/*void inOrder(struct node)
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
  delete(s);
}
*/
int main ()
  {
    //struct node *t,*root;
    struct node *root=create();
    struct node *t=root;
    //traverse(t);
    printf ("Root child : %d\n",t->data);
    printf ("Inorder traversal\n");
    Inorder(t);
    return 0;
  }
