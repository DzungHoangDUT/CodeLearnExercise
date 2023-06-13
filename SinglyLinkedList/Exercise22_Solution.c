#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
    int data;
    struct node* pNext;
} node;

node* createNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode -> data = data;
    newNode -> pNext = NULL;
    return newNode;
}
node* addNode(int data, node* tailNode)
{
    node* newNode = createNode(data);
    tailNode -> pNext = newNode;
    newNode -> pNext = NULL;
    return newNode;
}
node* addHeadNode(int data, node* headNode)
{
    node* newHeadNode = createNode(data);
    newHeadNode -> pNext = headNode;
    return newHeadNode;
}
node* addTailNode(int data, node* tailNode)
{
    node* newTailNode = createNode(data);
    tailNode -> pNext = newTailNode;
    return newTailNode;
}
node* insertNode(int data, int index, node* headNode)
{
    node* newNode = createNode(data);
    node* tmp = headNode;
    for (int i = 0; i < index-1; ++i)
    {
        tmp = tmp -> pNext;
    }
    newNode -> pNext = tmp -> pNext;
    tmp -> pNext = newNode;
    return headNode;
}
void printList(node* headNode)
{
    node* p = headNode;
    while (p != NULL)
    {
        printf("%d ", p -> data);
        p = p ->pNext;
    }
}
int main()
{
    int n; scanf("%d", &n);
    node* headNode, *tailNode;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        scanf("%d", &temp);
        if (i == 0)
        {
            headNode = createNode(temp);
            tailNode = headNode;
        }
        else tailNode = addTailNode(temp, tailNode);
    }
    int index, value;
    scanf("%d %d", &index, &value);
    if (index == 0) headNode = addHeadNode(value, headNode);
    else if (index == n-1) tailNode = addTailNode(value, tailNode);
    else headNode = insertNode(value, index, headNode);
    printList(headNode);
    return 0;
}