/*
Input a positive integer n, followed by n integers of a sequence, install it in a singly linked list.
Next enter an integer k (0 ≤ k < n).
Remove the elements whose value is greater than the value of the element at index k.
Print that list to the screen, followed by exactly one space.
-----------------------------------------------------------------------------------------------------
Test case:
|-----------------------------------------|
|    Input             |        Output    |
|-----------------------------------------|
|  4                   |                  |
|  1 2 3 1             |      1 1         |
|  3                   |                  |
|-----------------------------------------|
*/

#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
    int data;
    struct node *pNext;
} node;

node *createNode(int data)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode -> data = data;
    newNode -> pNext = NULL;
    return newNode;
}
node *addTailNode(int data, node* tailNode)
{
    node *newTail = createNode(data);
    tailNode -> pNext = newTail;
    return newTail;
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
node *deleteAtIndex(node *headNode, int index)
{
    node *p = headNode;
    for (int i = 0; i < index - 1; ++i)
    {
        p = p -> pNext;
    }
    node *tmp = p -> pNext;
    p -> pNext = p -> pNext -> pNext;
    free(tmp);
    return headNode;
}
int getValueAtIndex(node *headNode, int index)
{
    node *p = headNode;
    int i = 0;
    while (i != index)
    {
        p = p -> pNext;
        i++;
    }
    return p -> data;
}
int main()
{
    int n, index, target;
    node *headNode, *tailNode;
    scanf("%d", &n);
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
    scanf("%d", &index);
    target = getValueAtIndex(headNode, index);
    node *resultList, *resultTail;
    node *p = headNode;
    int isFirstNode = 1;
    for (int i = 0; i < n; ++i)
    {
        if (p -> data <= target)
        {
            if (isFirstNode == 1)
            {
                resultList = createNode(p -> data);
                resultTail = resultList;
                isFirstNode = 0;
            }
            else resultTail = addTailNode(p -> data, resultTail);
        }
        p = p -> pNext;
    }
    printList(resultList);
    return 0;
}