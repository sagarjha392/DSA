#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

void printQueue(struct queue *q){
    printf("\n");
    for(int i = q->f+1; i <= q->r; i++){
        printf("%d ",q->arr[i]);
    }
}

bool isfull(struct queue *q){
    bool isfull=false;
    if(q->r == q->size-1){
        isfull=true;
    }

    return isfull;
}

bool isEmpty(struct queue *q){
    bool isEmpty=false;
    if(q->r == q->f){
        isEmpty=true;
    }
    return isEmpty;
}

void enqueue(struct queue *q, int val ){
    if(isfull(q)){
        printf("Queue overflow");
    }
    else{
        q->r = q->r+1;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q){

    int a =-1;
    if(isEmpty(q)){
        printf("Empty queue");
    }
    else{
        q->f++;
        a=q->arr[q->f];
    }

    return a;
}


int main(){
    struct queue q;

    q.size=3;
    q.f= q.r =-1;

    q.arr = (int *)malloc(q.size*sizeof(int));

    enqueue(&q, 2);
    enqueue(&q, 4);
    enqueue(&q, 6);


    printQueue(&q);
    printf("\n%d",dequeue(&q)); 
    printf("\n%d",dequeue(&q)); 
    printf("\n%d",dequeue(&q)); 
    enqueue(&q, 6);
    
    printQueue(&q);

}