#include <stdio.h>
#include <stdlib.h>
struct doublyLinkedList
{
  int data;
  struct doublyLinkedList *next;
  struct doublyLinkedList *prev;
}*first;

void create(int n)
{
  struct doublyLinkedList *p=first;
  p=(struct doublyLinkedList *)malloc(sizeof(struct doublyLinkedList));
  scanf("%d", &p->data);
  p->next=NULL;
  p->prev=NULL;
  first=p;
while(n--)
{
  struct doublyLinkedList *t;
  t=(struct doublyLinkedList *)malloc(sizeof(struct doublyLinkedList));
  scanf("%d", &t->data);
  t->next=NULL;
  t->prev=p;
  p->next=t;
  p=t;
}
}

void display(struct doublyLinkedList *p)
{
while(p)
{
  printf("%d\t", p->data);
  p=p->next;
}
}

void insertbegin(int x)
{
  struct doublyLinkedList *p;
  p=(struct doublyLinkedList *)malloc(sizeof(struct doublyLinkedList));
  p->data=x;
  p->prev=NULL;
  p->next=first;
  first->prev=p;
  first=p;
}

void insertend(int y)
{
  struct doublyLinkedList *p , *temp=first;
  p=(struct doublyLinkedList*)malloc(sizeof(struct doublyLinkedList));
  p->data=y;
  while(temp->next!=NULL)
  temp=temp->next;
  p->prev=temp;
  temp->next=p;
  p->next=NULL;
}

void insertRandom(int z,int m)
{
struct doublyLinkedList *p,*t=first;
p=(struct doublyLinkedList*)malloc(sizeof(struct doublyLinkedList));
p->data=z;
for(int i=1;i<m-1;i++)
{
  t=(struct doublyLinkedList*)malloc(sizeof(struct doublyLinkedList));
  t=t->next;
}
  p->next=t->next;
  p->prev=t;
  t->next->prev=p;
  t->next=p;
}

void deletebegin(struct doublyLinkedList *p)
{
  struct doublyLinkedList *temp=first;
  p=p->next;
  p->prev=NULL;
  first=p;
  free(temp);
}

void deleteend(struct doublyLinkedList *p)
{
  struct doublyLinkedList *temp=first;
  while(p->next!=NULL)
  {
  temp=p;
  p=p->next;
  }
  temp->next=NULL;
  free(p);
}

void deleteRandom(int a)
{
  struct doublyLinkedList *p,*temp=first;
  p=first;
  for(int i=1;i<a;i++)
  {
    temp=p;
    p=p->next;
  }
  temp->next = p->next;
  p->next->prev=temp;
  free(p);
}

void reverse(struct doublyLinkedList *p)
{
  struct doublyLinkedList *temp=NULL;
  while(p)
  {
    temp=p->prev;
    p->prev=p->next;
    p->next=temp;
    p=p->prev;
  }
  if(temp)
  first=temp->prev;
}

void displayReverse(struct doublyLinkedList *p)
{
  while(p->next)
  p=p->next;
  while(p)
  {
    printf("%d\t",p->data );
    p=p->prev;
  }
}

int main ()
{
  int x,y,z,n,m,a;
  printf("Enter the number of data user want to enter\n");
  scanf("%d", &n);
  create(n-1);
  display(first);
  printf("\n");
  scanf("%d",&x);
  insertbegin(x);
  printf("\n");
  display(first);
  printf("\n");
  scanf("%d",&y);
  insertend(y);
  printf("\n");
  display(first);
  printf ("\n");
  scanf("%d",&z);
  printf("Enter the position User want to enter data\n");
  scanf("%d",&m);
  insertRandom(z,m);
  display(first);
  printf("\n");
  deletebegin(first);
  display(first);
  printf("\n");
  deleteend(first);
  display(first);
  printf("\n");
  printf("Enter the position user want to delete the data\n");
  scanf("%d",&a);
  deleteRandom(a);
  display(first);
  printf("\n");
  reverse(first);
  display(first);
  printf("\n");
  displayReverse(first);
  return 0;
}
