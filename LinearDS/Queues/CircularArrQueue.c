#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct queue *q){
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}

bool isEmpty(struct queue *q){
    bool isEmpty=false;
    if(q->r == q->f){
        isEmpty=true;
    }
    return isEmpty;
}
void enQueue(struct queue *q, int val)
{
    if (isfull(q))
    {
        printf("Queue overflow\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("Enqueued %d\n", val);
    }
}

int dequeue(struct queue *q)
{
    int val = -1;
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        val = q->arr[q->f];
    }
    return val;
}

int main()
{
    struct queue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enQueue(&q, 4);
    enQueue(&q, 5);
    enQueue(&q, 7);

    printf("DeQueueing %d\n", dequeue(&q));
    printf("DeQueueing %d\n", dequeue(&q));
    printf("DeQueueing %d\n", dequeue(&q));
    enQueue(&q, 11);
    printf("DeQueueing %d\n", dequeue(&q));
    enQueue(&q, 12);
    enQueue(&q, 13);
    printf("DeQueueing %d\n", dequeue(&q));
    // enQueue(&q, 2);
    // enQueue(&q, 5);
    // enQueue(&q, 5);
}
