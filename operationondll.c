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
}

void append()
{
    int n;
    printf("enter data of append node");
    scanf("%d", &n);
    newnode = (node *)malloc(sizeof(node));
    newnode->data = n;
    newnode->next = NULL;
    newnode->prev = NULL;
    temp = start;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void display()
{
    temp = start;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
void insatanypos()
{
    int pos, n, i = 1;
    temp = start;
    printf("enter position where u wann to insert:\n");
    scanf("%d", &pos);
    if (start == NULL)
    {
        printf("u have not create your node yet");
        exit(0);
    }
    if (pos == 1)
    {

        printf("enter your data:\n");
        scanf("%d", &n);
        newnode = (node *)malloc(sizeof(node));
        newnode->data = n;
        newnode->next = temp;
        newnode->prev = NULL;
        temp->prev = newnode;
        start = newnode;
    }
    else
    {

        printf("enter data:\n ");
        scanf("%d", &n);
        newnode = (node *)malloc(sizeof(node));
        newnode->data = n;
        newnode->next = NULL;
        newnode->prev = NULL;
        while (i < pos - 1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }

        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void delatanypos()
{
    int pos, n, i = 1;
    temp = start;
    printf("enter position where u wann to delete:\n");
    scanf("%d", &pos);
    if (start == NULL)
    {
        printf("u have not create your node yet");
        exit(0);
    }
    if (pos == 1)
    {
        start = temp->next;
        start->prev = NULL;
        free(temp);
    }
    else
    {
        while (i < pos - 1 && temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        node *pre = NULL, *post = NULL;
        pre = temp->next;
        post = pre->next;
        post->prev = temp;
        temp->next = pre->next;
        free(pre);
    }
}
void search(int key)
{
    temp = start;
    int i = 0;
    while (temp != NULL)
    {
        i++;
        if (key == temp->data)
        {
            printf("element is found at postion %d\n", i);
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("element is not found\n");
    }
}
int main()
{
    int ch,key;
    printf("1:create\n2:display\n3:append\n4:insertatanypos\n5:delatanypos\n6:search\n7:exit\n");
    while (1)
    {
        printf("enter your choice\n");
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
           
            printf("enter the value of node that u wann to search\n");
            scanf("%d", &key);
            search(key);
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("choose right option from given menu");
        }
    }
}