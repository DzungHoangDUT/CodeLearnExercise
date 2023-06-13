/*
 * Enter a positive integer n, followed by the integer of a sequence, install it in a singly linked list->
 * Continue to enter two integers a and b-> Then, change the values ​​of the elements with the value a to the value b->
 * Print that list to the screen, followed by exactly one space->
 * -----------------------------------------------------------------------------------------------------------------
 * Test case:
 * Input: 6
 *        1 1 2 2 3 3
 *        2 10
 * Ouptut: 1 1 10 10 3 3
 */

#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
    int data;
    struct node *pNext;
} node;

node* createNode(int data)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->pNext = NULL;
    return newNode;
}
node* addTailNode(int data, node *headNode)
{
    node* newTailNode = createNode(data);
    headNode -> pNext = newTailNode;
    return newTailNode;
}
void printList(node *headNode)
{
    node *p = headNode;
    while (p != NULL)
    {
        printf("%d ", p -> data);
        p = p -> pNext;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    node *headNode, *tailNode;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        scanf("%d", &tmp);
        if (i == 0)
        {
            headNode = createNode(tmp);
            tailNode = headNode;
        }
        else tailNode = addTailNode(tmp, tailNode);
    }
    int a, b;
    scanf("%d %d", &a, &b);
    node *tmp = headNode;
    while(tmp != NULL)
    {
        if (tmp -> data == a) tmp -> data = b;
        tmp = tmp -> pNext;
    }
    printList(headNode);
    return 0;
}