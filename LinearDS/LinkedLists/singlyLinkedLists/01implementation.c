#include "stdio.h"
#include "stdlib.h"

// Adt of LinkedList
struct Node{
    int data;
    struct Node *next;    
};

void printList(struct Node *head){
    while (head != NULL)
    {
        printf("%d ", head->data);
        head=head->next;
    }

    printf("\n");
    
}


// Insertion in Linked List
struct Node * InsertAtHead(struct Node *head,int  data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;

    return ptr;
}


struct Node *InsertBetween(struct Node *head, int data, int index){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    int i =0;

    while(i!=index-1){
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next=p->next;
    p->next=ptr;

    return head;
}


struct Node *insertAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data; 
    struct Node *p = head;
    
    
    while(p->next != NULL){
        p=p->next;
    }

    p->next=ptr;
    ptr->next=NULL;

    return head;
}


struct Node * InsertAfter(struct Node *head, struct Node *prevNode, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next=prevNode->next;
    prevNode->next=ptr;

    return head;
}

// Deletion of a node
struct Node *deleteHead(struct Node *head){
    if(head==NULL){
        printf("Nothing to delete, head is empty\n");
    }
    else{
    struct Node *ptr =head;
    head=head->next;

    free(ptr);
    ptr=NULL;

    return head;
    }
}

struct Node *deleteBetween(struct Node *head, int idx){
    struct Node *p = head;
    struct Node *q = head->next;
    for(int i = 0; i <idx-1;i++){
        p= p->next;
        q= q->next;
    }

    p->next =q->next;
    free(q);
    q=NULL;
    return head;
}

struct Node *deleteEnd(struct Node *head){
    struct Node *p = head;
    struct Node *q = head->next;
     while(q->next != NULL){
        p=p->next;
        q=q->next;
    }

    p->next = q->next;
    free(q);
    q=NULL;
    return head;
}

struct Node *deleteValue(struct Node *head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data !=value && q->next !=NULL){
        p= p->next;
        q= q->next;
    }

    if(q->data ==value){
        p->next =q->next;
        free(q);
        q=NULL;
    }
    return head;
}

int main(){

    struct Node *head;
    struct Node *second;
    struct Node *third;
    head=(struct Node *)malloc(sizeof(struct Node));
    second= (struct Node *)malloc(sizeof(struct Node));
    third= (struct Node *)malloc(sizeof(struct Node));
    head->data=45;
    head->next=second;   
    

    second->data=25;
    second->next=third;

    third->data=5;
    third->next=NULL;

    printf("Original data in Linked list: ");
    printList(head);
    // InsertAtFirst(head,1);
    // head= InsertAtHead(head,0);
    // head = InsertBetween(head, 23, 2);
    // head=insertAtEnd(head, 2);

    // head =InsertAfter(head, head,12);

    // head = deleteHead(head);
    // head = deleteBetween(head,2);
    // head = deleteEnd(head);
    head = deleteValue(head, 15);


    printf("Data After Deleting : ");
    printList(head);
    return 0;
}