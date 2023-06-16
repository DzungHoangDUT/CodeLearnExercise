/*
Enter a positive integer n, install a list on the pairing to store numbers from n down to 1 and from 1 to n. 
Print that linked list, with a space after each element.
----------------------------------------------------------------------------------------------------
Input: 3
Output: 3 2 1 2 3
*/

#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
    int data;
    struct node *nextNode;
    struct node *preNode;
} node;
node *createNode(int data)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode -> data = data;
    newNode -> nextNode = NULL;
    newNode -> preNode = NULL;
    return newNode;
}
node *addTail(int data, node *tailNode)
{
    node *newTail = createNode(data);
    newTail -> preNode = tailNode;
    tailNode -> nextNode = newTail;
    return  newTail;
}
node *addHead(int data, node *headNode)
{
    node *newHead = createNode(data);
    newHead -> nextNode = headNode;
    headNode -> preNode = newHead;
    return newHead;
}
void printFromHead(node *headNode)
{
    node *p = headNode;
    while (p != NULL)
    {
        printf("%d ", p -> data);
        p = p -> nextNode;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    node *headNode = createNode(1);
    node *tailNode = headNode;
    for (int i = 2; i <= n; ++i)
    {
        headNode = addHead(i, headNode);
        tailNode = addTail(i, tailNode);
    }
    printFromHead(headNode);
    return 0;
}