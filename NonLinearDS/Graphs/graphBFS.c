#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

void printQueue(struct queue *q)
{
    printf("\n");
    for (int i = q->f + 1; i <= q->r; i++)
    {
        printf("%d ", q->arr[i]);
    }
}

bool isfull(struct queue *q)
{
    bool isfull = false;
    if (q->r == q->size - 1)
    {
        isfull = true;
    }

    return isfull;
}

bool isEmpty(struct queue *q)
{
    bool isEmpty = false;
    if (q->r == q->f)
    {
        isEmpty = true;
    }
    return isEmpty;
}

void enqueue(struct queue *q, int val)
{
    if (isfull(q))
    {
        printf("Queue overflow");
    }
    else
    {
        q->r = q->r + 1;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{

    int a = -1;
    if (isEmpty(q))
    {
        printf("Empty queue");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }

    return a;
}

int main()
{
    struct queue q;

    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    int u;
    int i = 0;
    int visited[] = {0, 0, 0, 0, 0, 0, 0};

    int graph[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i); // enqueue i for exploration
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (graph[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    return 0;
}
