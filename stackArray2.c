#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
struct stack
{
  int top;
  int capacity;
  int *array;
};

struct stack *createStack(int capacity)
{
  struct stack *s=malloc(sizeof(struct stack));
  if(!s)
  return NULL;
  s->capacity=capacity;
  s->top=-1;
  s->array=malloc(s->capacity*sizeof(int));
  if(!s->array)
  return NULL;
  return s;
}

int isEmpty(struct stack *s)
{
  return (s->top==-1);
}

int size(struct stack *s)
{
  return (s->top+1);
}

int isFull(struct stack*s)
{
  return (s->top==s->capacity-1);
}

void doubleStack(struct stack *s)
{
  s->capacity=s->capacity*2;
  s->array=realloc(s->array,s->capacity*sizeof(int));
}

void push(struct stack *s,int data)
{
  if(isFull(s))
  doubleStack(s);
  else
  s->array[++s->top]=data;
}

int pop(struct stack*s)
{
  if(isEmpty(s))
  {
    printf ("Stack is empty\n");
    return INT_MIN;
  }
  else
  return (s->array[s->top--]);
}

int peek(struct stack*s)
{
  if(isEmpty(s))
  {
    printf ("Stack is empty\n");
    return INT_MIN;
  }
  else
  return (s->array[s->top]);
}

void delete(struct stack*s)
{
  if(s)
  {
    if(s->array)
    free(s->array);
    free(s);
  }
}

int main ()
{
  int i=0,capacity=5;
  //creates a stack of capacity of 15
  struct stack *stk=createStack(capacity);
  for(i=0;i <=2*capacity;i++)
  push(stk,i);
  printf ("Top element is %d\n", peek(stk));
  printf ("Stack size is %d\n", size(stk));
  for(i=0;i<=2*capacity;i++)
  printf ("Popped element is %d\n",pop(stk));
  if (isEmpty(stk))
  printf ("Stack is empty\n");
  else
  printf ("Stack is not empty");
  delete(stk);
  return 0;
}
