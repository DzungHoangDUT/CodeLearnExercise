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
node *addTail(int data, node *headNode)
{
    node* newTail = createNode(data);
    headNode -> pNext = newTail;
    return newTail;
}
int getValue(int index, node *headNode)
{
    node *p = headNode;
    for (int i = 0; i < index; ++i)
    {
        p = p -> pNext;
    }
    return p -> data;
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
        else tailNode = addTail(tmp, tailNode);
    }
    int index;
    scanf("%d", &index);
    printf("%d", getValue(index, headNode));
}