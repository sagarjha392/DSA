#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void printStack(Node* ptr){
    while(ptr!=NULL){
        printf("Element: %d ", ptr->data);
        ptr = ptr->next;
    }
}

 bool isEmpty(Node* top){
    bool value = false;
    if(top==NULL){
        value=true;
    }
    return value;
 }


bool isfull(Node* top){
    Node* p =  (Node*)malloc(sizeof(Node));
    bool value=false;
    if(p==NULL){
        value=true;
    }
    return value;
}

Node* push(Node* top, int x){
    if(isfull(top)){
        printf("\nStack overflow\n");
    }else{
        Node* n = (Node*)malloc(sizeof(Node));
        n->data=x;
        n->next= top;
        top=n;
        return top;
    }
}
int pop (Node** top){
    int x;
    if(isEmpty(*top)){
        printf("\nStack underflow");
    }
    else{
        Node * n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;

    }
}

int peek(Node *top, int pos){
    Node *ptr = top;
    int i = 0;
    while (i<pos-1 && ptr !=NULL){
        ptr = ptr->next;
    }
    if(ptr !=NULL){
        return ptr->data;
    }else{
        return -1;
    }

}

int main(){
    Node * top =NULL;
    top = push(top,78);
    top = push(top,79);
    //   printf("\nPopped element: %d\n",pop(&top) );
      int pos = peek(top, 0);
      printf("\nelement at 0 is: %d\n",pos);
    printStack(top);
    return 0;
}