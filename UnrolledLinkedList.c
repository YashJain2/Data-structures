#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>
#include<time.h>

int blockSize;//Max.number of nodes in a block
struct ListNode
{
  struct ListNode *next;
  int value;
};

struct LinkedBlock
{
  struct LinkedBlock *next;
  struct LinkedBlock *head;
  int nodeCount;
};

struct LinkedBlock *blockHead;

//create an empty blockHead
struct LinkedBlock *newLinkedBlock()
{
  struct LinkedBlock * block=(struct LinkedBlock*)malloc(sizeof(struct LinkedBlock));
  block->next=NULL;
  block->head=NULL;
  block->nodeCount=0;
  return block;
}

//create a node
struct ListNode *newListNode(int value)
{
  struct ListNode*temp=(struct ListNode*)malloc(sizeof(struct ListNode));
  temp->next=NULL;
  temp->value=value;
  return temp;
}

void searchElement(int k,struct LinkedBlock **fLinkedBlock,struct ListNode ** fListNode)
{
//find the block
int j=(k+blockSize-1)/blockSize;  // kth node is in the jth block
struct LinkedBlock*p=blockHead;
while(--j)
p=p->next;
*fLinkedBlock=p;
// find the node
struct ListNode *q=p->head;
k=k%blockSize;
k=p->nodeCount+1-k;
while(k--)
q=q->next;
*fListNode=q;
}

//start shift operation from block
void shift(struct LinkedBlock *A)
{
  struct LinkedBlock *B;
  struct ListNode *temp;
  while(A->nodeCount > blockSize) // If the block still have to shift
  {
    if(A->next==NULL)
    {
      A->next=newLinkedBlock();
      B=A->next;
      temp=A->head->next;
      A->head->next=A->head->next->next;
      B->head=temp;
      temp->next=temp;
    A->nodeCount--;
    B->nodeCount++;
  }
    else
    {
      B=A->next;
      temp=A->head->next;
      A->head->next=A->head->next->next;
      temp->next=B->head->next;
      B->head->next=temp;
      B->head=temp;
      A->nodeCount--;
      B->nodeCount++;
    }
    A=B;
  }
}

void addElement(int k,int x)
{
  struct LinkedBlock *r;
  struct ListNode *p,*q;
  if(!blockHead)
  {
    blockHead=newLinkedBlock();
    blockHead->head=newListNode(x);
    blockHead->head->next=blockHead->head;
    blockHead->nodeCount++;
  }
  else
  {
    if(k==0)  //special case
    {
      p=blockHead->head;
      q=p->next;
      p->next=newListNode(x);
      p->next->next=q;
      blockHead->head=p->next;
      blockHead->nodeCount++;
      shift(blockHead);
    }
    else
    {
      searchElement(k,&r,&p);
      q=p;
      while(q->next!=p)
      q=q->next;
      q->next=newListNode(x);
      q->next->next=p;
      r->nodeCount++;
      shift(r);
    }
  }
}

int searchElement(int k)
{
  struct ListNode*p;
  struct LinkedBlock *q;
  searchElement(k,&q,&p);
  return p->value;
}

int testUnrolledLinkedList()
{
  int t=clock();
  int m,i,k,x;
  char cmd[10];
  scanf("%d",&m);
  blockSize=(int)(sqrt(m-0.001))+1;
  for(i=0;i<m;i++)
  {
    scanf("%s",cmd);
    if(strcmp(cmd,"add")==0)
    {
      scanf("%d %d", &k,&x);
      addElement(k,x);
    }
    else if(strcmp(cmd,"search")==0)
    {
      scanf("%d",&k);
      printf("%d\n",searchElement(k));
    }
    else
    fprintf(stderr,"Wrong Input\n");
  }
  return 0;
}
