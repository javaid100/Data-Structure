/*  Array Implementation of List ADT  */

#include<stdio.h>
#include<stdlib.h>

#define MAX 10

void create();
void insert();
void deletion();
void search();
void display();

int b[20], n;

// Create the List
void create()
{
 printf("=== Create the List first === \n");
 printf("Enter the number of nodes: ");
 scanf("%d", &n);
 printf("Enter the  Elements:\n");
 for (int i=0; i<n; i++)
    {
     scanf("%d", &b[i]);
    }
}

// Delete the element from the list
void deletion()
{
 int pos;
 printf("Enter the position you want to delete: ");
 scanf("%d", &pos);
 if (pos>=n)
   {
    printf(":: Invalid Location ::");
   }
 else
   {
    for (int i=pos+1; i<n; i++)
       {
        b[i-1]=b[i];
       }
    n--;
   }
 printf("The Elements after deletion: ");
 for (int i=0; i<n; i++)
    {
     printf("\t%d", b[i]);
    }
 printf("\n");
}

// Search the element from the list
void search()
{
 int e;
 printf("Enter the Element to be searched: ");
 scanf("%d", &e);
 for (int i=0; i<n; i++)
    {
     if (b[i] == e)
       {
        printf("Value is in the %d Position\n", i);
       }
    }
}

// Insert the element in the list
void insert()
{
 int pos, p;
 printf("Enter the position you need to insert: ");
 scanf("%d", &pos);
 if (pos>=n)
   {
    printf("!! Invalid Location !!");
   }
 else
   {
    for (int i=MAX-1; i>=pos-1; i--)
       {
        b[i+1]=b[i];
       }
    printf("Enter the element to insert: ");
    scanf("%d",&p);
    b[pos]=p;
    n++;
   }
}

// Display the list
void display()
{
 printf("The Elements of The list ADT are: ");
 for (int i=0; i<n; i++)
    {
     printf("\n%d", b[i]);
    }
 printf("\n");
}

void main()
{
 int ch;
 create();

 printf("\n------------------\n 1.Delete \n 2.Search \n 3.Insert \n 4.Display\n 5.Exit \n-------------------\n");

 for(;;)
      {
       printf("\nEnter your Choice: ");
       scanf("%d", &ch);

       switch (ch)
             {
              case 1:
                     deletion();
                     break;
              case 2:
                     search();
                     break;
              case 3:
                     insert();
                     break;
              case 4:
                     display();
                     break;
              case 5:
                     exit(0);
              default:
                     printf("\nEnter correct option! Try again.");
             }
      }
}
