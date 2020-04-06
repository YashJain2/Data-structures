#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
 struct LL
 {
   int data;
   struct LL *next;
 };

 struct stack
 {
   struct LL *top;
 };

 struct stack *createStack()
 {
   struct stack *stk;
   stk=malloc(sizeof(struct stack));
   stk->top=NULL;
   return stk;
 }

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

int isEmpty(struct stack *stk)
{
  return (stk->top==NULL);
}

int size(struct stack*stk)
{
  int count=0;
  struct LL *temp;
  if(isEmpty(stk))
  return 0;
  temp=stk->top;
  while(temp)
  {
    count++;
    temp=temp->next;
  }
  return count;
}

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

int peek(struct stack *stk)
{
  if(isEmpty(stk))
  return INT_MIN;
  return stk->top->data;
}

void delete(struct stack *stk)
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

int main ()
{
  int i=0;
  struct stack *stk=createStack();
  for(i=0;i<=10;i++)
  push(stk,i);
  printf ("Top element is %d\n",peek(stk));
  printf ("Stack size is %d\n",size(stk));
  for(i=0;i<=10;i++)
  printf ("Popped element is %d\n",pop(stk));
  if(isEmpty(stk))
  printf ("stack is empty");
  else
  printf("Stack is not empty");
  delete(stk);
  return 0;
}
