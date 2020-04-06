#include <stdio.h>
 int top=-1; // Delaring a Top variable initially pointing to -1
 int stack [10]; // a stack array of 10 elements

int main()
{

    // Push operation in stack  array
    for (int i=0; i<10; i++)
    {
    top=top+1;
    stack[top]=i+1;
      }

   // Printing content of stack array
     for (int i=0; i<10; i++)
     {
     printf(" The element in the stack are %d\n",stack[i]);
     }

    // pop operation in stack array
//follows last in first out pattern
    for (int i=3; i<=10; i++)
     {
     printf(" poping %d  element  %d\n",i, stack[top]);
     top=top-1;
     }

    printf(" After performing pop operation the content of stack is %d\n",stack[top]);

    return 0;
}
