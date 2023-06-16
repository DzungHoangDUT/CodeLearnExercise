// Nhập vào một số nguyên dương n, tiếp theo là n số nguyên của một dãy số, hãy cài đặt nó vào một danh sách liên kết đôi. Tiếp theo cho hai số nguyên k và x, (0 ≤ k ≤ n).
// Hãy chèn giá trị x vào danh sách liên kết tại chỉ số k và in ra màn hình danh sách đó, sau một phần tử có đúng một khoảng trắng.

// Ví dụ:

// Test mẫu 1:

// Input  |	Output
// 3      |  
// 1 2 3  |  10 1 2 3
// 0 10   |   
// Với l = [1, 2, 3] và k = 0, x = 10 thì kết quả là: "10 1 2 3 ".

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
    tailNode -> nextNode = newTail;
    newTail -> preNode = tailNode;
    return newTail;
}
void printList(node *headNode)
{
    node *p = headNode;
    while (p != NULL)
    {
        printf("%d ", p -> data);
        p = p -> nextNode;
    }
}
node *insertAtIndex(int data, int index, node *headNode)
{
    node *newNode = createNode(data);
    node *p = headNode;
    for (int i = 0; i < index; i++)
    {
        p = p -> nextNode;
    }
    p -> preNode -> nextNode = newNode;
    newNode -> preNode = p -> preNode;
    newNode -> nextNode = p;
    return headNode;
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
    int x, k;
    scanf("%d %d", &k, &x);
    if (k == 0) {
        printf("%d ", x);
        printList(headNode);
    }
    else if (k == n)
    {
        printList(headNode);
        printf("%d ", x);
    } else
    {
        headNode = insertAtIndex(x, k, headNode);
        printList(headNode);
    }
    return 0;
}