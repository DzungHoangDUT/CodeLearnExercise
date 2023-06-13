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
node *deleteHeadNode(node* headNode)
{
    node *newHeadNode = headNode -> pNext;
    free(headNode);
    return newHeadNode;
}
node *deleteTailNode(node *headNode)
{
    node *p = headNode;
    while (p -> pNext -> pNext != NULL)
    {
        p = p -> pNext;
    }
    free(p -> pNext);
    p -> pNext = NULL;
    return p;
}
node *deleteNode(node* headNode, int index)
{
    node* tmp = headNode;
    for (int i = 0; i < index-1; ++i) {
        tmp = tmp -> pNext;
    }
    node* p = tmp -> pNext;
    tmp -> pNext = tmp -> pNext -> pNext;
    free(p);
    return headNode;

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
    int index;
    scanf("%d", &index);
    if (index == 0) headNode = deleteHeadNode(headNode);
    else if (index == n-1) tailNode = deleteTailNode(headNode);
    else headNode = deleteNode(headNode, index);
    printList(headNode);
    return 0;
}