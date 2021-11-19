#include <time.h>
#include <malloc.h>
#include <windows.h>
#include <iostream>
using namespace std;

struct Node
{
    int items;
    Node* next;
};

typedef Node* PNode;

PNode* Head;

void InitializHead(int size)
{
    int i;
    Head = (PNode*)malloc(size * sizeof(PNode));
    for (i = 0; i < size; i++) Head[i] = NULL;
}

PNode CreateNode(int items)
{
    PNode NewNode = (Node*)malloc(sizeof(Node));
    NewNode->items = items;
    NewNode->next = NULL;
    return NewNode;
}

void AddFirst(PNode NewNode, int i)
{
    NewNode->next = Head[i];
    Head[i] = NewNode;
}

void AddAfter(PNode q, PNode NewNode)
{
    NewNode->next = q->next;
    q->next = NewNode;
}

void AddLast(PNode NewNode, int i)
{
    PNode q = Head[i];
    while (q->next) q = q->next;
    AddAfter(q, NewNode);
}

void print(int i)
{
    PNode q = Head[i];
    while (q)
    {
        printf("%d ", q->items);
        q = q->next;
    }
    printf("\n");
}

void road(int size, int** a, int* vis, int num, int* parent)
{
    vis[num] = 1;
    for (int i = 0; i < size; i++)
    {
        if (a[num][i] == 1 && vis[i] == 0)
        {
            parent[i] = num;
            printf("%d ", i);
            road(size, a, vis, i, parent);
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (vis[i] == 0)
        {
            num = parent[num];
            road(size, a, vis, num, parent);
        }
    }
}

void road2(int size, int* vis, int num, int* parent)
{
    vis[num] = 1;
    while (Head[num])
    {
        if (vis[Head[num]->items] == 0)
        {
            parent[Head[num]->items] = num;
            printf("%d ", Head[num]->items);
            road2(size, vis, Head[num]->items, parent);
        }
        Head[num] = Head[num]->next;
    }
    for (int i = 0; i < size; i++)
    {
        if (vis[i] == 0)
        {
            num = parent[num];
            road2(size, vis, num, parent);
        }
    }
}

int main()
{
    int size, i, j, ran, ** a, *vis, *parent, num = 0;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    PNode NewNode = NULL;
    printf("”кажите размер массива: ");
    scanf_s("%d", &size);
    a = (int**)malloc(size * sizeof(int));
    vis = (int*)malloc(size * sizeof(int));
    parent = (int*)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        a[i] = (int*)malloc(size * sizeof(int));
    }
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            a[i][j] = 0;
        }
    }
    for (i = 0; i < size; i++)
    {
        vis[i] = 0;
    }
    for (i = 0; i < size; i++)
    {
        for (j = 1 + i; j < size; j++)
        {
            a[i][j] = rand() % 2;
        }
    }
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            a[j][i] = a[i][j];
        }
    }

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("ќбход в глубину в матрице: 0 ");
    road(size, a, vis, num, parent);
    for (i = 0; i < size; i++)
    {
        vis[i] = 0;
    }
    num = 0;

    InitializHead(size);
    for (i = 0; i < size; i++)
    {
        NewNode = CreateNode(i);
        AddFirst(NewNode, i);
    }
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (a[i][j] == 1)
            {
                NewNode = CreateNode(j);
                AddLast(NewNode, i);
            }
        }
    }
    printf("\n\n");
    for (i = 0; i < size; i++)
    {
        print(i);
    }
    printf("ќбход в глубину в списке: 0 ");
    road2(size, vis, num, parent);
}