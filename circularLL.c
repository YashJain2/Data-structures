#include<stdio.h>
#include<stdlib.h>
struct CLL
{
  int data;
  struct CLL *next;
}*first;

void create(int x)
{
  struct CLL *p;
  struct CLL *temp;
  temp=(struct CLL*)malloc(sizeof(struct CLL));
  scanf("%d",&temp->data );
  temp->next=NULL;
  first=temp;
  for(int i=1;i<=x-1;i++)
  {
      p=(struct CLL*)malloc(sizeof(struct CLL));
    scanf("%d",&p->data);
    p->next=first;
    temp->next=p;
    temp=p;
  }
}

void display(struct CLL *p)
{
  do{
    printf ("%d\t",p->data);
    p=p->next;
  }while(p!=first);
}

void insertBegin(int y)
{
struct CLL *p,*temp=first;
while(temp->next!=first)
temp=temp->next;
p=(struct CLL*)malloc(sizeof(struct CLL));
temp->next=p;
p->data=y;
p->next=first;
first=p;
}

void deleteBegin(struct CLL *p)
{
  struct CLL *temp;
  while(temp->next!=first)
  temp=temp->next;
  p=p->next;
  temp->next=p;
  free(first);
  first=p;
}

int main ()
{
  printf ("Enter the number of data to be feed\n ");
  int x,y,z;
  scanf("%d",&x);
  create (x);
  display(first);
  printf("\n");
  scanf("%d",&y);
  insertBegin(y);
  display(first);
  deleteBegin(first);
  printf("\n The first element is deleted from the circular linked list : ");
  display(first);
  return 0;
}
