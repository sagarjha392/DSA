#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *f = NULL, *r = NULL;

void printList(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}
void enQueue(int value)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL)
        printf("Queue is full\n");
    else
    {
        n->data = value;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;

            r = n;
        }
    }
}


int dequeue(){
    int val =-1;
    Node *n = f;

    if(f==NULL){
        printf("Queue is empty");
    }else{
        f= f->next;
        val= n->data;
        free(n);
    }

    return val;
}

int main()
{
    printf("\nDequeuing: %d\n", dequeue());

    enQueue(4);
    enQueue(8);
    enQueue(18);

    printList(f);

    printf("\nDequeuing: %d\n", dequeue());
    printList(f);
    return 0;
}