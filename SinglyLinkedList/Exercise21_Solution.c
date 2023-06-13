#include "stdio.h"
#include "stdlib.h"

typedef struct node {
    int data;
    struct node* pNext;
} node;
node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode -> data = data;
    newNode -> pNext = NULL;
    return newNode;
}
node* insertLastNode(int data, node* tailNode){
    node* newNode = createNode(data);
    tailNode -> pNext = newNode;
    return newNode;
}
void printList(node* headNode) {
    node* p = headNode;
    while (p != NULL)
    {
        printf("%d ", p -> data);
        p = p -> pNext;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    
    int firstElement;
    scanf("%d", &firstElement);

    node* headNode = createNode(firstElement);
    node* tailNode = headNode;
    for (int i = 1; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        tailNode = insertLastNode(tmp, tailNode);
    }
    printList(headNode);
    return 0;
}