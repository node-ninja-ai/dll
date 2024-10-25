
https://prod.liveshare.vsengsaas.visualstudio.com/join?BEE9BA26FD3883E5DC0147B096C6FC166D8A

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev, *next;
};
typedef struct node node;
node *start = NULL, *temp = NULL, *newnode = NULL;
node* create()
{
    int n, non;
    printf("how many nodes du u wann:\n");
    scanf("%d", &non);
    printf("enter first data:\t");
    scanf("%d", &n);
    start = (node *)malloc(sizeof(node));
    start->data = n;
    start->next = NULL;
    start->prev = NULL;
    temp = start;
    for (int i = 2; i <= non; i++)
    {
        printf("enter %d data:\t", i);
        scanf("%d", &n);
        newnode = (node *)malloc(sizeof(node));
        newnode->data = n;
        newnode->next = NULL;
        newnode->prev = temp;
        temp->next = newnode;
        temp = newnode;
    }
    return start;
}

node* merged(node *list1,node *list2)
{
    if(!list1) return list2;
    if(!list2) return list1;

    if(list1->data <= list2->data)
    {
        start = list1;
        list1 = list1->next;
    }
    else
    {
        start = list2;
        list2 = list2->next;
    }

    temp = start;
    while(list1 != NULL && list2 != NULL)
    {
        if(list1->data <= list2->data)
        {
            temp->next = list1;
            list1->prev = temp;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2->prev = temp;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    if(list1 != NULL)
    {
        temp->next = list1;
        list1->prev = temp;
    }
    else if(list2 != NULL)
    {
        temp->next = list2;
        list2->prev = temp;
    }

    return start;
}

void display(node *list)
{
    temp = list;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int main()
{
   node *list1=NULL,*list2=NULL;
   list1=create();
   display(list1);
   list2=create();
   display(list2);
    printf("after merege\n");
    node *stofmerge=merged(list1,list2);
    display(stofmerge);
}



/* this is the program of circular

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev,*next;
};
typedef struct node node;
node *start=NULL,*temp=NULL,*newnode=NULL;
void create()
{
    int n,non;
    printf("how many nodes du u wann");
    scanf("%d",&non);
    printf("enter first data");
    scanf("%d",&n);
    start=(node *)malloc(sizeof(node));
    start->data=n;
    start->next=NULL;
    start->prev=NULL;
    temp=start;
    for(int i=2;i<=non;i++)
    {
        printf("enter %d data",i);
        scanf("%d",&n);
        newnode=(node *)malloc(sizeof(node));
        newnode->data=n;
        newnode->next=NULL;
        newnode->prev=temp;
        temp->next=newnode;
        temp=newnode;
    }
    
}
void circular()
{
    temp=start;
    node *ptr=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=start;
    start->prev=temp;
    
}

void display()
{
    temp=start;
    do
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }while(temp!=start);
}
int main()
{
    create();
    circular();
    printf("_________________________\nyour entered data are\n");
    display();
}

this is the program of addition of poly

#include <stdio.h>
#include <stdlib.h>

struct polynomial {
    int coe;        // Coefficient
    int pow;        // Power
    struct polynomial *next;
};

typedef struct polynomial poly;

poly *create() {
    int coef, powe, noofterms;
    poly *start = NULL, *temp = NULL, *newnode;

    printf("How many terms are there in your polynomial?\n");
    scanf("%d", &noofterms);

    for (int i = 1; i <= noofterms; i++) {
        printf("Enter the value of coefficient of term %d and its power: ", i);
        scanf("%d %d", &coef, &powe);

        newnode = (poly*)malloc(sizeof(poly));
        newnode->coe = coef;
        newnode->pow = powe;
        newnode->next = NULL;

        if (start == NULL) {
            start = newnode;
        } else {
            temp->next = newnode;
        }
        temp = newnode;
    }

    return start;
}

void display(poly *sop) {
    poly *temp = sop;

    while (temp != NULL) {
        if (temp->coe >= 0 && temp != sop) { 
            printf(" + ");
        }
        printf("%dX^%d", temp->coe, temp->pow);
        temp = temp->next;
    }
    printf("\n");
}

poly* addpoly(poly *t1, poly *t2) {
    poly *start = NULL, *temp = NULL, *newnode;

    while (t1 != NULL || t2 != NULL) {
        newnode = (poly*)malloc(sizeof(poly));
        newnode->next = NULL;

        if (t1 != NULL && t2 != NULL) {
            if (t1->pow == t2->pow) {
                newnode->coe = t1->coe + t2->coe;
                newnode->pow = t1->pow;
                t1 = t1->next;
                t2 = t2->next;
            } else if (t1->pow > t2->pow) {
                newnode->coe = t1->coe;
                newnode->pow = t1->pow;
                t1 = t1->next;
            } else {
                newnode->coe = t2->coe;
                newnode->pow = t2->pow;
                t2 = t2->next;
            }
        } else if (t1 != NULL) {  // Only t1 remains
            newnode->coe = t1->coe;
            newnode->pow = t1->pow;
            t1 = t1->next;
        } else if (t2 != NULL) {  // Only t2 remains
            newnode->coe = t2->coe;
            newnode->pow = t2->pow;
            t2 = t2->next;
        }

        if (start == NULL) {
            start = newnode;
        } else {
            temp->next = newnode;
        }
        temp = newnode;
    }

    return start;
}

int main() {
    poly *p1 = NULL, *p2 = NULL, *resp3 = NULL;

    p1 = create();
    printf("Your first polynomial is:\n");
    display(p1);

    p2 = create();
    printf("Your second polynomial is:\n");
    display(p2);

    printf("Addition of your both polynomials is:\n");
    resp3 = addpoly(p1, p2);
    display(resp3);

    return 0;
}
if i make header file of dll

#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};
typedef struct node node;

node *start = NULL, *temp = NULL, *newnode = NULL;

void create()
{
    int n, non;
    printf("How many nodes do you want?\n");
    scanf("%d", &non);
    if (non <= 0) {
        printf("Number of nodes must be greater than 0.\n");
        return;
    }

    printf("Enter first data: ");
    scanf("%d", &n);
    start = (node *)malloc(sizeof(node));
    start->data = n;
    start->next = NULL;
    start->prev = NULL;
    temp = start;
    for (int i = 2; i <= non; i++)
    {
        printf("Enter data for node %d: ", i);
        scanf("%d", &n);
        newnode = (node *)malloc(sizeof(node));
        newnode->data = n;
        newnode->next = NULL;
        newnode->prev = temp;
        temp->next = newnode;
        temp = newnode;
    }
}

void append()
{
    int n;
    printf("Enter data for append node: ");
    scanf("%d", &n);
    newnode = (node *)malloc(sizeof(node));
    newnode->data = n;
    newnode->next = NULL;
    temp = start;

    if (temp == NULL) {
        start = newnode;
        newnode->prev = NULL;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void display()
{
    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }

    temp = start;
    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insatanypos()
{
    int pos, n, i = 1;
    temp = start;
    printf("Enter position where you want to insert: ");
    scanf("%d", &pos);
    if (start == NULL) {
        printf("List is empty. Creating the first node.\n");
        pos = 1;
    }

    printf("Enter your data: ");
    scanf("%d", &n);
    newnode = (node *)malloc(sizeof(node));
    newnode->data = n;

    if (pos == 1)
    {
        newnode->next = start;
        newnode->prev = NULL;
        if (start != NULL) {
            start->prev = newnode;
        }
        start = newnode;
    }
    else
    {
        while (i < pos - 1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }

        if (temp == NULL || (temp->next == NULL && i < pos - 1)) {
            printf("Position out of bounds. Appending to the end.\n");
            append();
            return;
        }

        newnode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newnode;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void delatanypos()
{
    int pos, i = 1;
    printf("Enter position where you want to delete: ");
    scanf("%d", &pos);
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    temp = start;
    if (pos == 1)
    {
        start = temp->next;
        if (start != NULL) {
            start->prev = NULL;
        }
        free(temp);
    }
    else
    {
        while (i < pos && temp != NULL)
        {
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            printf("Position out of bounds.\n");
            return;
        }

        temp->prev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
}

void search(int key)
{
    temp = start;
    int i = 1;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element found at position %d.\n", i);
            return;
        }
        temp = temp->next;
        i++;
    }
    printf("Element not found.\n");
}

#endif // DLL_H
  and this is for dll main.c


  #include <stdio.h>
#include <stdlib.h>
#include "dll.h"

int main()
{
    int ch, key;
    printf("Doubly Linked List Operations Menu:\n");
    printf("1: Create\n");
    printf("2: Display\n");
    printf("3: Append\n");
    printf("4: Insert at any position\n");
    printf("5: Delete at any position\n");
    printf("6: Search\n");
    printf("7: Exit\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            append();
            break;
        case 4:
            insatanypos();
            break;
        case 5:
            delatanypos();
            break;
        case 6:
            printf("Enter the value of the node you want to search for: ");
            scanf("%d", &key);
            search(key);
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Choose a valid option from the menu.\n");
        }
    }

    return 0;
}

*/
